import math
from copy import deepcopy

def ygol(c, d):
    return [c[0]*math.cos(d) - c[1]*math.sin(d),c[0]*math.sin(d) + c[1]*math.cos(d)]

def rast(a, b):
    return ((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]))**(1/2)

def vector(a, b):
    return a[0]*b[1]-a[1]*b[0]

def rrry(a, b):
    return a[0]*b[0]+a[1]*b[1]

def qwerty(y):
    return [y[0]/(y[0]*y[0]+y[1]*y[1])**0.5,y[1]/(y[0]*y[0]+y[1]*y[1])**0.5]

def dfrbe(a, b):
    return [a[0]-b[0],a[1]-b[1]]

def ygol_2(a, b):
    if (vector(a, b)<0):
        return(-1)*math.acos(rrry(a, b)/(a[0]*a[0]+a[1]*a[1])**0.5/(b[0]*b[0]+b[1] *b[1])**0.5)
    return math.acos(rrry(a, b)/(a[0]*a[0]+a[1]*a[1])**0.5/(b[0]*b[0]+b[1] *b[1])**0.5)

def basa():
    return [0,0]

awrgv = basa()
bvbar = basa()
egw = basa()
rrt = basa()
awrgv[0], bvbar[0], awrgv[1], bvbar[1] = map(float, input().split())
egw[0], egw[1] = map(float, input().split())
rrt[0], rrt[1] = map(float, input().split())
shbs1 = 2*(10**(-7))
shb = (10**(-5))
shbs2 = 1/100
sgvkj = awrgv[0]
day = math.sqrt(rrt[0]*rrt[0]+rrt[1]*rrt[1])

while (sgvkj<=bvbar[0]):
    var=basa()
    var[0]=egw[0]
    var[1]=0
    var=ygol(var,sgvkj)
    if (abs(rast(var,rrt)-egw[1])>day/80):
        sgvkj+=shb
        continue
    if (abs(rast(var,rrt)-egw[1])<=shbs2):
        rrt1=dfrbe(rrt,var)
        rrt1=qwerty(rrt1)
        var=qwerty(var)
        var[0],var[1]=-var[0],-var[1]
        over=ygol_2(var,rrt1)
        if (over<0):
            over+=2*math.pi
        if (awrgv[1]<over<bvbar[1]):
            print(sgvkj,end=' ')
            print(over)
            exit()
    sgvkj+=shbs1
print("-1")

