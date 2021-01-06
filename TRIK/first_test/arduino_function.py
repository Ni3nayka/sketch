from time import sleep
from time import time

PI = 3.141592653589793

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
        print(mas)
        
class timer():
    
    def __init__(self):
        self.t_start = 0
        self.t_stop = 0
        
    def start(self):
        self.t_start = int(time()*1000)
        
    def stop(self):
        self.t_stop = int(time()*1000)
        return (self.t_stop-self.t_start)/1000
    
    def result(self):
        return (self.t_stop-self.t_start)/1000
        
    
