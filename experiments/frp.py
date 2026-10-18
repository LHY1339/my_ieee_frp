"""FRP 测量脚本共用的工具函数。

线上格式（对应论文附录 A）:
  * 控制请求是纯 UTF-8 文本，没有长度头
  * 控制应答是 4 字节小端 uint32 长度 + 正文
  * 列表正文形如  "@list/<id>&<has_password>&<property>/..."

只用标准库，不需要 pip install。
"""
from __future__ import annotations

import socket
import struct
import time

DEFAULT_PORT = 2233


def tcp_request(relay, payload, port=DEFAULT_PORT, timeout=5.0):
    """发一条控制请求，返回 (body_bytes, elapsed_ms)。

    每次新建连接，因为插件就是这么做的（FRPSubsystem::SendMsgAsync）。
    复用连接会把数字测得比真实情况好看，属于失真。
    """
    t0 = time.perf_counter()
    sock = socket.create_connection((relay, port), timeout=timeout)
    try:
        sock.sendall(payload)
        header = b""
        while len(header) < 4:
            chunk = sock.recv(4 - len(header))
            if not chunk:
                raise ConnectionError("relay 在长度头之前就关了连接")
            header += chunk
        length = struct.unpack("<I", header)[0]
        if length == 0 or length > (1 << 20):
            raise ValueError("应答长度不合理: {}".format(length))
        body = b""
        while len(body) < length:
            chunk = sock.recv(length - len(body))
            if not chunk:
                raise ConnectionError("relay 在正文中途关了连接")
            body += chunk
        return body, (time.perf_counter() - t0) * 1000.0
    finally:
        sock.close()


def parse_list(body):
    """把 '@list/...' 正文解析成 [(id, has_password, property), ...]。"""
    text = body.split(b"\x00", 1)[0].decode("utf-8", "replace")
    if not text.startswith("@list"):
        raise ValueError("不是列表应答: {!r}".format(text[:40]))
    records = []
    for field in text[len("@list"):].split("/"):
        if not field:
            continue
        parts = field.split("&", 2)
        if len(parts) == 3:
            records.append((parts[0], parts[1] == "true", parts[2]))
    return records


def list_ids(relay, port=DEFAULT_PORT):
    """返回当前所有 session 的 id 字符串列表。"""
    body, _ = tcp_request(relay, b"@get_list", port)
    return [r[0] for r in parse_list(body)]


def summarize(values):
    """返回 n / min / median / p95 / max。"""
    ordered = sorted(values)
    n = len(ordered)
    if n == 0:
        raise ValueError("没有样本")
    if n % 2:
        median = ordered[n // 2]
    else:
        median = 0.5 * (ordered[n // 2 - 1] + ordered[n // 2])
    return {
        "n": n,
        "min": ordered[0],
        "median": median,
        "p95": ordered[min(n - 1, max(0, int(round(0.95 * (n - 1)))))],
        "max": ordered[-1],
    }


def pick_session(relay, port=DEFAULT_PORT, explicit=None):
    """确定要用的 session id：显式给定，或者列表里唯一的那一个。"""
    ids = list_ids(relay, port)
    if explicit:
        if explicit not in ids:
            raise SystemExit(
                "指定的 session {!r} 不在列表里。当前列表: {}".format(explicit, ids or "（空）")
            )
        return explicit
    if len(ids) == 1:
        return ids[0]
    raise SystemExit(
        "列表里有 {} 个 session，请用 --session 指定一个。当前: {}".format(len(ids), ids or "（空）")
    )
