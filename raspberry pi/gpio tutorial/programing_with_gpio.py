# https://kip-world.ru/pervoe-znakomstvo-s-gpio-v-raspberry-pi.html
# https://ph0en1x.net/86-raspberry-pi-znakomstvo-s-gpio-perekluchatel-i-svetodiod.html

# настройка
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.output(17, 0)
GPIO.setup(27, GPIO.IN)

I_STARTED = 0 # если 1, то стартует первая ЭТА разбери,
              # если 0, то первая должна запускатся ДРУГАЯ разбери

def main():
    # здесь (в этой функции) находится твоя прога
    
    print("Hello, world!") # просто для теста

# выполнение проги (приема\передачи) в цикле
while True:
    if (I_STARTED==0): # если первой стартует не ЭТА разбери или если старты уже были
        # ожидание сигнала о старте
        while (GPIO.input(27)==0):
            pass
        
        # приняли сигнал, ожидаем окончания
        while (GPIO.input(27)==1):
            pass
    else: # если ЭТА разбери стартует первая, то сразу переодим к выполнени проги
        I_STARTED = 0 # помечаем, чтобы в следуий раз ожидат ответного сигнала
    
    # выполняем действия
    main()
    
    GPIO.output(17, 1)  # отправляем сигнал об окончании
    time.sleep(1)       # ждем некоторое время (1 сек)
    GPIO.output(17, 0)  # перестаем отправлят сигнал
    
    
