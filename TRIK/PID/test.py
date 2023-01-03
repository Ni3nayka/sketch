##########################################################################################################
# SETUP

import sys
import time
import random
import math

PI = 3.141592653589793

def delay(t):
    time.sleep(t/1000)
    #script.wait(1000)
    
def millis():
  return int(time.time()*1000)

def map_a(x, in_min, in_max, out_min, out_max):
  return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
  
def analogRead(n):
  return int(brick.sensor(n).read())

def motor(n, speed):
  #brick.motor("M1").powerOff()
  #brick.motor("M3").setPower(100)
  #brick.motor("M4").setPower(100)
  if (speed==0):
    brick.motor(n).powerOff()
  else:
    brick.motor(n).setPower(speed)
  
def end():
  brick.stop()
  
##########################################################################################################
# main

class Program():
  #__interpretation_started_timestamp__ = time.time() * 1000

  pi = 3.141592653589793

  def execMain(self):
    brick.motor("M1").powerOff()
    brick.motor("M2").powerOff()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
    
    brick.stop()
    return

def main():
  t = millis()
  #print(analogRead(A1))
  k = 2.5
  e_old = 0
  P = 0
  D = 0
  I = 0
  while(t+30000>millis()):
    # черная линия
    e = analogRead(A1) - analogRead(A2)
    
    # по стенке
    #e = analogRead(A1) - 25
    
    #print(e)
    
    P = e*2.5
    D = D + (e-e_old)*2
    I = (I + e)*0.7
    
    regulator = (P + D + I)/3
    print(regulator)
    motor("M1", 100-regulator)
    motor("M2", 100+regulator)
    e_old = e
  end()

if __name__ == '__main__':
  main()
