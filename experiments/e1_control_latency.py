"""E1 -- 控制面往返时延（@get_list 与 @ask_addr）。

用法（在每台能跑 Python 的机器上各跑一遍）:

    python e1_control_latency.py --relay <中继IP> --label local-lan
    python e1_control_latency.py --relay <中继IP> --label chongqing-campus
    python e1_control_latency.py --relay <中继IP> --label beijing-cellular

前提:
    中继已启动，并且**至少有一个 host 已经注册**（否则 @ask_addr 没有目标）。
    session id 会自动探测；有多个时用 --session 指定。

输出:
    e1_<label>.csv         每一条样本的原始时延
    屏幕上打印 median / p95 / max，以及可以直接粘进论文表格的 LaTeX 行

注意:
    每次请求都新建 TCP 连接，和插件的行为一致。不要改成复用连接。
"""
import argparse
import csv
import sys
import time

import frp


def measure(relay, port, payload, n, warmup):
    lat = []
    for i in range(n + warmup):
        _, ms = frp.tcp_request(relay, payload, port)
        if i >= warmup:
            lat.append(ms)
        if (i + 1) % max(1, (n + warmup) // 10) == 0:
            sys.stderr.write("\r  {:>6}/{}".format(i + 1, n + warmup))
            sys.stderr.flush()
    sys.stderr.write("\r  {:>6}/{}\n".format(n + warmup, n + warmup))
    return lat


def row(label, what, values, unit="ms"):
    s = frp.summarize(values)
    print(
        "  {:<22s} {:<12s} n={:<6d} median={:7.2f}  p95={:7.2f}  max={:8.2f}  [{}]".format(
            label, what, s["n"], s["median"], s["p95"], s["max"], unit
        )
    )
    return s


def latex_row(what, s, unit):
    cmd = "\\texttt{{{}}}".format(what.replace("_", "\\_"))
    return "{} & {:.1f}\\,{} & {:.1f}\\,{} \\\\".format(cmd, s["median"], unit, s["max"], unit)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--relay", required=True, help="中继 IP 或域名")
    ap.add_argument("--port", type=int, default=frp.DEFAULT_PORT, help="msg 服务端口，默认 2233")
    ap.add_argument("--label", required=True, help="这条路径的名字，用于文件名，例如 chongqing-campus")
    ap.add_argument("--n", type=int, default=1000, help="有效样本数，默认 1000")
    ap.add_argument("--warmup", type=int, default=20, help="预热样本数，丢弃，默认 20")
    ap.add_argument("--session", default=None, help="用于 @ask_addr 的 session id，省略则自动探测")
    ap.add_argument("--password", default="", help="session 密码，没有就留空")
    ap.add_argument("--out", default=None, help="CSV 路径，默认 e1_<label>.csv")
    args = ap.parse_args()

    out = args.out or "e1_{}.csv".format(args.label)

    print("== 探测 session ==")
    session = frp.pick_session(args.relay, args.port, args.session)
    print("  使用 session id: {}".format(session))

    payloads = [
        ("@get_list", b"@get_list"),
        ("@ask_addr/{}".format(session), ("@ask_addr/{}/{}".format(session, args.password)).encode()),
    ]

    summary = {}
    with open(out, "w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["label", "request", "i", "latency_ms"])

        print("\n== 计时（每条 {} 次 + {} 次预热）==".format(args.n, args.warmup))
        for what, payload in payloads:
            t_start = time.time()
            lat = measure(args.relay, args.port, payload, args.n, args.warmup)
            for i, v in enumerate(lat):
                w.writerow([args.label, what, i, "{:.3f}".format(v)])
            s = row(args.label, what, lat)
            s["wall_s"] = time.time() - t_start
            summary[what] = s

    print("\n== LaTeX 片段（粘进 Table III）==")
    for what, s in summary.items():
        print("  " + latex_row(what, s, "ms"))

    print("\n== 提醒 ==")
    lo = summary["@get_list"]["median"]
    if lo > 200:
        print("  ! median 超过 200 ms，检查是否每次都在解析 DNS（换成 IP 再测一次）")
    if summary["@get_list"]["max"] > 10 * max(1.0, lo):
        print("  ! max 是 median 的 10 倍以上，多半是 TCP SYN 重传，正文里要说明")
    print("  原始样本已写入 {}".format(out))


if __name__ == "__main__":
    main()
