def translater(a):
    if a == 'U':
        return 0
    if a == 'L':
        return 1
    if a == 'D':
        return 2
    return 3


def forward(a):
    if a[2] == 0:
        a[1] -= 1
    if a[2] == 1:
        a[0] -= 1
    if a[2] == 2:
        a[1] += 1
    if a[2] == 3:
        a[0] += 1
    return a


n, dir, xf, yf, xs, ys = map(str, input().split())
n = int(n)
xf = int(xf)
yf = int(yf)
xs = int(xs)
ys = int(ys)
blocked = []
for i in range(n):
    blocked.append([])
    s = map(int, input().split())
    for u in s:
        blocked[i].append(u)
d = []
used = []
par = []
for i in range(n):
    d.append([])
    used.append([])
    par.append([])
    for j in range(n):
        d[i].append([])
        used[i].append([])
        par[i].append([])
        for k in range(4):
            d[i][j].append(0)
            used[i][j].append(0)
            par[i][j].append([-1, -1, -1])
d[xf][yf][translater(dir)] = 0
q = [[xf, yf, translater(dir)]]
used[xf][yf][translater(dir)] = 1
while len(q) != 0:
    p = q[0]
    q.pop(0)
    if blocked[p[1]][p[0]] == 1:
        continue
    if used[p[0]][p[1]][(p[2] + 1) % 4] == 0:
        used[p[0]][p[1]][(p[2] + 1) % 4] = 1
        d[p[0]][p[1]][(p[2] + 1) % 4] = d[p[0]][p[1]][p[2]] + 1
        par[p[0]][p[1]][(p[2] + 1) % 4] = p.copy()
        q.append([p[0], p[1], (p[2] + 1) % 4].copy())
    if used[p[0]][p[1]][(p[2] + 3) % 4] == 0:
        used[p[0]][p[1]][(p[2] + 3) % 4] = 1
        d[p[0]][p[1]][(p[2] + 3) % 4] = d[p[0]][p[1]][p[2]] + 1
        par[p[0]][p[1]][(p[2] + 3) % 4] = p.copy()
        q.append([p[0], p[1], (p[2] + 3) % 4].copy())
    nt = forward(p.copy())
    if n > nt[0] >= 0 and n > nt[1] >= 0 and used[nt[0]][nt[1]][nt[2]] == 0:
        used[nt[0]][nt[1]][nt[2]] = 1
        d[nt[0]][nt[1]][nt[2]] = d[p[0]][p[1]][p[2]] + 1
        par[nt[0]][nt[1]][nt[2]] = p.copy()
        q.append(nt.copy())
now = [0, 0, 0]
mn = int(1e18)
for k in range(4):
    mn = min(mn, d[xs][ys][k])
for k in range(4):
    if d[xs][ys][k] == mn:
        now = [xs, ys, k]
        break
ans = []
while par[now[0]][now[1]][now[2]][2] != -1:
    p = par[now[0]][now[1]][now[2]].copy()
    if p[2] == now[2]:
        ans.append('F')
    elif (p[2] + 1) % 4 == now[2]:
        ans.append('L')
    else:
        ans.append('R')
    now = p
ans = reversed(ans)
for u in ans:
    print(u, end='')
