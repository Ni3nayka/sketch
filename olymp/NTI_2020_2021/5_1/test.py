import numpy as np
from copy import deepcopy
import os.path
from time import time
from copy import deepcopy
import sys
sys.setrecursionlimit(999999) 


img = []
color = [16777215]
color_object = []

def millis():
    return int(time()*1000)

def add_color(c):
    global color
    if (not (c in color)):
        color.append(c)
        #color[1].append(max(color[1])+1)
    return -color.index(c)

def read_line(S):
    mas = []
    for i in range(800):
        mas.append(0)
    S = list(S)
    #print(S)
    array = "0123456789abcdef"
    array = list(array)
    i = len(S)-2
    I = 800-1
    while (i>=0):
        # a = a*16+array.index(S[i])
        a = 0
        if (S[i]!=' '):
            a+=array.index(S[i])
            i-=1
        if (S[i]!=' '):
            a+=array.index(S[i])*16
            i-=1
        if (S[i]!=' '):
            a+=array.index(S[i])*256
            i-=1
        if (S[i]!=' '):
            a+=array.index(S[i])*4096
            i-=1
        if (S[i]!=' '):
            a+=array.index(S[i])*65536
            i-=1
        if (S[i]!=' '):
            a+=array.index(S[i])*1048576
            i-=1
        if (a!=0):
          mas[I] = add_color(a)
        I-=1
        i-=1
    return(mas)

def add_object(color):
    global color_object
    color = abs(color)
    if (not (color in color_object)):
        color_object.append(color)
        return color
    else:
        return add_object(color+1)

def my_object(y1,x1,color1, start_color1):
    global img
    x = deepcopy(x1)
    y = deepcopy(y1)
    color = deepcopy(color1)
    c = deepcopy(start_color1)
    #c = deepcopy(img[y][x])
    if (img[y][x]==c):
        img[y][x] = deepcopy(color)
        #if (y%10==0):
        #    print(y,x,color)
        if (x>0 and 1): # left
            #if (img[y][x-1]==c):
            my_object(y,x-1,color,c)
        if (x<799 and 1): # right
            #if (img[y][x+1]==c):
            my_object(y,x+1,color,c)
        if (y>0 and 1): # up
            #if (img[y-1][x]==c):
            my_object(y-1,x,color,c)
        if (y<599 and 1): # down
            #if (img[y+1][x]==c):
            #print(y,x,color)
            my_object(y+1,x,color,c)
        
    

timer = millis()
#a= [int(i) for i in input()]
#a= [int(i) for i in input().split]
S = sys.stdin.read() # пропускаем первую строчку
#print(S)
i = 0
while (i<600):
    if (i==0 and len(S)>20):
        img.append(deepcopy(read_line(S)))
        i+=1
    S = sys.stdin.read()
    img.append(deepcopy(read_line(S)))
    #print(i)
    i+=1
file.close()

#print("===========") # вывести размеры картинки
#print((millis()-timer)/1000)
#print(len(img))
#print(len(img[0]))
#print("===========")
#print(img[0])
#print()
#print("===========")
#####################################

#timer = millis()
for i in range (len(img)):
    for u in range (len(img[i])):
        if (img[i][u]<0): # есть цветовое пятно
            #print(i,u,img[i][u],"start")
            my_object(i,u,add_object(img[i][u]), img[i][u])
            #print(i,u,img[i][u],"end")
#print((millis()-timer)/1000)
#print(img[360])
#print()
#print(img[484])
#print()
color = deepcopy(color_object)

check = []
ch = 0
p = [0] * (len(color))
for num in range(len(color)):
  check.clear()
  for stroka in range(599):
   for stolb in range(799):
     if img[stroka][stolb] == num:


      if img[stroka-1][stolb] != img[stroka][stolb]:

        for i in range(len(check)):
          if  str((stroka-1)*1000)+str(stolb)== check[i]:
            ch += 1

        if ch == 0:
          check.append(str((stroka-1)*1000)+str(stolb))
          p[num] += 1
        ch = 0


      if img[stroka+1][stolb] != img[stroka][stolb]:

        for i in range(len(check)):
          if  str((stroka+1)*1000)+str(stolb)== check[i]:
            ch += 1

        if ch == 0:
          check.append(str((stroka+1)*1000)+str(stolb))
          p[num] += 1
        ch = 0


      if img[stroka][stolb-1] != img[stroka][stolb]:

        for i in range(len(check)):
          if  int(str(stroka*1000)+str(stolb-1))== check[i]:
            ch += 1

        if ch == 0:
          check.append(str(stroka*1000)+str(stolb-1))
          p[num] += 1
        ch = 0

      if img[stroka][stolb+1] != img[stroka][stolb]:

        for i in range(len(check)):
          if  str(stroka*1000)+str(stolb+1)== check[i]:
            ch += 1

        if ch == 0:
          check.append(str(stroka*1000)+str(stolb+1))
          p[num] += 1
        ch = 0


F = 0
p[0] = 0
 
for i in range(len(p)):
  if int(p[i]) > F:
    F = p[i]
print(F)
