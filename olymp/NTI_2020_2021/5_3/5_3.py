import math                  # https://pythonworld.ru/moduli/modul-math.html
from copy import deepcopy
#from test import *

PI = math.pi

### input ###############################################################

L = 2.7 # длинна тележки
#x0, y0, Q0, f, dt, N = map(float, input().split())
#N = int(N)
#input_data = []
#for i in range (N):
#    a, b = map(float, input().split())
#    input_data.append(deepcopy([a,b]))

 # тест для первой задачи, для реальной работы эти две строки комментируются, а предыдущие 6 раскомментируются
x0, y0, Q0, f, dt, N = -0.253, -89.497, -2.201, 0.422, 37.0, 6
input_data = [[36.0, -0.033], [17.0, -0.03], [-23.0, 0.058], [11.0, 0.299], [-29.0, 0.188], [0.0, 0.0]]
    
if (0):
    print(x0, y0, Q0, f, dt, N)
    for i in range (N):
        print(input_data[i])
    print("=====")
    
Q_nast = Q0
x_nast = x0
y_nast = y0
#f_nast
t_nast = 0

    
### function ###############################################################

def test_data():
    global PI, Q_nast, f
    if (Q_nast<(-PI)):
        Q_nast+=2*PI
    if (Q_nast>=PI):
        Q_nast-=2*PI
    if (f<(-PI/6)):
        f = -PI/6
    if (f>(PI/6)):
        f = PI/6
    
def print_data():
    print("x =", x_nast, "  y =", y_nast, "  Q =", Q_nast, "  f =", f, "  t =", t_nast)

def go_operation(x0, y0, fi0, v, w, Q0):
    global L, dt, t_nast
    t_nast += dt
    t = dt
    fi_t = -fi0+w*t
    R_t = L/(2*math.sin(fi_t))
    W_t= v/R_t
    x_c_t = x0+R_t*math.sin(Q0+fi_t)
    y_c_t = y0-R_t*math.cos(Q0+fi_t)
    x_t = x_c_t+R_t*math.sin(t*W_t-(Q0+fi_t))
    y_t = y_c_t+R_t*math.cos(t*W_t-(Q0+fi_t))
    #print(x_t, y_t)
    Q_new = 0 # <========================================== ???????????????
    return [x_t, y_t, fi_t, Q_new]

### main ###############################################################


#test_data()
print_data()
print("=====")
for i in range (N):
    v_nast = input_data[i][0]
    w_nast = input_data[i][1]
    mas = go_operation(x_nast, y_nast, f, v_nast, w_nast, Q_nast)
    x_nast = mas[0]
    y_nast = mas[1]
    f = mas[2]
    Q_nast = mas[3]
    print_data()


















