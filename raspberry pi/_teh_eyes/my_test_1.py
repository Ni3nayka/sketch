import cv2
import numpy as np

import smbus
import time
import os

from time import sleep
from time import time

Time = time()
#print(time.ctime(Time))
print(Time)


bus = smbus.SMBus(1)
SLAVE_ADDRESS = 0x04

if __name__ == '__main__':
    def callback(*arg):
        print (arg)

cv2.namedWindow( "result" )

cap = cv2.VideoCapture(0)
hsv_min = np.array((30, 255, 0), np.uint8)
hsv_max = np.array((100, 255, 60), np.uint8)


color_yellow = (190, 220, 80)

camera_center_x = 333;
camera_center_y = 265;

camera_x = 0;
camera_y = 0;

angle_servo_1 = 0;
angle_servo_2 = 0;
speed_motor_1 = 0;
speed_motor_2 = 0;
speed_motor_3 = 0;
speed_motor_4 = 0;

encoder_1 = 0;
encoder_2 = 0;
encoder_3 = 0;
encoder_4 = 0;

def request_reading():
    global encoder_1;
    global encoder_2;
    global encoder_3;
    global encoder_4;
    d1  = int(bus.read_byte(SLAVE_ADDRESS));
    d2  = int(bus.read_byte(SLAVE_ADDRESS));
    d3  = int(bus.read_byte(SLAVE_ADDRESS));
    d4  = int(bus.read_byte(SLAVE_ADDRESS));
    d5  = int(bus.read_byte(SLAVE_ADDRESS));
    d6  = int(bus.read_byte(SLAVE_ADDRESS));
    d7  = int(bus.read_byte(SLAVE_ADDRESS));
    d8  = int(bus.read_byte(SLAVE_ADDRESS));
    d9  = int(bus.read_byte(SLAVE_ADDRESS));
    d10 = int(bus.read_byte(SLAVE_ADDRESS));
    d11 = int(bus.read_byte(SLAVE_ADDRESS));
    d12 = int(bus.read_byte(SLAVE_ADDRESS));
    encoder_1 = d1*256*256  + d2*256  + d3;
    encoder_2 = d4*256*256  + d5*256  + d6;
    encoder_3 = d7*256*256  + d8*256  + d9;
    encoder_4 = d10*256*256 + d11*256 + d12;
    print(encoder_1, " ", encoder_2, " ", encoder_3, " ", encoder_4);

def request_writing():
    #bus.write_byte(SLAVE_ADDRESS, ord('l'));
    a = input()
    if (a == 'r'):
        request_reading();
    elif (a == 'c'):
        bus.write_byte(SLAVE_ADDRESS, ord('c'));
        print("clean encoder");
    else:
        i = input();
        vvod(a, i);


def map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);

def cut(i, a):
    if (abs(i) > a):
        i = abs(i)/i*a;
        i = int(i);
    return i;

def vvod(a, i):
    i = int(i);
    a = int(a);
    if ((a > 0) and (a < 5)):
        i = cut(i, 100);
        print("motor: ", a, " speed: ", i);
        i = i + 100;
        bus.write_byte(SLAVE_ADDRESS, a);
        #sleep(0.1);
        bus.write_byte(SLAVE_ADDRESS, i);
        #sleep(0.1);
    elif ((a == 5) or (a == 6)):
        i = cut(i, 100);
        print("servo: ", a-4, " angle: ", i);
        i = i + 100;
        bus.write_byte(SLAVE_ADDRESS, a);
        #sleep(0.1);
        bus.write_byte(SLAVE_ADDRESS, i);
        #sleep(0.1);
    else :
        print("ERROR vvod");

def go(x, y):
    global Time;
    global camera_center_x;
    global camera_center_y;
    global camera_x;
    global camera_y;
    global angle_servo_1;
    global angle_servo_2;
    global speed_motor_1;
    global speed_motor_2;
    global speed_motor_3;
    global speed_motor_4;
    global encoder_1;
    global encoder_2;
    global encoder_3;
    global encoder_4;
#    camera_x = map(x, 0, 600, -100, 100)
#        camera_x = cut(camera_x, 100)
#        angle_servo = angle_servo + camera_x
#         if (abs(camera_x - angle_servo) > 10):
#             if (camera_x > angle_servo):
#                 angle_servo = angle_servo + 1
#             else:
#                 angle_servo = angle_servo - 1
#         angle_servo = cut(angle_servo, 100)
#         print(angle_servo)
#         vvod(5, angle_servo)
#        aaa = 0;
#
    if ((x == -1) and (y == -1)):
        vvod(1, 0);
        vvod(2, 0);
        vvod(3, 0);
        vvod(4, 0);
        #vvod(5, 0);
        #vvod(6, 0);
    else:
        camera_x = map(x, 0, 600, -100, 100)
        Time = time();
        if (abs(camera_x) > 20):
            aaa = 1;
            if (camera_x < 0):
                aaa = -1;
            aaa = aaa*10;
            angle_servo_1 = angle_servo_1 + aaa
            cut(angle_servo_1, 100);
            cut(angle_servo_1, 100);
            vvod(5, angle_servo_1);
#            vvod(1, -40*aaa);
#            vvod(2, -40*aaa);
#            vvod(3, 40*aaa);
#            vvod(4, 40*aaa);
        #else:
            #vvod(5, 0);
#            vvod(1, 0);
#            vvod(2, 0);
#            vvod(3, 0);
#            vvod(4, 0);

            
vvod(1, 0);
vvod(2, 0);
vvod(3, 0);
vvod(4, 0);
vvod(5, 0);
vvod(6, 0);
 
while True:
    flag, img = cap.read()
    img = cv2.flip(img,0) 
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV )
    thresh = cv2.inRange(hsv, hsv_min, hsv_max)

    moments = cv2.moments(thresh, 1)
    dM01 = moments['m01']
    dM10 = moments['m10']
    dArea = moments['m00']

    x = -1;
    y = -1;
    if dArea > 100:
        x = int(dM10 / dArea)
        y = int(dM01 / dArea)
        cv2.circle(img, (x, y), 5, color_yellow, 2)
        cv2.putText(img, "%d-%d" % (x,y), (x+10,y-10), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1, color_yellow, 2)
    if (int(Time*2) < int(time()*2)):
        go(x, y);
        
        
    #sleep(0.1)
    #print("123")
    
    cv2.imshow('result', img)

    
    ch = cv2.waitKey(5)
    if ch == 27:
        break

cap.release()
cv2.destroyAllWindows()
