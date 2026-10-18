# MEASUREMENTS — provenance of every number in Section VII

This file exists because a reviewer is entitled to trace any number in the paper
to the run that produced it. Everything below was measured from this repository,
on one machine pair, on 18 October 2026.

## Environment

| | |
|---|---|
| Client / game host | Windows 10 (build 19045), Intel Core i5-13500HX (14 cores / 20 threads), 15.7 GB RAM |
| Relay | Tencent Cloud, 2 vCPU, 4 GB RAM, 10 Mbit/s uplink, Windows Server 2012, `ArkServer.exe` |
| Access path | Domestic broadband, Beijing |
| ICMP | filtered on the instance; `ping` is not available, so the UDP rendezvous round trip is used as the path baseline everywhere |
| Python | 3.12, standard library only |

## Protocol of the harness

Every script speaks the control protocol directly: ASCII request, reply framed by
a 4-byte little-endian length. `frp.py` is the only implementation of that
framing; the other scripts import it.

---

## E1 — control-plane round trip (`e1_control_latency.py`)

1000 requests per request type, 20 warm-up requests discarded, one fresh TCP
connection per request (which is what the plugin does).

| Build | File | `@get_list` median / max | `@ask_addr` median / max |
|---|---|---|---|
| polling + two writes | `e1_local-lan.csv` | 93.5 / 295.0 ms | 93.2 / 294.8 ms |
| polling + one write | `e1_after-fix.csv` | 31.7 / 76.5 ms | 32.0 / 249.4 ms |
| blocking wait | `e1_final.csv` | 24.2 / 82.9 ms | 25.9 / 115.2 ms |
| blocking wait, repeat | `e1_final2.csv` | 24.4 / 96.4 ms | 23.9 / 91.4 ms |

Table III reports `e1_final2.csv` for the final build and quotes `e1_final.csv`
as the repeat run in Section VII-B. **The first row was produced twice**: the
first run (session id 1003) was reported from the console and its file was later
overwritten by a second run of the same command (session id 1005). The numbers in
the table are the second run's, i.e. the ones that survive in the CSV.

## E1b — four-timestamp decomposition (`diag_control_split.py`)

This produced the decomposition rows of Table III and the UDP baseline. It
prints to the console and does not write a CSV, which is why those rows are not
regenerable by `make_table.py`; the console output is reproduced here.

Run 1, polling + two writes, 20 requests:

```
connect          27.8 ms   (min 25.3 / max 29.5)
request -> hdr   10.6 ms   (min  9.3 / max 12.2)
hdr -> body      61.0 ms   (min 59.2 / max 64.4)
total            98.9 ms
UDP rendezvous RTT (n=20)  10.3 ms
```

Run 2, polling + one write, 20 requests:

```
connect          25.6 ms   (min 11.5 / max 29.5)
request -> hdr   10.9 ms   (min  9.3 / max 13.8)
hdr -> body       0.0 ms   (20 of 20 samples exactly 0.0)
total            36.0 ms
UDP rendezvous RTT (n=20)   9.2 ms
```

The decomposition was **not** re-run on the blocking-wait build; Section VII-B
says so and restricts the interpretation accordingly. The UDP baseline in the
table is Run 2's 9.2 ms.

## E2 — host-crash discovery time (`e2_staleness.py`)

8 trials, 0.1 s polling resolution. `--trials 30` was requested but the run was
aborted partway; the CSV holds 8 completed trials and the paper reports n = 8.

| File | n | median | max |
|---|---|---|---|
| `e2_staleness.csv` | 8 | 2.2 s | 2.8 s |

Pre-fix runs of the same script against a build with a live 1000-request
dataset produced 2.28 s on one trial; that value is not used.

## E4 — relayed data-path round trip (`e4_relay_delay.py`)

Two synthetic endpoints hold one session; one sends a timestamped datagram per
probe, the other echoes what the relay forwards. 1000 probes at 50 per second.
The script writes to `e4_relay_rtt.csv` by default.

| Build | Round trip median / max | Where used |
|---|---|---|
| polling | 18.5 / 62.0 ms | quoted in Section VII-D as the "before" value |
| sleep(1 ms) | 33.9 / 207.7 ms | quoted in Section VII-D as the regression |
| blocking wait (final) | 16.1 / 74.2 ms (`e4_relay_rtt.csv`) | Table III |

**Only the final run's CSV survives**: the script writes to a fixed filename, so
the two earlier runs were overwritten. They are recorded here so that the two
figures quoted in Section VII-D are not unattributed; re-running the command on
the corresponding build reproduces them.

The "two link round trips" prediction uses the 9.2 ms UDP baseline from E1b,
which was measured in a different run and on a different socket. Section VII-C
argues why the 2.3 ms difference between prediction and measurement should not be
read as a negative processing cost.

## E6 — concurrent-session sweep (`e6_scaling.py`)

Synthetic hosts register and heartbeat at 1 Hz; each level is held 20 s; the
harness polls `@get_list` once per second and counts sessions that expire while
their host is still heartbeating. **The synthetic hosts carry no payload**, so
this measures the thread budget and not the link (Section VII-D).

| Level | File | Expiry events | Min alive | `@get_list` median / max |
|---|---|---|---|---|
| 20 | `e6_scaling.csv` | 0 | 20 | 40.2 / 51.9 ms |
| 50 | `e6_scaling.csv` | 0 | 50 | 40.1 / 69.5 ms |
| 100 | `e6_scaling.csv` | 0 | 100 | 42.7 / 65.4 ms |
| 200 | `e6_high.csv` | 0 | 200 | 52.0 / 80.8 ms |
| 300 | `e6_high.csv` | 0 | 300 | 49.3 / 108.5 ms |

An earlier sweep on the sleep(1 ms) build failed at 100 sessions (68 expiry
events, surviving count oscillating between 52 and 86). That run's CSV was
overwritten by the final sweep; the qualitative claim in Section VII-D rests on
it, and the command reproduces it on that build.

## Not measured

* **Per-match bandwidth.** No multi-player match was recorded, so the paper's
  150-300 kbit/s per match is a working estimate, labelled as such, and the
  bandwidth ceiling derived from it is arithmetic rather than measurement.
* **Engine-in-the-loop fidelity.** No probe in E4 was generated by
  `UIpNetDriver`; Section VII-C states this explicitly.
* **CPU and memory of the relay process.** The sweep infers the thread cost from
  the symptom (expired sessions) rather than from a profiler.
