import math

def go_operation(L, x0, y0, fi0, v, w, Q0, t):
    #global L
    fi_t = -fi0+w*t
    R_t = L/(2*math.sin(fi_t))
    W_t= v/R_t
    x_c_t = x0+R_t*math.sin(Q0+fi_t)
    y_c_t = y0-R_t*math.cos(Q0+fi_t)
    x_t = x_c_t+R_t*math.sin(t*W_t-(Q0+fi_t))
    y_t = y_c_t+R_t*math.cos(t*W_t-(Q0+fi_t))
    print(x_t, y_t)