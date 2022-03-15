import sys
import time
import random
import math

lang = 0

def millis():
  return int(time.time()*1000)

def main():
  global lang

  pi = 3.141592653589793

  #lang = 0
  #############################################################
  def f_left():
    global lang
    script.wait(10)
  
    brick.encoder(E3).reset()
    
    brick.motor("M4").setPower(-(100))
    
    brick.motor("M3").setPower(100)
    
    while not (brick.encoder("E3").read() >= 240):
      script.wait(10)
    
    brick.motor("M1").powerOff()
    brick.motor("M2").powerOff()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
    
  #############################################################
  def f_right():
    global lang
    script.wait(10)
    
    brick.encoder(E4).reset()
    
    brick.motor("M4").setPower(100)
    
    brick.motor("M3").setPower(-(100))
    
    while not (brick.encoder("E4").read() >= 240):
      script.wait(10)
    
    brick.motor("M1").powerOff()
    brick.motor("M2").powerOff()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
   
  ############################################################# 
  def f_upor():
    global lang
    while (brick.sensor(D1).read() > 20):
      brick.motor("M4").setPower(100)
      brick.motor("M3").setPower(100)
      script.wait(10)
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
   
  ############################################################# 
  
  def test():
    global lang
    f_left()
    if lang < (brick.sensor(D1).read() + brick.sensor(D2).read()) and (brick.sensor(D1).read() < 250):
      lang = (brick.sensor(D1).read() + brick.sensor(D2).read())
    f_right()
   
  ############################################################# 
  def f_ride_start():
    global lang
    t = millis()
    D = 1500
    while (brick.sensor(D1).read() > 20): #  and t+10000>millis()
      input = int(brick.sensor(A2).read())
      t = millis()
      while t+D>millis() and brick.sensor(D1).read() > 20:
        e = (25 - brick.sensor(A2).read())*5
        brick.motor("M4").setPower(70-e)
        brick.motor("M3").setPower(70+e)
        
      if (brick.sensor(D1).read() > 20):
        test()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
    
  #############################################################   
  f_upor()
  f_left()
  for i in range(5):
    f_ride_start()
    f_left()
  print(lang)
  brick.display().addLabel(lang, 1, 1)
  brick.stop()
  

if __name__ == '__main__':
  main()

