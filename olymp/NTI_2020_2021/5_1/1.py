import sys

a = []
used = []
col = []
it = 1
now = 0
mas = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def dfs(i, j):
    queue = [[i, j]]
    while queue:
        v = queue.pop()
        i = v[0]
        j = v[1]
        cnt = 0
        global used, a, now, col, it, mas
        used[i][j] = 1
        for k in range(4):
            i1 = mas[k][0] + i
            j1 = mas[k][1] + j
            if 600 > i1 >= 0 and 800 > j1 >= 0:
                if a[i1][j1] != a[i][j]:
                    if col[i1][j1] != it:
                        cnt += 1
                    col[i1][j1] = it
            else:
                cnt += 1
        now += cnt
        for k in range(4):
            i1 = mas[k][0] + i
            j1 = mas[k][1] + j
            if 600 > i1 >= 0 and 800 > j1 >= 0:
                if a[i1][j1] == a[i][j] and used[i1][j1] == 0:
                    queue.append([i1, j1])


mx = 0
v = []
for i in range(800):
    v.append(0)
for i in range(600):
    a.append(input().split())
    col.append(v.copy())
    used.append(v.copy())
for i in range(600):
    for j in range(800):
        if a[i][j] != "ffffff" and used[i][j] == 0:
            now = 0
            dfs(i, j)
            mx = max(mx, now)
            it += 1
print(mx)