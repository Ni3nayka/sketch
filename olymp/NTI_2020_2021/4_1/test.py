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
 
# функции
def analogRead(n): # a = robot.analogRead(A1)
  return int(brick.sensor(n).read())

def delay(t):
    time.sleep(t/1000)
    #script.wait(1000)
    
def end():
  brick.stop()
  
def millis():
  return script.time()#*1000
  
### MAIN ##################################################################################################
  
  
#def main():

l_motor = motor(4)
r_motor = motor(3)

t = millis()
print(t)
while (t+2000>millis()):
  l_motor.start(100)
  r_motor.start(50)
t = millis()
print(t)
while (t+2000>millis()):
  l_motor.start(50)
  r_motor.start(100)

while (0):
  #e = (analogRead(D1)-40)*1.6
  e = (analogRead(D1)-45)*1.6
  #if ()
  #print(brick.accelerometer().read())
  l_motor.start(100-e)
  r_motor.start(100+e)
    

#if __name__ == '__main__':
#  main()

end()
