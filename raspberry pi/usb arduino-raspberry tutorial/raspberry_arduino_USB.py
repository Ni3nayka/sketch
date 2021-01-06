'''
this program writing Bakay Egor, Moscow, Russia, 2020

info:
https://arduinoplus.ru/podkluchenie-raspberry-arduino/

commands:
from raspberry_arduino_USB import *
serial_read() # return String input
serial_write(String output)
'''

print("$ import <raspberry_arduino_UART> test: ", end='')

import serial

# ввести в терминал
# ls /dev/tty*
# Затем найдите строку с /dev/ttyACM0 или что-то вроде /dev/ttyACM1 и т.д. Проверьте ACM с любым числом 0,1,2 и т.д.

ser=serial.Serial("/dev/ttyUSB0",9600) 
ser.baudrate=9600

def serial_read():
    S = ser.readline()
    # b'1\r\n' => 1
    #print(S, " ", end='')
    # отрезаем "мусор"
    S = str(S)
    S = list(S)  # str => mas
    del S[0]
    del S[0]
    del S[len(S)-1]
    del S[len(S)-1]
    del S[len(S)-1]
    del S[len(S)-1]
    del S[len(S)-1]
    S = ''.join(S) # mas => str
    #print(S)
    return S
        
def serial_write(S):
    #ser.write(b'hello, arduino!!!\n') # \r
    S = str(S)
    S = list(S)  # str => mas
    i = 0
    while (i<len(S)):
        f = S[i]
        if (f == ' '):
            ser.write(b' ')
        if (f == 'a'):
            ser.write(b'a')
        if (f == 'b'):
            ser.write(b'b')
        if (f == 'c'):
            ser.write(b'c')
        if (f == 'd'):
            ser.write(b'd')
        if (f == 'e'):
            ser.write(b'e')
        if (f == 'f'):
            ser.write(b'f')
        if (f == 'g'):
            ser.write(b'g')
        if (f == 'h'):
            ser.write(b'h')
        if (f == 'i'):
            ser.write(b'i')
        if (f == 'j'):
            ser.write(b'j')
        if (f == 'k'):
            ser.write(b'k')
        if (f == 'l'):
            ser.write(b'l')
        if (f == 'm'):
            ser.write(b'm')
        if (f == 'n'):
            ser.write(b'n')
        if (f == 'o'):
            ser.write(b'o')
        if (f == 'p'):
            ser.write(b'p')
        if (f == 'q'):
            ser.write(b'q')
        if (f == 'r'):
            ser.write(b'r')
        if (f == 's'):
            ser.write(b's')
        if (f == 't'):
            ser.write(b't')
        if (f == 'u'):
            ser.write(b'u')
        if (f == 'v'):
            ser.write(b'v')
        if (f == 'w'):
            ser.write(b'w')
        if (f == 'x'):
            ser.write(b'x')
        if (f == 'y'):
            ser.write(b'y')
        if (f == 'z'):
            ser.write(b'z')
        if (f == 'A'):
            ser.write(b'A')
        if (f == 'B'):
            ser.write(b'B')
        if (f == 'C'):
            ser.write(b'C')
        if (f == 'D'):
            ser.write(b'D')
        if (f == 'E'):
            ser.write(b'E')
        if (f == 'F'):
            ser.write(b'F')
        if (f == 'G'):
            ser.write(b'G')
        if (f == 'H'):
            ser.write(b'H')
        if (f == 'I'):
            ser.write(b'I')
        if (f == 'J'):
            ser.write(b'J')
        if (f == 'K'):
            ser.write(b'K')
        if (f == 'L'):
            ser.write(b'L')
        if (f == 'M'):
            ser.write(b'M')
        if (f == 'N'):
            ser.write(b'N')
        if (f == 'O'):
            ser.write(b'O')
        if (f == 'P'):
            ser.write(b'P')
        if (f == 'Q'):
            ser.write(b'Q')
        if (f == 'R'):
            ser.write(b'R')
        if (f == 'S'):
            ser.write(b'S')
        if (f == 'T'): 
            ser.write(b'T')
        if (f == 'U'):
            ser.write(b'U')
        if (f == 'V'):
            ser.write(b'V')
        if (f == 'W'):
            ser.write(b'W')
        if (f == 'X'):
            ser.write(b'X')
        if (f == 'Y'):
            ser.write(b'Y')
        if (f == 'Z'):
            ser.write(b'Z')
        if (f == '1'):
            ser.write(b'1')
        if (f == '2'):
            ser.write(b'2')
        if (f == '3'):
            ser.write(b'3')
        if (f == '4'):
            ser.write(b'4')
        if (f == '5'):
            ser.write(b'5')
        if (f == '6'):
            ser.write(b'6')
        if (f == '7'):
            ser.write(b'7')
        if (f == '8'):
            ser.write(b'8')
        if (f == '9'):
            ser.write(b'9')
        if (f == '0'):
            ser.write(b'0')
        if (f == '.'):
            ser.write(b'.')
        if (f == ','):
            ser.write(b',')
        if (f == '!'):
            ser.write(b'!')
        if (f == '-'):
            ser.write(b'-')
        if (f == '='):
            ser.write(b'=')
        if (f == '+'):
            ser.write(b'+')
        if (f == '_'):
            ser.write(b'_')
        if (f == ':'):
            ser.write(b':')
        if (f == ';'):
            ser.write(b';')
        i += 1
    ser.write(b'\n') # \r 

print("successful")
