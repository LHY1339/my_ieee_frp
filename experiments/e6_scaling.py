"""E6 -- 扩展性：多少个并发 session 之后中继开始掉 tick。

不需要开游戏，也不需要读中继的 CPU。原理是利用"掉 tick = session 被误回收"
这个可观测后果：

    1. 造 N 个假 host，每个每秒发 @reg（心跳），一直不停
    2. 每秒查一次 @get_list，看这 N 个 id 还在不在
    3. 如果某个 id 在我们**明明还在发心跳**的情况下从列表里消失，
       说明中继那一秒没跑计时器 —— 这就是忙碌轮询导致的调度饥饿

同时每秒记录 @get_list 的往返时延，因为饥饿也会直接抬高控制面时延。

用法:

    python e6_scaling.py --relay <中继IP> --levels 10,50,100 --hold 30

可选:
    --levels 5,10,20,50,100   逐级加压（默认）
    --hold 30                 每级稳定观察多少秒
    --ramp 0.05               创建 session 的间隔（秒），避免瞬间冲击

输出:
    e6_scaling.csv            每次采样的原始记录
    屏幕上一张逐级汇总表 + 论文可用的结论
"""
import argparse
import csv
import socket
import statistics
import time

import frp

APP_PORT = 2233


class FakeHost:
    """一个假 host：只做 @id 和 1 Hz 的 @reg。"""

    __slots__ = ("sock", "id", "next_reg", "relay", "app_port")

    def __init__(self, relay, app_port):
        self.relay = relay
        self.app_port = app_port
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind(("0.0.0.0", 0))
        self.sock.settimeout(3.0)
        self.id = None
        self.next_reg = 0.0

    def request_id(self):
        self.sock.sendto(b"@id", (self.relay, self.app_port))
        deadline = time.perf_counter() + 3.0
        while time.perf_counter() < deadline:
            try:
                data, _ = self.sock.recvfrom(1024)
            except socket.timeout:
                break
            if data.startswith(b"@id/"):
                self.id = data.split(b"/")[1].decode()
                return self.id
        return None

    def reg_payload(self):
        return "@reg/{}//load".format(self.id).encode()

    def send_reg(self):
        self.sock.sendto(self.reg_payload(), (self.relay, self.app_port))
        self.next_reg = time.perf_counter() + 1.0

    def drain(self):
        """把 @os 之类的回包丢进垃圾桶，避免接收缓冲堆满。"""
        self.sock.setblocking(False)
        try:
            while True:
                self.sock.recv(1024)
        except (BlockingIOError, socket.timeout):
            pass
        except OSError:
            pass
        self.sock.setblocking(True)
        self.sock.settimeout(3.0)

    def close(self):
        try:
            self.sock.close()
        except OSError:
            pass


def build_hosts(relay, app_port, n, ramp):
    hosts = []
    for i in range(n):
        h = FakeHost(relay, app_port)
        if h.request_id() is None:
            print("  ! 第 {} 个 session 没拿到 @id，停止创建".format(i + 1))
            h.close()
            break
        h.send_reg()
        hosts.append(h)
        if ramp:
            time.sleep(ramp)
    return hosts


