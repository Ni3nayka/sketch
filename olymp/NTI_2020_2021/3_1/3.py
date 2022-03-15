
from copy import deepcopy

blocked = []
d = []
used = []
par = []
ans = []
now = [0, 0, 0]
n = 0
ugol = 0
x1 = 0
y1 = 0
x0 = 0
y0 = 0
q = 0
mn = 10**18

def read_data():
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    #global n, ugol, x1, y1, x0, y0, blocked
    n, ugol, x1, y1, x0, y0 = map(str, input().split())
    n = int(n)
    x1 = int(x1)
    y1 = int(y1)
    x0 = int(x0)
    y0 = int(y0)
    blocked.clear()
    i = 0
    while (i<n):
        if (1):
            blocked.append([])
        s = map(int, input().split())
        for u in s:
            blocked[i].append(u)
        i+=1

def print_answer():
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    ans = reversed(ans)
    for u in ans:
        print(u, end='')

def translater(d):
    array = "ULDR"
    return array.index(d)

def forward(b):
    if (b[2]==0):
        b[1]-=1
    if (b[2]==1):
        b[0]-=1
    if (b[2]==2):
        b[1]+=1
    if (b[2]==3):
        b[0]+=1
    return b

def make_area():
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    basa = [-1, -1, -1]
    zero = []
    data = deepcopy(d)
    i = 0
    while (i<n):
        par.append(deepcopy(zero))
        data.append(deepcopy(zero))
        used.append(deepcopy(zero))
        j = 0
        while (j<n):
            par[i].append(deepcopy(zero))
            data[i].append(deepcopy(zero))
            used[i].append(deepcopy(zero))
            k = 0
            while (k<4):
                data[i][j].append(0)
                used[i][j].append(0)
                k+=1
                par[i][j].append(deepcopy(basa))
            j+=1
        i+=1
    ugol2 = translater(ugol)
    data[x1][y1][ugol2] = 0
    q = [[x1, y1, ugol2]]
    used[x1][y1][ugol2] += 1
    d = deepcopy(data)

def go_operation1(p):
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    used[p[0]][p[1]][(p[2] + 1) % 4] = 1
    d[p[0]][p[1]][(p[2] + 1) % 4] = d[p[0]][p[1]][p[2]]
    d[p[0]][p[1]][(p[2] + 1) % 4] += 1
    par[p[0]][p[1]][(p[2] + 1) % 4] = deepcopy(p)
    q.append(deepcopy([p[0], p[1], (p[2] + 1) % 4]))
    
def go_operation2(p):
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    used[p[0]][p[1]][(p[2] + 3) % 4] = 1
    d[p[0]][p[1]][(p[2] + 3) % 4] = d[p[0]][p[1]][p[2]]
    d[p[0]][p[1]][(p[2] + 3) % 4] += 1
    par[p[0]][p[1]][(p[2] + 3) % 4] = deepcopy(p)
    q.append(deepcopy([p[0], p[1], (p[2] + 3) % 4]))
    
def go_operation3(p,nt):
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    used[nt[0]][nt[1]][nt[2]] = 1
    d[nt[0]][nt[1]][nt[2]] = d[p[0]][p[1]][p[2]]
    d[nt[0]][nt[1]][nt[2]]+=1
    par[nt[0]][nt[1]][nt[2]] = deepcopy(p)
    q.append(deepcopy(nt))
    
def go_operation4(p, nt):
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    k = 0
    while (k<4):
        mn = min(mn, d[x0][y0][k])
        k+=1
    k = 0
    while (k<4):
        if (d[x0][y0][k]==mn):
            now = [x0, y0, k]
            break
        k+=1

def go_operation():
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    while (len(q)>0):
        p = q[0]
        del q[0]
        if (blocked[p[1]][p[0]]==1):
            continue
        if (used[p[0]][p[1]][(p[2]+1)%4]==0):
            go_operation1(p)
        if (used[p[0]][p[1]][(p[2]+3)%4]==0):
            go_operation2(p)
        nt = forward(deepcopy(p))
        if (n>nt[0]>=0 and n>nt[1]>=0 and used[nt[0]][nt[1]][nt[2]]==0):
            go_operation3(p,nt)
    go_operation4(p, nt)

def make_answer():
    global blocked, d, used, par, ans, now, n, ugol, x1, y1, x0, y0, q, mn
    answer = []
    while (par[now[0]][now[1]][now[2]][2]!=-1):
        p = deepcopy(par[now[0]][now[1]][now[2]])
        nn = 2
        if (now[nn]==p[nn]):
            answer.append('F')
        elif (now[nn]==(p[nn]+1)%4):
            answer.append('L')
        else:
            answer.append('R')
        now = p
    ans = deepcopy(answer)

def main():
    read_data()
    make_area()
    go_operation()
    make_answer()
    print_answer()

main()

'''
6 U 5 2 2 2
0 0 1 0 0 0
0 1 0 0 1 0
0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

FFLFFLFRFLF

=================

7 R 3 5 6 1
0 0 0 0 0 0 0 
0 0 1 1 1 0 0 
0 1 0 0 0 1 0 
0 0 1 0 0 0 0 
0 0 0 1 1 0 0 
0 1 1 0 0 0 0 
0 0 1 0 0 1 0

FFFLFFFF
'''
