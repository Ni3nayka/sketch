'''
from tkinter import *
from random import * # x0 = randint(0, 100)
from copy import deepcopy 
import time
from time import sleep
from time import time
Time = int(time()*1000)
ras = 50
import os.path # для определения наличия файла
import webbrowser


from arduino_function import *

arduino_function_version("1.2+") # test version

end_program_time()

if (arduino_function_version()!="1.2"):
    print("<arduino_function> have more version!!!")
'''

from time import sleep
from time import time
import datetime
from copy import deepcopy
from math import gcd # для простых дробей

PI = 3.141592653589793

def arduino_function_version(S=0):
    version = "1.3"
    if (S==0):
        return version
    if (S==version):
        return 1
    else:
        print("<arduino_function> have more version!!!")
        return 0
        
def input_int(S=0):
    a = 0
    while (a==0):
        a = input(S)
        if (a.isdigit()):
            return int(a)
        else:
            a = 0
   
def input_float(S=0):
    def is_digit(string):
        if string.isdigit():
           return True
        else:
            try:
                float(string)
                return True
            except ValueError:
                return False
    a = 0
    while (a==0):
        a = input(S)
        if (is_digit(a)):
            return int(a)
        else:
            a = 0
            

        
def delay(t):
    sleep(t/1000)
    
def millis():
    return int(time()*1000)

def map_a(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
    
def znak(a):
    if   (a > 0):
        return  1
    elif (a < 0):
        return -1
    else:
        return  0
    
def print_mas(mas):
    for i in range(len(mas)):
        print(mas[i])
        
def available(mas):
    return int(sum(mas)/len(mas))

def min_index(mas):
    return mas.index(min(mas))

def max_index(mas):
    return mas.index(max(mas))

class timer():
    
    def __init__(self):
        self.t_stop = 0
        self.t_start = time()
        
    def start(self):
        self.t_stop = 0
        self.t_start = time()
        
    def stop(self):
        self.t_stop = time()
        return (int(self.t_stop*1000)-int(self.t_start*1000))/1000
    
    def result(self):
        if (self.t_stop>0):
            return (int(self.t_stop*1000)-int(self.t_start*1000))/1000
        else:
            return (int(time()*1000)-int(self.t_start*1000))/1000
        
    def accurate_result(self):
        if (self.t_stop>0):
            return self.t_stop-self.t_start
        else:
            return time()-self.t_start
        
def convert_CC(num, to_base=10, from_base=10):
    # first convert to decimal number
    if isinstance(num, str):
        n = int(num, from_base)
    else:
        n = int(num)
    # now convert decimal to 'to_base' base
    alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if n < to_base:
        return alphabet[n]
    else:
        return convert_base(n // to_base, to_base) + alphabet[n % to_base]
    
def rounding(a, b):
    return int(a*10**b)/10**b

def fraction(n1,d1,n2,d2): # сложение простых дробей: n - числитель d - знаменатель
    '''
    input:
    1/3
    2/5
    output:
    11/15
    '''
    #n1, d1 = map(int, input().split('/')) 
    #n2, d2 = map(int, input().split('/'))
    cd = int(d1*d2/gcd(d1, d2))
    rn = int(cd/d1*n1+cd/d2*n2)
    g2 = gcd(rn, cd)
    n = int(rn/g2)
    d = int(cd/g2)
    #print('{}/{}'.format(n, d) if n != d else n)
    return [n,d]

elementary_timer = timer()
def end_program_time():
    print("время выполнения программы (сек):", elementary_timer.stop())


#if __name__ == "__main__":
#    pass
    
