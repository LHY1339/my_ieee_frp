# 测量脚本（第 VII 节数据来源）

纯 Python 标准库，**不需要 pip install**。

| 文件 | 作用 | 状态 |
|---|---|---|
| `frp.py` | 共用工具：控制请求、列表解析、统计 | 已验证（E1/E2 跑通） |
| `e1_control_latency.py` | E1 控制面往返时延 → Table III 前两行 | **已测完，数据已入稿** |
| `e2_staleness.py` | E2 崩溃发现时延 → Table III 第三行 | **已测完（30 轮），数据已入稿** |
| `e4_relay_delay.py` | E4 数据面附加时延（假端点，不开游戏） | 待跑 |
| `e6_scaling.py` | E6 扩展性 / 饱和点（假 host，不开游戏） | 待跑 |

> 说明：E4 和 E6 我没法替你跑——沙箱没有到外网任意 UDP/TCP 的能力，
> 中继又是你的私有 VPS。这两个脚本语法我核过，但**没有实际执行过**，
> 第一次跑如果报错，把完整报错贴给我。
> 自检：`python -m py_compile frp.py e4_relay_delay.py e6_scaling.py`

---

## 0. 前置条件（两个实验都要求）

1. 中继服务在跑，控制台能看到 `<app> run at port [...]` 和 `<msg> run at port [...]`
2. **至少一个 host 已经注册**（否则列表是空的）
3. 云端安全组：UDP + TCP 的 1000–5000 已放通（你已经配过了）
4. Python 3.8 以上，能在要测的那台机器上运行

先做一次连通性自检：

```bash
python -c "import frp; print(frp.list_ids('你的中继IP'))"
```

打印出 `['1']` 之类就通了；报 `ConnectionError` 就是端口/安全组的问题。

---

## 1. E1 控制面时延

### 跑几遍

在**每一条要写进论文的路径**上各跑一遍，用 `--label` 区分：

```bash
# 本机（和 host 同机，路径最短）
python e1_control_latency.py --relay 1.2.3.4 --label local-lan

# 重庆校园网那台
python e1_control_latency.py --relay 1.2.3.4 --label chongqing-campus

# 手机热点给笔记本供网（测移动数据那条路径）
python e1_control_latency.py --relay 1.2.3.4 --label beijing-cellular
```

每遍 1000 次有效样本 + 20 次预热，大约 1–3 分钟。

### 输出

- 屏幕：`median / p95 / max`，外加可以直接粘进 Table III 的 LaTeX 行
- 文件：`e1_<label>.csv`，每一条样本都在里面（放进匿名仓库）

### 怎么填进论文

Table III 每行只有一个 median 和一个 max，所以选**跨省那条路径**（最保守），
另外两条在正文里一句话带过：

> Control-plane round trips were 3.5 ms (median) on the shared LAN and
> 41.8 ms from the campus network; we report the latter, since it is the
> case a remote participant experiences.

如果你只能在本机跑（没有第二台能跑 Python 的机器），就填本机的数，并把
第 VII-A 节里关于"three access networks"的那句改成如实的描述 —— **别声称测了没测过的路径**。

---

## 2. E2 崩溃发现时延

### 关键设计

脚本**自己执行 taskkill**，而不是你手按。因为人的反应时间约 0.3 s，
在 3–4 秒的量级上是显著误差。

### 操作

```bash
python e2_staleness.py --relay 1.2.3.4 --trials 30
```

每一轮：

1. 脚本提示"请把 host 开起来并完成注册，然后按回车"
2. 脚本等 session 出现在列表里（最多 90 s）
3. 随机等 3–15 秒（避免和心跳周期共振）
4. **脚本自动** `taskkill /F /IM UE4Editor.exe`
5. 每 0.1 秒查一次列表，连续 3 次查不到才算消失
6. 记录秒数

一轮结束后，回到第 1 步重开 host，共 30 轮。

### 进程名要对

- 在编辑器里跑：`--image UE4Editor.exe`（默认）
- 打包后的游戏：`--image 你的游戏名-Win64-Shipping.exe`
- **不确定就先手动试一次**：`taskkill /F /IM UE4Editor.exe` 看是不是真的杀掉了 host

如果 host 和 client 跑在同一个 exe 里，两个会一起被杀 —— 对本实验**没有影响**，
我们只关心 host 那条 session 什么时候消失。

### 输出

