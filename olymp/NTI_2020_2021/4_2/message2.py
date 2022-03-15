import sys
import time
import random
import math

def millis():
  return int(time.time()*1000)
  
lang = 1000
tiiime = millis()

    
def escape():
  global tiiime
  if (tiiime+180000<millis()):
    brick.display().addLabel("105", 1, 1)


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
      escape()
    
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
      escape()
    
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
      escape()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
   
  ############################################################# 
  
  def test():
    global lang
    f_left()
    #print("test")
    script.wait(10)
    #print(lang)
    a = int(brick.sensor(D1).read()) + int(brick.sensor(D2).read())
    #print(a)
    if lang > a:
      lang = a
      #print(lang)
    script.wait(10)
    f_right()
    
  def bok_test():
    global lang
    a = brick.sensor(A1).read() + brick.sensor(A2).read()
    if lang > a:
      lang = a
    
   
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
        escape()
      escape()
      if (brick.sensor(D1).read() > 20):
        if (brick.sensor(A1).read()>20):
          test()
        else:
          bok_test()
    brick.motor("M3").powerOff()
    brick.motor("M4").powerOff()
    
  #############################################################   
  f_upor()
  f_left()
  for i in range(5):
    f_ride_start()
    f_left()
    escape()
  print(lang)
  brick.say(lang)
  brick.display().addLabel(lang, 1, 1)
  script.wait(10000)
  brick.stop()
  

if __name__ == '__main__':
  main()

