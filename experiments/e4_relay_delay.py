"""E4 -- 数据面附加时延：中继到底给每包加了多少时间。

不需要开游戏。用两个假端点就把数据面测出来：

    fake host  --@reg 心跳-->  中继 app
               <--@os/端口--

    fake peer  --payload-->  中继 listen_socket
                             +--> 转发 `<id>/payload` 给 host 的 owner_socket
    fake host  <--           原样回显
                             +--> 转发回 peer
    fake peer  <--payload--  记 RTT

一次探测经过 4 段单程链路：

    peer -> 中继 -> host -> 中继 -> peer
      D       D       D       D

host 和 peer 跑在同一台机器上，所以两段 D 相同，合计 4D = 2 × 链路 RTT。
于是：

    RTT_中继 ≈ 2 × RTT_链路
    中继处理开销 = RTT_中继 − 2 × RTT_链路

链路 RTT 由脚本自己测（TCP 连接到 msg 端口，一次握手 = 1 个 RTT），
也可以用 --icmp-rtt 手动指定 ping 的结果。

用法:

    python e4_relay_delay.py --relay <中继IP>

可选:
    --count 1000      探测包数（默认 1000）
    --pps 50          发送速率（默认 50 包/秒，避免自己造成排队）
    --icmp-rtt 40     手动指定链路 RTT（ms）；不指定则用 TCP 握手自测
"""
import argparse
import socket
import struct
import time

import frp

APP_PORT = 2233

UDP_HELP = """
发 @id 之后没收到任何应答。这不是脚本的问题 —— UDP 的 app 端口不通。

依次排除（30 秒能定位）:

  1) 用这条命令单独验证 UDP 通不通（把 IP 换成你的中继）:

     python -c "import socket;s=socket.socket(2,2);s.settimeout(3);s.sendto(b'@id',('{relay}',{port}));print(s.recvfrom(200))"

     - 打印 (b'@id/1234', (...))  => UDP 是通的，那就回来重跑本脚本
     - 超时 / TimeoutError          => 继续往下看

  2) 中继是否在跑，且控制台打印了 "<app> run at port [{port}]"？
     （注意 app 是 UDP，msg 是 TCP，两者默认端口号相同但协议不同）

  3) --app-port 和服务端 gdefine.h 里的 APP_PORT 一致吗？

  4) 云安全组是否对 **UDP**（不只是 TCP）放通了 {port}？
     你的配置是 1000-5000 UDP+TCP，检查是否只对某一个协议生效。

  5) 本机是否开着 VPN？部分 VPN 客户端会丢弃非 443 的 UDP。

  6) 在 VPS 上本地自测（排除云端防火墙）:
     python -c "import socket;s=socket.socket(2,2);s.settimeout(3);s.sendto(b'@id',('127.0.0.1',{port}));print(s.recvfrom(200))"
"""


