# https://kip-world.ru/pervoe-znakomstvo-s-gpio-v-raspberry-pi.html
# https://ph0en1x.net/86-raspberry-pi-znakomstvo-s-gpio-perekluchatel-i-svetodiod.html

import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(22, GPIO.IN)
while True:
    GPIO.output(17, 1)
    i = 0
    while (i<3):
        print(GPIO.input(22))
        time.sleep(0.5)
        i += 1
    
    GPIO.output(17, 0)
    i = 0
    while (i<3):
        print(GPIO.input(22))
        time.sleep(0.5)
        i += 1