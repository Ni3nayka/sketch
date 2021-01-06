import cv2
import numpy as np
import smbus
import os
import time
from time import sleep
from time import time
from array import *
from tkinter import *

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

angle_servo = array('i', [0,0,0]);
speed_motor = array('i', [0,0,0,0,0]);
encoder_data = array('i', [0,0,0,0,0]);
encoder_old_data = array('i', [0,0,0,0,0]);
encoder_time = array('i', [0,0,0,0,0]);

#=====================================================================================================================================================================================================
# utilites:

def encoder_read():
    global encoder_data;
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
    encoder_data[1] = d1*256*256  + d2*256  + d3;
    encoder_data[2] = d4*256*256  + d5*256  + d6;
    encoder_data[3] = d7*256*256  + d8*256  + d9;
    encoder_data[4] = d10*256*256 + d11*256 + d12;
    #print(encoder_data[1], " ", encoder_data[2], " ", encoder_data[3], " ", encoder_data[4]);

def encoder_clean():
    global encoder_data;
    global encoder_old_data;
    global encoder_time;
    for i in range(5):
        encoder_data[i] = 0;
        encoder_old_data[i] = 0;
        encoder_time[i] = 0;
    bus.write_byte(SLAVE_ADDRESS, ord('c'));
    print("clean encoder");

def map(x, in_min, in_max, out_min, out_max):
    return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);

def millis():
    return int(time()*1000);

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
        #print("motor: ", a, " speed: ", i);
        i = i + 100;
        bus.write_byte(SLAVE_ADDRESS, a);
        bus.write_byte(SLAVE_ADDRESS, i);
    elif ((a == 5) or (a == 6)):
        i = cut(i, 100);
        #print("servo: ", a-4, " angle: ", i);
        i = i + 100;
        bus.write_byte(SLAVE_ADDRESS, a);
        bus.write_byte(SLAVE_ADDRESS, i);
    else :
        print("ERROR vvod");

def stop_motor():
    global speed_motor;
    for i in range(5):
        speed_motor[i] = 0;
        if (i != 0):
            vvod(i, 0);
    

def start_motor():
    global speed_motor;
    for i in range(5):
        if (i != 0):
            vvod(i, speed_motor[i]);

def auto_speed_motor(a):
    if (a == 1):
        bus.write_byte(SLAVE_ADDRESS, ord('M'));
    else:
        bus.write_byte(SLAVE_ADDRESS, ord('m'));

def auto_angle_servo(a):
    if (a == 1):
        bus.write_byte(SLAVE_ADDRESS, ord('S'));
    else:
        bus.write_byte(SLAVE_ADDRESS, ord('s'));

def auto_n_motor(a):
    if (a == 1):
        bus.write_byte(SLAVE_ADDRESS, ord('N'));
    else:
        bus.write_byte(SLAVE_ADDRESS, ord('n'));

def PDU(speed):
    def PDU_forward():  
        print("PDU_forward");
        vvod(1, speed);
        vvod(2, speed);
        vvod(3, speed);
        vvod(4, speed);

    def PDU_backward():  
        print("PDU_backward");
        vvod(1, -speed);
        vvod(2, -speed);
        vvod(3, -speed);
        vvod(4, -speed);

    def PDU_stop():  
        print("PDU_stop");
        vvod(1, 0);
        vvod(2, 0);
        vvod(3, 0);
        vvod(4, 0);

    def PDU_left():  
        print("PDU_left");
        vvod(1, -speed);
        vvod(2, -speed);
        vvod(3, speed);
        vvod(4, speed);

    def PDU_right():  
        print("PDU_right");
        vvod(1, speed);
        vvod(2, speed);
        vvod(3, -speed);
        vvod(4, -speed);

    window = Tk();
    window.title("teh_eyes_PDU");
    window.geometry('200x100');

    btn = Button(window, text="forward", command=PDU_forward);
    btn.grid(column=1, row=0);
    btn = Button(window, text="left", command=PDU_left);
    btn.grid(column=0, row=1);
    btn = Button(window, text="right", command=PDU_right);
    btn.grid(column=2, row=1);
    btn = Button(window, text="backward", command=PDU_backward);
    btn.grid(column=1, row=2);
    btn = Button(window, text="stop motor", command=PDU_stop);
    btn.grid(column=1, row=1);

    window.mainloop();
    
#=====================================================================================================================================================================================================



def go(x, y):
    global Time;        
    global camera_center_x;
    global camera_center_y;
    global camera_x;
    global camera_y;
    global angle_servo;
    global speed_motor;
    global encoder_data;
    global encoder_old_data;
    global encoder_time;
    
def go_s(x, y):
    global Time;
    global camera_center_x;
    global camera_center_y;
    global camera_x;
    global camera_y;
    global angle_servo;
    global speed_motor;
    global encoder_data;
    global encoder_old_data;
    global encoder_time;
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
            angle_servo[1] = angle_servo[1] + aaa
            cut(angle_servo[1], 100);
            cut(angle_servo[1], 100);
            vvod(5, angle_servo[1]);

auto_speed_motor(1);
auto_angle_servo(1);
auto_n_motor(1);
    
stop_motor();
vvod(5, 0);
vvod(6, 0);
encoder_clean();

PDU(100);
stop_motor();
vvod(5, 0);
vvod(6, 0);
encoder_clean();

#mode = input("enter work mode: 1 - PDU; 2 - teh_eyes;");
#mode = int(mode);
mode = 1;

while True:
    flag, img = cap.read()
    img = cv2.flip(img,0)
    cv2.imshow('result', img)

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
        
    ch = cv2.waitKey(5)
    if ch == 27:
        break

cap.release()
cv2.destroyAllWindows()
