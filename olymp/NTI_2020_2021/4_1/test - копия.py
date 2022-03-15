### SETUP #################################################################################################

# библиотеки
import sys
import time
import random
import math

# константы
white_IK = 20 # ИК белое
black_IK = 70 # ИК черное
PI = 3.141592653589793
    
# классы
class motor():
  
  def __init__(self,n):
    self.N = n
    
  def start(self,speed): # motor(1, 100)
    n = str("M"+str(self.N))
    if (speed==0):
      brick.motor(n).powerOff()
    else:
      brick.motor(n).setPower(speed)   
      
  def stop(self):
    n = str("M"+str(self.N))
    brick.motor(n).powerOff()
    
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
    
#class ROBOT():
#  
#  def __init__(self,n):
#    self.N = n
    
# функции
def analogRead(n): # a = robot.analogRead(A1)
  return int(brick.sensor(n).read())

def delay(t):
    time.sleep(t/1000)
    #script.wait(1000)
    
def millis():
  return int(time.time()*1000)

def map_a(x, in_min, in_max, out_min, out_max):
  return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
  
def end():
  brick.stop()
  
# другие классы:
'''
https://help.trikset.com/trik/programming-code/object-brick

brick.accelerometer();
brick.battery();
brick.colorSensor("video1")
brick.display()
brick.encoder(portName) # brick.encoder("portName") # brick.encoder(E1)
brick.gyroscope()
brick.keys()
brick.led()
brick.lineSensor("video1")
brick.objectSensor()
brick.playTone(frequency, time)
brick.say("Привет, я ТРИК")
brick.marker()
brick.stop()
brick.motor(motorName) # M1
brick.sensor(portName) # A1
'''
  
### MAIN ##################################################################################################
  
  
def main():
  l_motor = motor(4)
  r_motor = motor(3)
  '''
  #L = 1
  #R = 2
  #print()
  while (1):
    e = (analogRead(D1)-40)*1.5
    l_motor.start(100-e)
    r_motor.start(100+e)
  '''
  while (true):
#if (brick.sensor(D1).read() > 35):
if (1):
r_motor.start(100)
l_motor.start(-100)
delay(30)
l_motor.start(100)
r_motor.start(100)
delay(100)
#else:
l_motor.start(100)
r_motor.start(-100)
delay(30)
l_motor.start(100)
r_motor.start(100)
delay(100)
    

if __name__ == '__main__':
  main()
  end()
