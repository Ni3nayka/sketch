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
encoder_cm  = 155
encoder_360 = 988
encoder_90  = int(encoder_360/4)
    
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
    
  def read(self):
    n = str("M"+str(self.N))
    return brick.encoder(n).read()
    
  def clear(self):
    n = str("M"+str(self.N))
    brick.encoder(n).reset()
 
class timer():
  
  def __init__(self):
    self.t_stop = 0
    self.t_start = time.time()
      
  def start(self):
    self.t_stop = 0
    self.t_start = time.time()
      
  def stop(self):
    self.t_stop = time.time()
    return (int(self.t_stop*1000)-int(self.t_start*1000))/1000
  
  def result(self):
    if (self.t_stop>0):
      return (int(self.t_stop*1000)-int(self.t_start*1000))/1000
    else:
      return (int(time.time()*1000)-int(self.t_start*1000))/1000
      
  def accurate_result(self):
    if (self.t_stop>0):
      return self.t_stop-self.t_start
    else:
      return time.time()-self.t_start
 
# функции
def analogRead(n): # a = robot.analogRead(A1)
  return int(brick.sensor(n).read())

def delay(t):
    time.sleep(t/1000)
    #script.wait(1000)
    
def end():
  brick.stop()
  
### MAIN ##################################################################################################
  
l_motor = motor(4)
r_motor = motor(3)
  
def right():
  global l_motor, r_motor 
  l_motor.clear()
  r_motor.clear()
  l_motor.start(50)
  r_motor.start(-50)
  while (r_motor.read()>-encoder_90):
    pass
  l_motor.stop()
  r_motor.stop()
    
def left():
  global l_motor, r_motor
  l_motor.clear()
  r_motor.clear()
  l_motor.start(-50)
  r_motor.start(50)
  while (l_motor.read()>-encoder_90):
    pass
  l_motor.stop()
  r_motor.stop()
 
millis = timer()
 
def emergency_exit_time():
  global millis
  if (millis.result()>210):
    brick.display().addLabel("106", 1, 1)


'''
rast  = 20 # мм боковой датчик до стены
rast1 = 15 # 5 # передний датчик до стены
rast2 = 8.75 #(70-rast/5)//16 # см
rast3 = 65 # макс раст реагир датчика ИК
'''

rast  = 30 # мм боковой датчик до стены
rast1 = 25 # 5 # передний датчик до стены
rast2 = 8.75 #(70-rast/5)//16 # см
rast3 = 65 # макс раст реагир датчика ИК

#for i in range (4):
#  left()

#brick.say("9")

#brick.display().addLabel('9',0,0)
if (1):
  a = str(int(10*((int(time.time()*1000000000)**2)%19+1))+1)
  print(a)
  brick.display().addLabel(a, 1, 1)
#print(analogRead(A1)<rast3)
#brick.display().addLabel("137", 1, 1)

if (1):
  min = 9999
  
  while (analogRead(D1)>rast1):
    l_motor.start(100)
    r_motor.start(100)
    delay(10)
    emergency_exit_time()
    
  left()
  
  flag = 1 # 1 - небыло куба для ИК, 0 - был куб для ИК
  
  for i in range (5):
    emergency_exit_time()
    
    while (analogRead(D1)>rast1):
      emergency_exit_time()
      l_motor.clear()
      r_motor.clear()
      while (l_motor.read()<encoder_cm*rast2 and analogRead(D1)>rast1):
        e = (analogRead(A2)-rast)*15
        l_motor.start(80+e)
        r_motor.start(80-e)
        delay(10)
        emergency_exit_time()
      #print(l_motor.read(), end='')
      if (analogRead(D1)>rast1):
        if (analogRead(A1)<rast3):
          a = analogRead(A1)+10
          if (a<min):
            min = a
          flag = 0
        elif (flag):
          left()
          #delay(1000)
          a = analogRead(D1)+7
          if (a<min):
            min = a
          #print(analogRead(D1))
          right()
      
    left()
  min+=rast
  print(min)
  brick.display().addLabel(min, 1, 1)
 
#  print(brick.accelerometer().read()) # gyroscope

while (0):
  #e = (analogRead(D1)-45)*1.6
  #if ()
  print(brick.accelerometer().read())
  delay(1000)
  if (0):
    e = brick.accelerometer().read()
    e = int(e[0])*0.1
    #print(e)
    l_motor.start(50-e)
    r_motor.start(50+e)
    

#if __name__ == '__main__':
#  main()

end()
