import numpy as np
from copy import deepcopy
import os.path
from time import time
from copy import deepcopy
import sys
sys.setrecursionlimit(999999)

#from test_trinter import *

FILE = 0
file_name = "01.txt"
black_K = 10 # со скольки пикселей засчитывать


file = 0
img = []

def millis():
    return int(time()*1000)

def map_a(x,in_min,in_max,out_min,out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)

def filtr1(a):
    K = 50 # 30
    if (a[0]<=K and a[1]<=K and a[2]<=K):
        return 1
    return 0

def filtr(ot, do, a):
    #if (a[0]<=K and a[1]<=K and a[2]<=K):
    #    return 1
    ot = list(ot)
    do = list(do)
    a  = list(a)
    flag = 1
    for i in range (len(a)):
        if (ot[i]<=a[i]<=do[i]):
            pass
        else:
            flag = 0
    return flag

def read_line(S):
    mas = []
    for i in range(160):
        mas.append(0)
    S = list(S)
    #print(S)
    array = "0123456789abcdef"
    array = list(array)
    i = len(S)-2
    I = 160-1
    while (i>=0):
        # a = a*16+array.index(S[i])
        a = [0,0,0]
        if (S[i]!=' '):
            a[0]+=array.index(S[i])
            i-=1
        if (S[i]!=' '):
            a[0]+=array.index(S[i])*16
            i-=1
        if (S[i]!=' '):
            a[1]+=array.index(S[i])#*256
            i-=1
        if (S[i]!=' '):
            a[1]+=array.index(S[i])*16#4096
            i-=1
        if (S[i]!=' '):
            a[2]+=array.index(S[i])#*65536
            i-=1
        if (S[i]!=' '):
            a[2]+=array.index(S[i])*16#1048576
            i-=1
        #for r in range (len(a)):
        #    a[r] = array[int(a[r]/16)]
        if (a!=0):
            #mas[I] = deepcopy(filtr1(a))
            #mas[I] = deepcopy(str(str(a[0])+str(a[1])+str(a[2])))
            b = ""
            for c in range (len(a)):
                b += str(array[map_a(a[c],0,255,0,15)])
            mas[I] = deepcopy(b)
        I-=1
        i-=1
    #print(mas)
    return(mas)

def read_data():
    global file
    if (FILE):
        return file.readline()
    else:
        #return sys.stdin.read()
        a = input().split()
        #print(len(a))
        b = ""
        for i in range (len(a)):
            b+=str(a[i])
            b+=" "
        #print(b)
        return b
    #a= [int(i) for i in input()]
    #a= [int(i) for i in input().split]

timer = millis()

if (FILE):
    file = open(file_name)
#S = sys.stdin.read() # пропускаем первую строчку
#print(S)
i = 0
while (i<120):
    img.append(deepcopy(read_line(read_data())))
    #print(i)
    i+=1

if (FILE):
    file.close()

# test
'''
for i in range (len(img)):
    S = deepcopy(img[i])
    img[i].clear()
    a = 91
    for u in range (160-a):
        img[i].append("aaa")
    for u in range (a):
        img[i].append(S[u])
print(len(img[0]))
for i in range (len(img)):
    S = deepcopy(img[i])
    img[i].clear()
    a = 73
    for u in range (a,160):
        img[i].append(S[u])
    for u in range (a):
        img[i].append("aaa")
print(len(img[0]))
'''



#print(img)
#print(len(img))
#print(len(img[0]))
img_black = deepcopy(img)
img_brown = deepcopy(img)
img_blue  = deepcopy(img)

#print(img[75][43])

for i in range(len(img)):
    for u in range (len(img[i])):
        img_black[i][u] = deepcopy(filtr("000","222",img_black[i][u]))

for i in range(len(img)):
    for u in range (len(img[i])):
        img_brown[i][u] = deepcopy(filtr("431","653",img_brown[i][u]))

for i in range(len(img)):
    for u in range (len(img[i])):
        img_blue[i][u] = deepcopy(filtr("477","699",img_blue[i][u]))

#window_output(img_black, img_black)

if (0):
    file_name_2 = "qwerty.txt"
    file = open(file_name_2, 'w')
    for i in range (120):
        for u in range (160):
            file.write(str(img[i][u]))
        file.write("\n")
    file.close()
    #file = open("BARS_protocol.txt", 'r+')

#print(img)
img_label = []
grani = [0,0,0,0]

i = 0
while (i<120 and grani[1]==0):
    if (sum(img_black[i])>black_K):
        grani[1] = i
    i+=1

i = 120-1
while (i>=0 and grani[3]==0):
    if (sum(img_black[i])>black_K):
        grani[3] = i
    i-=1

i = 0
while (i<160 and grani[0]==0):
    summa = 0
    for u in range(120):
        summa+=img_black[u][i]
    if (summa>black_K):
        grani[0] = i
    i+=1

i = 160-1
while (i>=0 and grani[2]==0):
    summa = 0
    for u in range(120):
        summa+=img_black[u][i]
    if (summa>black_K):
        grani[2] = i
    i-=1

