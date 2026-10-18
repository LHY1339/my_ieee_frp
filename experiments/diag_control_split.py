"""诊断 -- 控制面 93 ms 到底花在哪一段。

把一次 @get_list 拆成四个时刻：

    t0 开始 connect
    t1 connect 返回              -> (t1-t0) = TCP 握手 = 1 个链路 RTT
    t2 请求发出
    t3 收到 4 字节长度头          -> (t3-t2) = 请求到中继 + 中继发出长度头
    t4 正文收完                  -> (t4-t3) = 中继发正文的那一段

如果 (t4-t3) 是几十毫秒而 (t3-t2) 只有个位数，就说明是
msg::send_with_head 里**两次独立 send()** 触发了 Nagle + 延迟 ACK：
长度头先走，正文被压住等 ACK。

用法:
    python diag_control_split.py --relay 111.228.32.155
"""
import argparse
import socket
import statistics
import struct
import time

import frp

N = 20


def one(relay, port):
    r = {}
    t0 = time.perf_counter()
    s = socket.create_connection((relay, port), timeout=5)
    t1 = time.perf_counter()
    s.sendall(b"@get_list")
    t2 = time.perf_counter()

    hdr = b""
    while len(hdr) < 4:
        c = s.recv(4 - len(hdr))
        if not c:
            raise ConnectionError("closed")
        hdr += c
    t3 = time.perf_counter()

    n = struct.unpack("<I", hdr)[0]
    body = b""
    while len(body) < n:
        c = s.recv(n - len(body))
        if not c:
            raise ConnectionError("closed")
        body += c
    t4 = time.perf_counter()
    s.close()

    r["connect"] = (t1 - t0) * 1000
    r["to_header"] = (t3 - t2) * 1000
    r["header_to_body"] = (t4 - t3) * 1000
    r["total"] = (t4 - t0) * 1000
    r["body_len"] = n
    return r


def udp_rtt(relay, app_port, n=20):
    """纯 UDP 的 @id 往返 = 链路 RTT，没有任何 TCP 干扰。

    这个数是"基准"，用来判断 connect/数据面哪个可信。
    """
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.settimeout(3)
    vals = []
    for _ in range(n):
        t0 = time.perf_counter()
        s.sendto(b"@id", (relay, app_port))
        try:
            s.recvfrom(256)
        except socket.timeout:
            break
        vals.append((time.perf_counter() - t0) * 1000.0)
        time.sleep(0.05)
    s.close()
    return vals


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--relay", required=True)
    ap.add_argument("--port", type=int, default=frp.DEFAULT_PORT)
    ap.add_argument("--app-port", type=int, default=2233, help="UDP 的 app 端口")
    ap.add_argument("--n", type=int, default=N)
    args = ap.parse_args()

    rows = []
    for i in range(args.n):
        try:
            rows.append(one(args.relay, args.port))
        except Exception as exc:                       # noqa: BLE001
            print("  ! 第 {} 次失败: {}".format(i + 1, exc))
        time.sleep(0.1)

    if not rows:
        raise SystemExit("全部失败")

    keys = ["connect", "to_header", "header_to_body", "total"]
    print("\n== {} 次采样的中位数（ms） ==".format(len(rows)))
    for k in keys:
        vals = sorted(r[k] for r in rows)
        med = statistics.median(vals)
        print("   {:<18}{:8.1f}   (min {:.1f} / max {:.1f})".format(k, med, vals[0], vals[-1]))

    print("\n   正文长度           {} 字节".format(rows[0]["body_len"]))

    med = {k: statistics.median([r[k] for r in rows]) for k in keys}

    print("\n== 对照：纯 UDP 的 @id 往返（= 链路 RTT，无 TCP 干扰）==")
    u = sorted(udp_rtt(args.relay, args.app_port))
    if u:
        path = statistics.median(u)
        print("   n={}  中位 {:.1f} ms   (min {:.1f} / max {:.1f})".format(
            len(u), path, u[0], u[-1]))
    else:
        path = None
        print("   一条都没回来 —— UDP app 端口不通？")

    print("\n== 判读 ==")
    gap = med["header_to_body"]
    hop = med["to_header"]
    print("   链路 RTT（UDP 实测）       {:.1f} ms".format(path) if path else "   链路 RTT 未知")
    print("   TCP connect               {:.1f} ms".format(med["connect"]))
    print("   请求→长度头               {:.1f} ms".format(hop))
    print("   长度头→正文（关键）       {:.1f} ms".format(gap))

    if path and med["connect"] > 1.6 * path:
        print("\n   ! TCP connect({:.1f}) 明显大于 UDP 链路 RTT({:.1f})，".format(
            med["connect"], path))
        print("     说明这条链路上 TCP 握手本身就被拖慢了（中间盒 / 跨网策略），")
        print("     论文里不能用 connect 当链路基准，要用 UDP 的 {:.1f} ms。".format(path))

    if gap > 20 and gap > 2 * max(1.0, hop):
        print("\n   >> 命中 Nagle：正文比长度头晚 {:.0f} ms 才到。".format(gap))
        print("      send_with_head 里两次 send()，第二段被 Nagle 扣住等 ACK。")
        print("      修法：长度头和正文拼成一个缓冲区、一次 send()；")
        print("            或对 accept 出来的 socket 设 TCP_NODELAY。")
        print("\n   论文可以写：控制面时延由一次可修的 TCP 写模式缺陷主导，")
        print("   而不是链路或服务端处理能力。")
    elif gap < 10:
        print("\n   >> 不是 Nagle。几十毫秒在别处（服务端调度 / 链路）。把输出发我。")
    else:
        print("\n   >> 介于两者之间，把输出发我。")


if __name__ == "__main__":
    main()