- `e2_staleness.csv`
- 屏幕最后会打印：
  - `n`（= P3）
  - `max`（= P4 = P13）
  - `median`（= P12）
  - LaTeX 行：`Stale session visibility after kill & x.x\,s & x.x\,s \\`
  - **判读**：`max <= 4.0 s` 才会告诉你 "OK"

### 如果 max 超过 3 秒

脚本会明确警告。**不要改数字去凑论文里的 three seconds**。先查：

1. 中继的 session 线程是不是把 CPU 占满了（忙轮询，`netlib::recv` 是非阻塞的，
   线程在 `while(is_running)` 里空转）
2. `taskkill` 是不是杀错了进程（看是不是 30 秒都没消失）

如果确认是设计所限，就把正文那句 `bounds host-failure detection at four
seconds` 改成实测值，并在 VII-D 解释原因 —— 这个诚实度反而是加分项。

---

## 4. E4 数据面附加时延（不需要开游戏）

用两个假端点直接测中继的转发时延。原理：一次探测经过 4 段单程链路
（peer→中继→host→中继→peer），host/peer 同机时相邻两段等长，所以

```
RTT_中继 ≈ 2 × 链路 RTT
中继处理开销 = RTT_中继 − 2 × 链路 RTT   ← 这个应该接近 0
```

```bash
# 如果已经 ping 过，把中位数直接给它，比 TCP 握手自测更准
python e4_relay_delay.py --relay 111.228.32.155 --icmp-rtt 40

# 或者让它自己测
python e4_relay_delay.py --relay 111.228.32.155
```

跑约 20 秒。输出会直接告诉你"中继开销 +x.x ms"。

> 前提：中继在跑，并且 `--app-port` 是 UDP 的 app 端口（默认 2233）。
> 脚本会自己建一个假 session、查自己的 listen 端口、然后打回声。
> 不需要 host 游戏在线。

## 5. E6 扩展性（不需要开游戏、不需要读 CPU）

不读中继的 CPU，而是利用"掉 tick = session 被误回收"这个后果来定位饱和点：
造 N 个假 host 每秒发心跳，同时每秒查列表，**明明还在发心跳却从列表消失了**，
就说明中继那一秒的计时器没跑。

```bash
python e6_scaling.py --relay 111.228.32.155 --levels 10,50,100 --hold 30
```

约 3–5 分钟（每级 30 秒 + 创建/回收开销）。最后会打印：

- 每级：存活最少几个、丢了几个、列表时延中位/最大
- **第一次出现误回收是在多少个并发 session**
- 一段可以直接抄进论文的英文结论

如果到 100 个都没出错，就加大：`--levels 100,200,300`。

> 你的中继是 10 Mbit/s 上行。如果**带宽**先到顶，这个脚本看不出来
> （假 host 只发心跳，几乎没有流量）。要测带宽墙得另做，本文暂时不需要。

## 6. 跑完把什么发给我

直接贴这几段：

```
E4:
   RTT 中位数 = ____ ms
   链路 RTT   = ____ ms
   中继开销   = ____ ms

E6:
   级别    目标   存活最少   丢失事件   列表中位   列表最大
   1        10     __        __         __        __
   2        50     __        __         __        __
   3       100     __        __         __        __
   饱和点 = ____ 个并发 session ／ 或"到 100 未饱和"
```

## 7. 常见问题

| 现象 | 原因 | 处理 |
|---|---|---|
| `ConnectionError: relay 在长度头之前就关了连接` | 请求发到了 UDP 端口 / 防火墙拦了 | 确认连的是 TCP 的 `msg` 端口 |
| `列表里有 0 个 session` | host 没注册，或 `@reg` 被丢了 | 看中继控制台有没有 `session [x] run` |
| `@ask_addr` 返回 `@addr/error` | session id 不对，或密码错 | 用 `--session` 指定正确的 id |
| E2 每一轮都 `no-show` | 杀进程杀早了 / host 没起来 | 把 `--image` 换成正确的 exe 名 |
| E1 的 median 突然变成几百毫秒 | 用的域名，每次都 DNS 解析 | 改用 IP |
| E4 一个回显都没收到 | listen 端口没放通，或 `@imowner` 没发出去 | 确认安全组包含 1000–5000 UDP |
| E6 一直"存活最少"等于目标数 | 中继很健康，还没到饱和点 | 加大 `--levels` |