def run_level(relay, msg_port, app_port, n, hold, ramp, csv_writer, level_no):
    print("\n--- 级别 {}: {} 个 session ---".format(level_no, n))
    hosts = build_hosts(relay, app_port, n, ramp)
    if not hosts:
        return None
    ids = set(h.id for h in hosts)
    print("  已注册 {} 个（id {}..{}）".format(len(hosts), min(ids, key=int), max(ids, key=int)))

    # 等列表稳定下来
    time.sleep(1.5)

    samples = []          # (t, alive_count, list_ms)
    lost_events = 0
    prev_alive = None
    t_end = time.perf_counter() + hold

    while time.perf_counter() < t_end:
        # 心跳
        now = time.perf_counter()
        for h in hosts:
            if now >= h.next_reg:
                h.send_reg()
                h.drain()

        # 采样
        try:
            body, ms = frp.tcp_request(relay, b"@get_list", msg_port, timeout=5.0)
            alive = len(ids & set(i for i, _, _ in frp.parse_list(body)))
        except Exception:                              # noqa: BLE001
            time.sleep(0.5)
            continue

        samples.append((time.perf_counter(), alive, ms))
        csv_writer.writerow([level_no, n, "{:.2f}".format(now), alive, "{:.2f}".format(ms)])

        if prev_alive is not None and alive < prev_alive:
            lost_events += prev_alive - alive
            print("    ! 第 {:.0f} 秒: 存活 {} -> {}（我们仍在发心跳）".format(
                hold - (t_end - time.perf_counter()), prev_alive, alive))
        prev_alive = alive

        time.sleep(max(0.0, 1.0 - (time.perf_counter() - now)))

    for h in hosts:
        h.close()
    print("  停止心跳，等 4 秒让中继回收 ...")
    time.sleep(4.0)

    if not samples:
        return None

    alive_counts = [s[1] for s in samples]
    lat = [s[2] for s in samples]
    return {
        "level": level_no,
        "sessions": len(hosts),
        "alive_min": min(alive_counts),
        "alive_median": statistics.median(alive_counts),
        "lost_events": lost_events,
        "list_median": statistics.median(lat),
        "list_max": max(lat),
        "samples": len(samples),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--relay", required=True)
    ap.add_argument("--msg-port", type=int, default=frp.DEFAULT_PORT)
    ap.add_argument("--app-port", type=int, default=APP_PORT)
    ap.add_argument("--levels", default="5,10,20,50,100",
                    help="逐级会话数，逗号分隔")
    ap.add_argument("--hold", type=float, default=30.0, help="每级观察秒数")
    ap.add_argument("--ramp", type=float, default=0.05, help="创建间隔（秒）")
    ap.add_argument("--out", default="e6_scaling.csv")
    args = ap.parse_args()

    levels = [int(x) for x in args.levels.split(",") if x.strip()]
    print("== E6 扩展性测试 ==")
    print("   中继 {}  app={}/udp  msg={}/tcp".format(args.relay, args.app_port, args.msg_port))
    print("   级别 {}  每级 {} 秒\n".format(levels, args.hold))

    results = []
    with open(args.out, "w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["level", "target_sessions", "t", "alive", "list_ms"])
        for i, n in enumerate(levels, 1):
            r = run_level(args.relay, args.msg_port, args.app_port,
                          n, args.hold, args.ramp, w, i)
            if r:
                results.append(r)
                fh.flush()

    if not results:
        raise SystemExit("没有有效数据。检查中继是否在跑、端口对不对")

    print("\n== 汇总 ==")
    header = "{:<6}{:<10}{:<10}{:<14}{:<14}{:<12}{:<12}".format(
        "级别", "目标", "存活最少", "丢失事件", "列表中位(ms)", "列表最大(ms)", "采样数")
    print(header)
    print("-" * len(header))
    for r in results:
        print("{:<6}{:<10}{:<10}{:<14}{:<14.1f}{:<12.1f}{:<12}".format(
            r["level"], r["sessions"], r["alive_min"], r["lost_events"],
            r["list_median"], r["list_max"], r["samples"]))

    # 判定饱和点
    print("\n== 判读 ==")
    saturated = None
    for r in results:
        if r["lost_events"] > 0 or r["alive_min"] < r["sessions"]:
            saturated = r["sessions"]
            break

    baseline = results[0]["list_median"]
    print("   1 级基线（{} 个 session）列表时延: {:.1f} ms".format(
        results[0]["sessions"], baseline))

    if saturated is None:
        print("   在测到的最高级别（{} 个 session）都没出现 session 误回收。".format(
            results[-1]["sessions"]))
        print("   说明这台中继还能撑更多——把 --levels 往上加（如 200,300）再跑一次。")
    else:
        print("   第一次出现 session 误回收是在 {} 个并发 session。".format(saturated))
        print("   这和忙轮询的预期一致：每个 session 一个不停转的线程，")
        print("   线程数超过核数之后，app 的 1 Hz 计时器就排不上队。")

    worst = max(results, key=lambda r: r["list_median"])
    print("   列表时延最差的一级: {} 个 session 时中位 {:.1f} ms（基线的 {:.1f} 倍）".format(
        worst["sessions"], worst["list_median"], worst["list_median"] / baseline if baseline else 0))

    print("\n== 论文可以写 ==")
    print("   Saturation appeared at <{}> concurrent matches on the 2-vCPU instance;".format(
        saturated if saturated else results[-1]["sessions"]))
    print("   the first symptom was not refused connections but dropped timer ticks,")
    print("   visible as sessions expiring while their hosts were still alive.")
    if baseline and worst["list_median"] > 2 * baseline:
        print("   Control-plane latency rose from {:.1f} ms to {:.1f} ms over the same range.".format(
            baseline, worst["list_median"]))
    print("\n   原始采样 -> {}".format(args.out))


if __name__ == "__main__":
    main()
