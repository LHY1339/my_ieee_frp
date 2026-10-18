# UnrealFRP — anonymous artefact

Artefact accompanying a submission to **IEEE Transactions on Games** (double-anonymous review):

> *UnrealFRP: A Self-Hosted Session Relay for Engine-Transparent NAT Traversal in Unreal Engine Multiplayer Games*

This repository contains the two halves of the system described in the paper, the
harness used to measure it, and the raw data behind every number in Section VII.
No author names, affiliations, funding acknowledgements, or identifying URLs
appear anywhere in this repository.

---

## 1. What is in here

```
proj/
  UnrealFRP/            Unreal Engine 4 runtime plugin (C++)
    Source/UnrealFRP/   module source
    UnrealFRP.uplugin   plugin descriptor
  ark_server/           standalone relay service (C++17, CMake)
    source/             app (UDP rendezvous), msg (TCP browser), session (relay)
    CMakeLists.txt
    CMakePresets.json

experiments/
  frp.py                shared client for the control protocol
  e1_control_latency.py E1: control-plane round trip, 1000 requests
  e2_staleness.py       E2: host-crash discovery time, N trials
  e4_relay_delay.py     E4: relayed data-path round trip (synthetic endpoints)
  e6_scaling.py         E6: concurrent-session sweep
  diag_control_split.py four-timestamp decomposition of one control request
  make_table.py         regenerates Table III's end-to-end rows from the CSVs
  *.csv                 raw measurements (see MEASUREMENTS.md)

MEASUREMENTS.md         provenance of every number: what was run, on what
LICENSE                 MIT
```

## 2. Requirements

| Component | Needs |
|---|---|
| Relay service | Windows (Winsock + I/O completion ports), MSVC, CMake >= 3.8 |
| Plugin | Unreal Engine 4.x |
| Measurement scripts | Python 3.8+, **standard library only** — no `pip install` |

We developed and measured on Windows 10 (build 19045) and Windows Server 2012.

## 3. Build

### Relay service

```bat
cd proj\ark_server
cmake --preset x64-release
cmake --build out\build\x64-release
```

The binary is written to `proj\ark_server\windows\ArkServer.exe`. It must be
started from a console so that its session log is visible:

```
<msg> run at port [2233]
<app> run at port [2233]
session [1001] run : [os:50032] [ls:50033] [pass:] [prop:...]
```

`msg` is TCP, `app` is UDP; both default to port 2233.

### Plugin

Copy `proj\UnrealFRP` into `<YourProject>\Plugins\`, enable it, and rebuild the
project. No engine change is required. The plugin's settings are exposed as
Blueprint calls (`UFRPLibrary::SetBaseIP`, `SetAppAddress`, `SetMsgAddress`), so
the relay address can come from a config file rather than a recompile.

## 4. Run

1. Start `ArkServer.exe` on a machine every participant can reach.
2. **Open the dynamic port range on the relay's firewall.** Session sockets ask
   the operating system for port zero, so they land outside the two fixed ports;
   on Windows the dynamic range is 49152-65535 by default. A narrow allow-list
   fails silently: the session registers and appears in the browser, but peers
   cannot reach it. Appendix B of the paper discusses this and why a fixed port
   pool is the better fix; our own deployment opened the whole range and we do
   not recommend copying it.
3. In game, set the relay IP and ports, call `OpenSession`, and set a property
   string if you want the session browser to show metadata.
4. Joining peers call `FlushFRPSessionList`, then `AskForAddress`, then
   `ConnectSession`; the plugin issues `open <relay>:<port>` internally.

## 5. Reproducing the numbers in the paper

`make_table.py` regenerates the end-to-end rows of Table III from the CSVs:

```bat
python experiments\make_table.py           :: print the LaTeX rows
python experiments\make_table.py --check   :: summary + the A/B difference
```

| Paper | Rows | Source |
|---|---|---|
| Table III, `polling + two writes` | `@get_list`, `@ask_addr` | `e1_local-lan.csv` |
| Table III, `polling + one write` | `@get_list`, `@ask_addr` | `e1_after-fix.csv` |
| Table III, `blocking wait (final)` | `@get_list`, `@ask_addr` | `e1_final2.csv`; `e1_final.csv` is the repeat run quoted in Section VII-B |
| Table III, decomposition (n = 20) | handshake / request-to-header / header-to-body | `diag_control_split.py`; output recorded in `MEASUREMENTS.md` |
| Table III, UDP baseline | 9.2 ms | `diag_control_split.py`, same run |
| Table III, relayed datagram | 16.1 ms | `e4_relay_rtt.csv` |
| Table III, staleness | n = 8 | `e2_staleness.csv` |
| Table IV (scaling) | 20 / 50 / 100 sessions | `e6_scaling.csv` |
| Table IV (scaling) | 200 / 300 sessions | `e6_high.csv` |

Every measurement was taken against one Tencent Cloud instance
(2 vCPU, 4 GB, 10 Mbit/s uplink, Windows Server 2012), with the tester on a
domestic broadband connection in Beijing. Re-running will give slightly
different numbers; the protocol and the harness are what should reproduce, not
the digits.

## 6. Known defects

Both are reported in the paper rather than hidden here.

* **The write pattern.** `msg::send_with_head` used to issue two `send` calls, a
  four-byte length header and then the body. With Nagle's algorithm on and no
  `TCP_NODELAY`, that cost 61 ms per request on Windows. This artefact contains
  the fix (one coalesced write); the difference is Table III's first two blocks.
* **The thread model.** Each session object owns one thread that blocks in
  `select`. It sustains 300 concurrent sessions on the two-vCPU instance
  (Table IV) but is linear in sessions; a single reactor would remove it.

## 7. Licence

MIT. See `LICENSE`.

## 8. Where the numbers came from

`MEASUREMENTS.md` records, for every figure in Section VII, the command that
produced it, the file it is stored in, and — where a run was overwritten by a
later one — what the earlier value was. Two of the values quoted in the paper
(the two intermediate data-plane figures in Section VII-D, and the 68-session
failure of the sleep build) have no surviving CSV; they are documented there so
that no number in the paper is unattributed.