#print(grani)
sum_brown = 0
sum_blue  = 0
for i in range (len(img_brown)):
    sum_brown += sum(img_brown[i])
for i in range (len(img_blue)):
    sum_blue += sum(img_blue[i])

if (sum(grani)>0 and abs((abs(grani[0]-grani[2])/abs(grani[1]-grani[3])))>7/10):
    #print("YES")
    #img1 = []
    for i in range (grani[1],grani[3]):
        img_label.append([])
        for u in range (grani[0],grani[2]):
            img_label[len(img_label)-1].append(img_black[i][u])
    #print(img_label)
    for i in range (len(img_label)):
        for u in range (len(img_label[i])):
            if (img_label[i][u]):
                img_label[i][u] = 0
            else:
                img_label[i][u] = 1
    D = abs(grani[1]-grani[3])
    if (abs((abs(grani[0]-grani[2])/abs(grani[1]-grani[3])))>9/10):
        print(img_label[int(D/10*3)][int(D/2)]+img_label[int(D/2)][int(D/10*3)]*2+img_label[int(D/2)][int(D/10*7)]*4+img_label[int(D/10*7)][int(D/2)]*8)
    else:
        print("<>")
        #DD = 0
        #print(img_label[int(D/10*3)][int(D/2+DD)]+img_label[int(D/2)][int(D/10*3+DD)]*2+img_label[int(D/2)][int(D/10*7+DD)]*4+img_label[int(D/10*7)][int(D/2+DD)]*8)
        #DD = D*abs(abs(grani[0]-grani[2])/abs(grani[1]-grani[3])-1)
        if (sum_brown>sum_blue):
            #print("L")
            DD = D - abs(grani[0]-grani[2])
            print(img_label[int(D/10*3)][int(D/2-DD)]+img_label[int(D/2)][int(D/10*3-DD)]*2+img_label[int(D/2)][int(D/10*7-DD)]*4+img_label[int(D/10*7)][int(D/2-DD)]*8)
        else:
            #print("R")
            print(img_label[int(D/10*3)][int(D/2)]+img_label[int(D/2)][int(D/10*3)]*2+img_label[int(D/2)][len(img_label[0])-1]*4+img_label[int(D/10*7)][int(D/2)]*8)
            
    #print(D)
    #print(img_label[int(D/10*3)][int(D/2)])
elif (sum_brown>sum_blue):
    print("L")
else:
    print("R")


'''
elif (sum(grani)>0 and abs((abs(grani[0]-grani[2])/abs(grani[1]-grani[3]))-1)<0.3 ):
    #print("!!!")
    for i in range (grani[1],grani[3]):
        img_label.append([])
        for u in range (grani[0]+abs(int((grani[0]-grani[2])/2)),grani[2]):
            img_label[len(img_label)-1].append(img_black[i][u])
    D = abs(grani[1]-grani[3])
    D1 = abs(grani[0]-grani[2])
    D1 = D1//2
    for i in range (len(img_label)):
        for u in range (len(img_label[i])):
            if (img_label[i][u]):
                img_label[i][u] = 0
            else:
                img_label[i][u] = 1
    if (sum_brown>sum_blue):
        nechetnoe = 1
        if (img_label[int(D/2)][int(D/15*7)]):
            nechetnoe = 0
        #print("n", nechetnoe)
        #print(img_label[int(D/10*3)][int(D/15*7)],img_label[int(D/2)][int(D/10*3)],img_label[int(D/10*7)][int(D/15*7)])
        n1 = img_label[int(D/10*3)][int(D/15*7)]+img_label[int(D/2)][int(D/10*3)]*2+1*4+img_label[int(D/10*7)][int(D/15*7)]*8
        n2 = img_label[int(D/10*3)][int(D/15*7)]+img_label[int(D/2)][int(D/10*3)]*2+0*4+img_label[int(D/10*7)][int(D/15*7)]*8
        #print(n1, n2)
        if (n1%2==n2%2):
            print("L")
        elif (n1%2==nechetnoe):
            print(n1)
        else:
            print(n2)
    else:
        print("R")
        nechetnoe = 1
        if (img_label[int(D/2)][int(D1-D/15*7)]):
            nechetnoe = 0
        #print("n", nechetnoe)
        #print(img_label[int(D/10*3)][int(D/15*7)],img_label[int(D/2)][int(D/10*3)],img_label[int(D/10*7)][int(D/15*7)])
        n1 = img_label[int(D/10*3)][int(D1-D/15*7)]+1*2+img_label[int(D/2)][int(D1-D/10*7)]*4+img_label[int(D/10*7)][int(D1-D/15*7)]*8
        n2 = img_label[int(D/10*3)][int(D1-D/15*7)]+0*2+img_label[int(D/2)][int(D1-D/10*7)]*4+img_label[int(D/10*7)][int(D1-D/15*7)]*8
        print(n1, n2)
        if (n1%2==n2%2):
            print("R")
        elif (n1%2==nechetnoe):
            print(n1)
        else:
            print(n2)
'''

#print("time:",(millis()-timer)/1000)


#window_output(img_black, img_label)
