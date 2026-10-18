"""E2 -- host 崩溃后，session 从中继列表消失需要多久。

这一步验证论文第 IV-E 节推导的界。推导：

    每次 @reg 把计数器置为 SESSION_DESTROY_TIME(=3)，之后每 tick 减 1，
    减到 0 销毁。而 @reg 和 tick 都是 1 Hz，所以 host 崩溃那一刻计数器
    通常已经被减过一次、值为 2。

        崩溃时计数器 = 2  ->  需要 2 次递减  ->  约 1~2 s
        崩溃时计数器 = 3  ->  需要 3 次递减  ->  约 2~3 s

    因此上界是 3 s（不是 4 s：量化误差不加一秒，因为减到 0 的那一 tick
    当场就销毁），典型值约 2 s。

用法:

    python e2_staleness.py --relay <中继IP> --trials 30

可选:
    --image UE4Editor.exe    要杀的进程名（打包后换成你的 exe 名）
    --session 1              手动锁定 id（一般不指定，自动探测更可靠）
    --delay-min 3 --delay-max 15   每次 kill 前的随机等待，避免周期性偏差
    --poll 0.1               轮询间隔（秒），也是本实验的时间分辨率

关于 session id（重要）:
    每次重启 host，插件都会向中继发 @id 重新申请一个号，中继的计数器
    单调递增。所以**每次重启都是一个新的 session id**。脚本因此在每一轮
    开始时重新探测"新出现的那个 id"，而不是死盯第一次拿到的号。

流程（每一轮）:
    1. 脚本等你把 host 重新开起来
    2. 用「本轮开始前的 id 集合」做差集，找出新出现的 session
    3. 随机等 3~15 秒
    4. 脚本自己 taskkill /F，记录精确的 kill 时刻
    5. 每 0.1 秒查一次列表，直到连续 3 次查不到
    6. 记录「从 kill 到消失」的秒数，写进 CSV

脚本自己执行 kill 而不是你手按，是为了避免人的反应时间（约 0.3 s）
污染测量。这个误差在 1~3 秒的量级上是显著的。
"""
import argparse
import csv
import random
import statistics
import subprocess
import time

import frp

# 与 gdefine.h 里的 SESSION_DESTROY_TIME 保持一致
SESSION_DESTROY_TIME = 3.0
TICK_PERIOD = 1.0
# 期望区间：下界取 0.5 s（计数器可能因相位漂移已降到 1），上界是真实上界 3 s
LOW_EXPECTED = 0.5
HIGH_EXPECTED = SESSION_DESTROY_TIME


def poll_ids(relay, port, retries=2):
    """查一次列表，容忍偶发失败。"""
    for attempt in range(retries + 1):
        try:
            return frp.list_ids(relay, port)
        except Exception as exc:                      # noqa: BLE001
            if attempt == retries:
                print("  ! 轮询失败: {}".format(exc))
                return None
            time.sleep(0.05)
    return None


def detect_new_session(relay, port, baseline, timeout):
    """等到列表里出现一个不在 baseline 里的 session，返回它的 id。

    id 是单调递增的整数，所以有多个新 id 时取最大的那个。
    """
    deadline = time.perf_counter() + timeout
    while time.perf_counter() < deadline:
        ids = poll_ids(relay, port)
        if ids:
            fresh = [i for i in ids if i not in baseline]
            if fresh:
                def as_int(s):
                    return int(s) if s.lstrip("-").isdigit() else -1
                return max(fresh, key=as_int)
        time.sleep(0.2)
    return None


def wait_for_gone(relay, port, session, timeout, poll, need_misses=3):
    """等到 session 连续 need_misses 次查不到。

    返回 (ok, t_first_miss, t_last_seen)。消失时刻的真值落在
    [t_last_seen, t_first_miss] 之间，取中点作为估计、半宽作为不确定度，
    这样就不需要任何拍脑袋的修正项。
    """
    deadline = time.perf_counter() + timeout
    misses = 0
    t_last_seen = None
    t_first_miss = None
    while time.perf_counter() < deadline:
        ids = poll_ids(relay, port)
        now = time.perf_counter()
        if ids is None:
            time.sleep(poll)
            continue
        if session in ids:
            misses = 0
            t_last_seen = now
            t_first_miss = None
        else:
            if misses == 0:
                t_first_miss = now
            misses += 1
            if misses >= need_misses:
                return True, t_first_miss, t_last_seen
        time.sleep(poll)
    return False, None, None


