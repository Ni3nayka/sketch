#!/usr/bin/env python3

import sys
#from robot_library.robot import *
#import rospy
import cv2
import numpy as np
from time import time
from copy import deepcopy

'''
Green - 8 0 0 107 255 255
Blue - 88 68 0 255 255 255
Red - 0 239 185 17 255 255
Yellow - 15 203 93 58 255 255
'''
image = 0 # картинка

def camera_analyzing():
    global image
    image = 0
    
    if (0): # тут замените на 1, чтобы считывать с камеры робота, сейчас тут тетовое считывание сохраненного изображения
        # тут считайте картинку и переведите ее в RGB
        robot = Robot()
        robot.getImage()
        image = RGB(image) 
    else:
        image = cv2.imread("12345.png")
    
    def input_color(color):
        global image
        img = deepcopy(image)
        hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV )
    
        # переносим значения из массива в переменные
        h1 = color[0]
        s1 = color[1]
        v1 = color[2]
        h2 = color[3]
        s2 = color[4]
        v2 = color[5]
        h_min = np.array((h1, s1, v1), np.uint8)
        h_max = np.array((h2, s2, v2), np.uint8)
        thresh = cv2.inRange(hsv, h_min, h_max)
        moments = cv2.moments(thresh, 1)
        dM01 = moments['m01']
        dM10 = moments['m10']
        dArea = moments['m00']
        return int(dArea)
    
    Green = [50, 20, 20, 107, 255, 255]
    Blue = [88, 68, 0, 255, 255, 255]
    Red = [0, 239, 115, 17, 255, 255]
    Yellow = [15, 203, 93, 58, 255, 255]
    
    array = ["Green", "Blue", "Red", "Yellow"]
    mas = [input_color(Green),input_color(Blue),input_color(Red),input_color(Yellow)]
    print(mas)
    return array[mas.index(max(mas))]


if __name__ == "__main__":
    object_color = camera_analyzing()
    print(object_color)