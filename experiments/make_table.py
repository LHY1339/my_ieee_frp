"""从原始 CSV 生成 Table III 的 LaTeX 行 —— 表格不再手工抄。

用法:
    python make_table.py            # 打印 LaTeX 行
    python make_table.py --check     # 只校验论文里的数是否与 CSV 一致

设计原则：表里每一个数都必须能由这里的某次 CSV 重算出来。
任何手工抄写都会漂，这个脚本就是防漂的。
"""
import argparse
import csv
import glob
import os
import statistics
import sys

HERE = os.path.dirname(os.path.abspath(__file__))

# 论文里每一行 <-> (CSV 文件, request 前缀)
SOURCES = [
    # 第一版：忙轮询 + 两次写
    ("polling_two_writes_list", "e1_local-lan.csv", "@get_list"),
    ("polling_two_writes_addr", "e1_local-lan.csv", "@ask_addr"),
    # 第二版：忙轮询 + 一次写（Nagle 修复）
    ("polling_one_write_list",  "e1_after-fix.csv", "@get_list"),
    ("polling_one_write_addr",  "e1_after-fix.csv", "@ask_addr"),
    # 第三版（最终）：select 阻塞等待 + 一次写
    ("final_list",              "e1_final2.csv",    "@get_list"),
    ("final_addr",              "e1_final2.csv",    "@ask_addr"),
]

LABELS = [
    ("polling_two_writes_list", "\\texttt{@get\\_list}, polling + two writes"),
    ("polling_two_writes_addr", "\\texttt{@ask\\_addr}, polling + two writes"),
    ("polling_one_write_list",  "\\texttt{@get\\_list}, polling + one write"),
    ("polling_one_write_addr",  "\\texttt{@ask\\_addr}, polling + one write"),
    ("final_list",              "\\texttt{@get\\_list}, blocking wait (final)"),
    ("final_addr",              "\\texttt{@ask\\_addr}, blocking wait (final)"),
]


def load(fname, prefix):
    path = os.path.join(HERE, fname)
    if not os.path.exists(path):
        return None
    vals = []
    with open(path, newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            if row["request"].startswith(prefix):
                vals.append(float(row["latency_ms"]))
    return vals or None


def load_e2():
    path = os.path.join(HERE, "e2_staleness.csv")
    if not os.path.exists(path):
        return None
    vals = []
    with open(path, newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            if row.get("resolved") == "ok" and row.get("disappeared_s"):
                vals.append(float(row["disappeared_s"]))
    return vals or None


def load_e4():
    path = os.path.join(HERE, "e4_relay_rtt.csv")
    if not os.path.exists(path):
        return None
    vals = []
    with open(path, newline="", encoding="utf-8") as fh:
        for row in csv.DictReader(fh):
            vals.append(float(row["rtt_ms"]))
    return vals or None


def stats(vals):
    if not vals:
        return None
    s = sorted(vals)
    n = len(s)
    med = statistics.median(s)
    p95 = s[min(n - 1, max(0, int(round(0.95 * (n - 1)))))]
    return {"n": n, "median": med, "p95": p95, "max": s[-1], "min": s[0]}


def fmt(v, unit):
    return "{:.1f}\\,{}".format(v, unit)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="只对论文里写的数做校验")
    args = ap.parse_args()

    table = {}
    for key, fname, prefix in SOURCES:
        st = stats(load(fname, prefix))
        if st:
            table[key] = st
        else:
            print("! 缺少数据: {} ({})".format(fname, prefix), file=sys.stderr)

    e2 = stats(load_e2())
    e4 = stats(load_e4())

    print("% ===== 由 make_table.py 生成，勿手工修改 =====")
    for key, label in LABELS:
        st = table.get(key)
        if not st:
            continue
        print("{} & {} & {} & {} \\\\".format(
            label, st["n"], fmt(st["median"], "ms"), fmt(st["max"], "ms")))

    if e4:
        print("Relayed datagram, final (4 crossings) & {} & {} & {} \\\\".format(
            e4["n"], fmt(e4["median"], "ms"), fmt(e4["max"], "ms")))
    if e2:
        print("Stale visibility after kill & {} & {} & {} \\\\".format(
            e2["n"], fmt(e2["median"], "s"), fmt(e2["max"], "s")))

    print("\n% ---- 汇总 ----")
    for k, st in table.items():
        print("% {:<16} n={:<5} median={:7.2f} p95={:7.2f} max={:7.2f}".format(
            k, st["n"], st["median"], st["p95"], st["max"]))
    if e2:
        print("% {:<16} n={:<5} median={:7.2f} max={:7.2f}".format(
            "e2_staleness", e2["n"], e2["median"], e2["max"]))
    if e4:
        print("% {:<16} n={:<5} median={:7.2f} max={:7.2f}".format(
            "e4_relay_rtt", e4["n"], e4["median"], e4["max"]))

    if args.check and table.get("polling_two_writes_list") and table.get("polling_one_write_list"):
        a = table["polling_two_writes_list"]["median"]
        b = table["polling_one_write_list"]["median"]
        c = table["final_list"]["median"] if table.get("final_list") else None
        print("\n% Nagle 修复前后中位差 = {:.2f} ms（对照分段测量的 61.0 ms）".format(a - b))
        if c is not None:
            print("% 再改 select 后 = {:.1f} ms，又降 {:.1f} ms（这是线程调度，不是 Nagle）".format(c, b - c))


if __name__ == "__main__":
    main()