def kill_host(image, timeout=10):
    """强杀 host 进程，返回 (t_before, t_after)。"""
    t_before = time.perf_counter()
    try:
        subprocess.run(
            ["taskkill", "/F", "/IM", image],
            capture_output=True,
            timeout=timeout,
        )
    except FileNotFoundError:
        raise SystemExit("找不到 taskkill，请在 Windows 上运行")
    except subprocess.TimeoutExpired:
        print("  ! taskkill 超时，这一轮作废")
        return None, None
    t_after = time.perf_counter()
    return t_before, t_after


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--relay", required=True)
    ap.add_argument("--port", type=int, default=frp.DEFAULT_PORT)
    ap.add_argument("--trials", type=int, default=30)
    ap.add_argument("--session", default=None, help="手动锁定 id；一般不用指定")
    ap.add_argument("--image", default="UE4Editor.exe", help="host 进程名，默认 UE4Editor.exe")
    ap.add_argument("--delay-min", type=float, default=3.0)
    ap.add_argument("--delay-max", type=float, default=15.0)
    ap.add_argument("--poll", type=float, default=0.1)
    ap.add_argument("--timeout", type=float, default=30.0, help="等消失的上限，超过记为未解析")
    ap.add_argument("--out", default="e2_staleness.csv")
    args = ap.parse_args()

    print("== 执行: taskkill /F /IM {} ==".format(args.image))
    print("   共 {} 轮，轮间需要你手动重开 host。".format(args.trials))
    print("   每轮会自动探测新出现的 session id（重启后 id 会变）。\n")

    rows = []
    with open(args.out, "w", newline="", encoding="utf-8") as fh:
        writer = csv.writer(fh)
        writer.writerow(
            ["trial", "session", "kill_t_before", "kill_t_after",
             "disappeared_s", "resolved", "note"]
        )

        for trial in range(1, args.trials + 1):
            # 本轮开始前，列表里已经存在的 id（通常为空；有残留也不要紧）
            baseline = set(poll_ids(args.relay, args.port) or [])

            input("[{:>2}/{}] 请把 host 开起来并完成注册，然后按回车...".format(trial, args.trials))

            if args.session:
                session = args.session
                print("  等待 session {} 出现 ...".format(session))
            else:
                print("  等待新 session 出现（基线 {} 个）...".format(len(baseline)))
                session = detect_new_session(args.relay, args.port, baseline, 90.0)
                if session is None:
                    print("  ! 90 秒内没看到新的 session，跳过这一轮")
                    print("    检查: 进程名对不对？中继控制台有没有 'session [x] run'？")
                    writer.writerow([trial, "", "", "", "", "no-show", "no new id"])
                    fh.flush()
                    continue
                print("  检测到新 session: {}".format(session))

            delay = random.uniform(args.delay_min, args.delay_max)
            print("  {:.1f} 秒后自动 kill（别动鼠标）".format(delay))
            time.sleep(delay)

            t_before, t_after = kill_host(args.image)
            if t_before is None:
                writer.writerow([trial, session, "", "", "", "kill-timeout", ""])
                fh.flush()
                continue
            t_kill = 0.5 * (t_before + t_after)     # 进程在 taskkill 调用期间死亡，取中点
            ok, t_first_miss, t_last_seen = wait_for_gone(
                args.relay, args.port, session, args.timeout, args.poll)
            if not ok:
                print("  ! {:.0f} 秒后仍然可见，记作未解析（多半是 taskkill 杀错了进程）".format(
                    args.timeout))
                writer.writerow([trial, session, "{:.6f}".format(t_before),
                                 "{:.6f}".format(t_after),
                                 ">{:.0f}".format(args.timeout), "not-resolved", ""])
                fh.flush()
                continue

            # 真值落在 [t_last_seen, t_first_miss]，取中点；半宽就是分辨率
            t_disappear = 0.5 * (t_last_seen + t_first_miss)
            dt = t_disappear - t_kill
            resolution = 0.5 * (t_first_miss - t_last_seen)
            print("  已 kill，开始计时 ... 消失用时 {:.2f} s（分辨率 ±{:.2f} s）".format(
                dt, resolution))

            note = ""
            if dt < LOW_EXPECTED - resolution:
                note = "below-window"        # 低于下界，测量可疑
                print("  !! {:.2f} s 低于 {:.1f} s 下界，本轮可疑".format(dt, LOW_EXPECTED))
            elif dt > HIGH_EXPECTED + resolution:
                note = "above-window"
                print("  !! {:.2f} s 高于 {:.0f} s 上界，本轮可疑".format(dt, HIGH_EXPECTED))

            rows.append(dt)
            writer.writerow([trial, session, "{:.6f}".format(t_before),
                             "{:.6f}".format(t_after), "{:.2f}".format(dt), "ok", note])
            fh.flush()

            if rows:
                print("  当前: n={}  median={:.2f} s  max={:.2f} s".format(
                    len(rows), statistics.median(rows), max(rows)))

    # ---- 汇总 ----
    print("\n== 结果 ==")
    if not rows:
        print("  没有有效样本。")
        return
    s = frp.summarize(rows)
    print("  n      = {}".format(s["n"]))
    print("  median = {:.2f} s".format(s["median"]))
    print("  min / max = {:.2f} / {:.2f} s".format(s["min"], s["max"]))

    print("\n== LaTeX 片段（Table III 那一行）==")
    print("  Stale session visibility after kill & {:.1f}\\,s & {:.1f}\\,s \\\\".format(
        s["median"], s["max"]))

    print("\n== 正文需要的另外两个数 ==")
    print("  P3  （kill 次数）      : {}".format(s["n"]))
    print("  P4  （最坏残留，秒）   : {:.1f}".format(s["max"]))
    print("  P12 （中位数，秒）     : {:.1f}".format(s["median"]))

    print("\n== 判读（理论上界 {:.0f} s，典型 ~2 s）==".format(HIGH_EXPECTED))
    if s["min"] >= LOW_EXPECTED - 0.3 and s["max"] <= HIGH_EXPECTED + 0.3:
        print("  OK: 全部落在 [{:.1f}, {:.0f}] s 内，与第 IV-E 节推导一致，可以直接填。".format(
            LOW_EXPECTED, HIGH_EXPECTED))
    else:
        print("  !! 有样本落在 [{:.1f}, {:.0f}] s 之外。".format(LOW_EXPECTED, HIGH_EXPECTED))
        print("     低于下界 => 测量问题（看 CSV 的 note 列，检查 kill 的目标对不对）")
        print("     高于上界 => 计时器被拖慢，很可能就是 VII-D 的忙轮询饥饿问题")
        print("     不要改数字去凑推导。")


if __name__ == "__main__":
    main()
