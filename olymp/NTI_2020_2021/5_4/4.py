# put your python code here

import array as arr

a = []
used = []
mn = []

for i in range(14):
    a.append([])
    for j in range(14):
        a[i].append([])
        for k in range(14):
            a[i][j].append([])
            for p in range(14):
                a[i][j][k].append(1)

for i in range(14):
    used.append([])
    for j in range(14):
        used[i].append([])
        for k in range(4):
            used[i][j].append(0)

for i in range(14):
    mn.append([])
    for j in range(14):
        mn[i].append(1000)

def blockX(x, y1, y2):
    for i in range(y1, y2+1):
        a[x][i][x+1][i] = 0
        a[x+1][i][x][i] = 0

def blockY(y, x1, x2):
    for i in range(x1, x2+1):
        a[i][y][i][y+1] = 0
        a[i][y+1][i][y] = 0

blockX(0, 1, 12)
blockX(1, 2, 4)
blockX(1, 9, 11)
blockX(2, 5, 9)
blockX(3, 2, 3)
blockX(3, 5, 6)
blockX(3, 9, 9)
blockX(4, 1, 3)
blockX(4, 10, 10)
blockX(5, 2, 2)
blockX(5, 6, 6)
blockX(5, 9, 9)
blockX(6, 3, 3)
blockX(6, 5, 7)
blockX(7, 2, 2)
blockX(7, 5, 7)
blockX(7, 10, 12)
blockX(8, 3, 3)
blockX(8, 5, 7)
blockX(8, 10, 11)
blockX(9, 5, 7)
blockX(9, 10, 11)
blockX(10, 6, 6)
blockX(11, 2, 3)
blockX(11, 9, 11)
blockX(12, 1, 12)

blockY(0, 1, 12)
blockY(1, 2, 3)
blockY(1, 5, 10)
blockY(2, 9, 10)
blockY(3, 2, 3)
blockY(3, 5, 10)
blockY(4, 5, 6)
blockY(4, 8, 8)
blockY(4, 10, 11)
blockY(5, 2, 2)
blockY(5, 5, 5)
blockY(5, 11, 11)
blockY(6, 5, 5)
blockY(6, 11, 11)
blockY(7, 5, 6)
blockY(7, 8, 8)
blockY(7, 10, 11)
blockY(8, 2, 7)
blockY(9, 2, 2)
blockY(9, 8, 8)
blockY(9, 10, 11)
blockY(10, 2, 6)
blockY(11, 2, 7)
blockY(11, 10, 11)
blockY(12, 1, 12)

x1, y1, c1 = input().split()
x2, y2, c2 = input().split()
x1 = int(x1)
x2 = int(x2)
y1 = int(y1)
y2 = int(y2)

q = []
q.append([[x2, y2, c2], 0])

while len(q):
    x = q[0][0][0]
    y = q[0][0][1]
    c = q[0][0][2]
    l = q[0][1]
    q = q[1:]
    mn[x][y] = min(mn[x][y], l)
    if c == 'D':
        if(used[x][y][1] == 0):
            q.append([[x, y, 'R'], l + 1])
            used[x][y][1] = 1
        if(used[x][y][3] == 0):
            q.append([[x, y, 'L'], l + 1])
            used[x][y][3] = 1
        if(a[x][y][x + 1][y] == 1) and (used[x + 1][y][2] == 0):
            q.append([[x + 1, y, 'D'], l + 1])
            used[x + 1][y][2] = 1
    if c == 'U':
        if(used[x][y][1] == 0):
            q.append([[x, y, 'R'], l + 1])
            used[x][y][1] = 1
        if(used[x][y][3] == 0):
            q.append([[x, y, 'L'], l + 1])
            used[x][y][3] = 1
        if (a[x][y][x - 1][y] == 1) and (used[x - 1][y][0] == 0):
            q.append([[x - 1, y, 'U'], l + 1])
            used[x - 1][y][0] = 1
    if c == 'L':
        if(used[x][y][2] == 0):
            q.append([[x, y, 'D'], l + 1])
            used[x][y][2] = 1
        if(used[x][y][0] == 0):
            q.append([[x, y, 'U'], l + 1])
            used[x][y][0] = 1
        if (a[x][y][x][y - 1] == 1) and (used[x][y - 1][3] == 0):
            q.append([[x, y - 1, 'L'], l + 1])
            used[x][y - 1][3] = 1
    if c == 'R':
        if (used[x][y][2] == 0):
            q.append([[x, y, 'D'], l + 1])
            used[x][y][2] = 1
        if (used[x][y][0] == 0):
            q.append([[x, y, 'U'], l + 1])
            used[x][y][0] = 1
        if (a[x][y][x][y + 1] == 1) and (used[x][y + 1][1] == 0):
            q.append([[x, y + 1, 'R'], l + 1])
            used[x][y + 1][1] = 1

q.append([[x1, y1, c1], 0, 0])

ans = 1000

while len(q) != 0:
    x = q[0][0][0]
    y = q[0][0][1]
    c = q[0][0][2]
    l = q[0][1]
    z = q[0][2]
    q = q[1:]
    if a[x][y][x+1][y] == 1 and mn[x+1][y] <= l:
        ans = l
        break;
    if a[x][y][x-1][y] == 1 and mn[x-1][y] <= l:
        ans = l
        break;
    if a[x][y][x][y+1] == 1 and mn[x][y+1] <= l:
        ans = l
        break;
    if a[x][y][x][y-1] == 1 and mn[x][y-1] <= l:
        ans = l
        break;

    if c == 'U':
        if a[x][y][x][y - 1] == 1 and z == 0:
            q.append([[x, y, 'L'], l + 1, 1])
        elif a[x][y][x - 1][y] == 1:
            q.append([[x - 1, y, 'U'], l + 1, 0])
        else:
            q.append([[x, y, 'R'], l + 1, 0])
    if c == 'R':
        if a[x][y][x - 1][y] == 1 and z == 0:
            q.append([[x, y, 'U'], l + 1, 1])
        elif a[x][y][x][y + 1] == 1:
            q.append([[x, y + 1, 'R'], l + 1, 0])
        else:
            q.append([[x, y, 'D'], l + 1, 0])
    if c == 'D':
        if a[x][y][x][y + 1] == 1 and z == 0:
            q.append([[x, y, 'R'], l + 1, 1])
        elif a[x][y][x + 1][y] == 1:
            q.append([[x + 1, y, 'D'], l + 1, 0])
        else:
            q.append([[x, y, 'L'], l + 1, 0])
    if c == 'L':
        if a[x][y][x + 1][y] == 1 and z == 0:
            q.append([[x, y, 'D'], l + 1, 1])
        elif a[x][y][x][y - 1] == 1:
            q.append([[x, y - 1, 'L'], l + 1, 0])
        else:
            q.append([[x, y, 'U'], l + 1, 0])

print(ans)