class FakeHost:
    """假 host：发 @id / @reg / @imowner，并把中继转来的包原样回显。"""

    def __init__(self, relay, app_port):
        self.relay = relay
        self.app_port = app_port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(("0.0.0.0", 0))
        self.id = None
        self.owner_port = None
        self.next_reg = 0.0

    def close(self):
        try:
            self.sock.close()
        except OSError:
            pass

    def _reg_payload(self):
        # @reg/<id>/<password>/<property>，密码留空 -> 4 个字段
        return "@reg/{}//echo".format(self.id).encode()

    def handshake(self, timeout=5.0):
        """拿 id、注册、记下 owner 端口、发 @imowner。

        注意：中继在**创建** session 的那一次 @reg 不回复 @os
        （app::do_reg 的新建分支直接 return），只有会话已存在时才回。
        所以这里必须重发 @reg 直到收到 @os，最多 6 次。
        """
        self.sock.settimeout(timeout)

        self.sock.sendto(b"@id", (self.relay, self.app_port))
        while True:
            try:
                data, _ = self.sock.recvfrom(4096)
            except socket.timeout:
                raise SystemExit(UDP_HELP.format(relay=self.relay, port=self.app_port))
            if data.startswith(b"@id/"):
                self.id = data.split(b"/")[1].decode()
                break

        self.sock.settimeout(1.2)
        for _ in range(6):
            self.sock.sendto(self._reg_payload(), (self.relay, self.app_port))
            got = None
            while True:
                try:
                    data, _ = self.sock.recvfrom(4096)
                except socket.timeout:
                    break
                if data.startswith(b"@os/"):
                    got = int(data.split(b"/")[1])
                    break
            if got is not None:
                self.owner_port = got
                break
        if self.owner_port is None:
            raise SystemExit(
                "发了 6 次 @reg 仍没收到 @os/<port>。\n"
                "  中继控制台应该每个 id 打印一行 'session [x] run : [os:...]'。\n"
                "  如果连 session 都没创建，看 UDP_HELP 的排查清单。"
            )

        # 让中继记住 host 的外部地址
        self.sock.sendto(b"@imowner", (self.relay, self.owner_port))
        self.next_reg = time.perf_counter() + 1.0

    def send_reg(self):
        """只发心跳，不读——避免在主循环里阻塞。"""
        self.sock.sendto(self._reg_payload(), (self.relay, self.app_port))
        self.next_reg = time.perf_counter() + 1.0

    def echo_pending(self):
        """把中继转来的 `<id>/payload` 原样送回 owner 端口。"""
        while True:
            try:
                data = self.sock.recv(4096)
            except (BlockingIOError, socket.timeout):
                return
            except OSError:
                return
            if data[:1].isdigit() and b"/" in data[:12]:
                self.sock.sendto(data, (self.relay, self.owner_port))


def measure_path_rtt(relay, msg_port, n=20):
    """TCP 握手耗时 = 1 个链路 RTT。"""
    samples = []
    for _ in range(n):
        t0 = time.perf_counter()
        s = socket.create_connection((relay, msg_port), timeout=5)
        s.close()
        samples.append((time.perf_counter() - t0) * 1000.0)
    samples.sort()
    return samples[len(samples) // 2]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--relay", required=True)
    ap.add_argument("--app-port", type=int, default=APP_PORT, help="UDP 的 app 端口")
    ap.add_argument("--msg-port", type=int, default=frp.DEFAULT_PORT, help="TCP 的 msg 端口")
    ap.add_argument("--count", type=int, default=1000)
    ap.add_argument("--pps", type=float, default=50.0)
    ap.add_argument("--icmp-rtt", type=float, default=None,
                    help="ping 得到的链路 RTT（ms）；不填则用 TCP 握手自测")
    ap.add_argument("--out", default="e4_relay_rtt.csv")
    args = ap.parse_args()

    print("== 1/4 建会话 ==")
    host = FakeHost(args.relay, args.app_port)
    host.handshake()
    print("   id = {}, owner 端口 = {}".format(host.id, host.owner_port))

    print("== 2/4 解析 listen 端口 ==")
    body, _ = frp.tcp_request(args.relay, "@ask_addr/{}/".format(host.id).encode(), args.msg_port)
    text = body.split(b"\x00")[0].decode("utf-8", "replace")
    if not text.startswith("@addr/") or text.endswith("error"):
        host.close()
        raise SystemExit("解析失败: {!r}".format(text))
    listen_port = int(text.split("/")[1])
    print("   listen 端口 = {}".format(listen_port))

    host.sock.setblocking(False)
    host.sock.settimeout(0.0)

    print("== 3/4 测链路基线 ==")
    if args.icmp_rtt is not None:
        path_rtt = args.icmp_rtt
        print("   用你给的 ping RTT: {:.1f} ms".format(path_rtt))
    else:
        path_rtt = measure_path_rtt(args.relay, args.msg_port)
        print("   TCP 握手自测: {:.1f} ms（≈ 1 个链路 RTT）".format(path_rtt))
    expected = 2.0 * path_rtt
    print("   4 段单程预期: {:.1f} ms（= 2 × 链路 RTT）".format(expected))

    print("== 4/4 发 {} 个探测包 @ {:.0f} pps ==".format(args.count, args.pps))
    peer = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    peer.bind(("0.0.0.0", 0))
    peer.setblocking(False)

    rtts = []
    seq = 0
    interval = 1.0 / args.pps
    next_send = time.perf_counter()
    csv = open(args.out, "w", encoding="utf-8")
    csv.write("seq,rtt_ms\n")

    def drain_peer():
        while True:
            try:
                data = peer.recv(4096)
            except (BlockingIOError, socket.timeout):
                return
            except OSError:
                return
            if len(data) >= 8:
                t0 = struct.unpack("<d", data[:8])[0]
                rtt = (time.perf_counter() - t0) * 1000.0
                rtts.append(rtt)
                csv.write("{},{:.3f}\n".format(len(rtts), rtt))

    while seq < args.count:
        now = time.perf_counter()

        if now >= host.next_reg:
            host.send_reg()

        if now >= next_send:
            payload = struct.pack("<d", time.perf_counter()) + b"x" * 32
            peer.sendto(payload, (args.relay, listen_port))
            seq += 1
            next_send = now + interval

        host.echo_pending()
        drain_peer()

    # 收尾：再收 1.5 秒，把在途的回显收干净
    tail = time.perf_counter() + 1.5
    while time.perf_counter() < tail:
        if time.perf_counter() >= host.next_reg:
            host.send_reg()
        host.echo_pending()
        drain_peer()
        time.sleep(0.002)

    csv.close()
    host.close()
    peer.close()

    if not rtts:
        raise SystemExit(
            "一个回显都没收到。检查：listen 端口是否放通、--app-port 是否是 UDP 端口"
        )

    s = frp.summarize(rtts)
    residual = s["median"] - expected

    print("\n== 结果 ==")
    print("   样本数        {}".format(s["n"]))
    print("   RTT 中位数    {:.1f} ms".format(s["median"]))
    print("   RTT p95       {:.1f} ms".format(s["p95"]))
    print("   RTT 最大      {:.1f} ms".format(s["max"]))
    print("   链路 RTT      {:.1f} ms".format(path_rtt))
    print("   预期(=2RTT)   {:.1f} ms".format(expected))
    print("   中继开销      {:+.1f} ms".format(residual))

    print("\n== 论文要填的 ==\n")
    print("   数据面 RTT 中位: {:.1f} ms   (n={})".format(s["median"], s["n"]))
    print("   中继处理开销   : {:+.1f} ms".format(residual))

    print("\n== 判读 ==")
    if abs(residual) <= max(3.0, 0.15 * expected):
        print("   OK: 中继开销在噪声内。可写：中继不引入可测的处理延迟，")
        print("       代价就是多一跳的传播时延。")
    elif residual < 0 and s["median"] < 0.6 * expected:
        print("   测出来的 RTT 比 2 倍链路 RTT **还小**，这在物理上不可能。")
        print("   说明链路 RTT 基线给高了（--icmp-rtt 或 TCP 握手都不准）。")
        print("   反推：链路 RTT ≈ {:.1f} ms（= RTT/{:.0f}）".format(
            s["median"] / 2.0, 2))
        print("   请用真实的 ping 结果核对：")
        print("       ping -n 6 {}".format(args.relay))
    elif residual > 0:
        print("   比预期慢 {:.0f} ms。可能：".format(residual))
        print("     - 中继被忙轮询线程占满（回到 E6）")
        print("     - 发送速率过高造成排队，试 --pps 20")
    else:
        print("   比预期略快，把这三个数发我再判断。")


if __name__ == "__main__":
    main()
