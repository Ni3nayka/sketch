#!/usr/bin/env python3

import sys
import cv2
import numpy as np
from time import time
from copy import deepcopy


#from robot_library.robot import *
#import rospy
#robot = Robot()

def cv_test(image):
    def nothing(*arg):
            pass
    cv2.namedWindow("NAME")
    while True:
        cv2.imshow("NAME", image) # black_image
        ch = cv2.waitKey(5)
        if ch == 27:
            break
    cv2.destroyAllWindows()

def update_image():
    #img = robot.getImage()
    #image = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)
    image = cv2.imread("444.jpg")
    #image = cv2.imread("222.png")
    
    #cv_test(image)
    
    (h, w) = image.shape[:2] # получим размеры изображения для поворота
    #print(h, w)
    h1 = int(h*0.8)
    pts1 = np.float32([[0,0], [w, 0], [0, h1], [w, h1]])
    pts2 = np.float32([[0,0], [w, 0], [0, h1], [w, h1]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(image, M, (w, h1))
    image = deepcopy(dst)
    
    #cv_test(image)
    
    return image
    

def reverse(mas):
    mas1 = []
    for i in range(4):
        mas1.append([mas[3][i], mas[2][i], mas[1][i], mas[0][i]])
    return mas1

def input_color(image,color):
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

def input_color_2(image, color):
    img = deepcopy(image)
    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

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
    return thresh


def test_qr_code(image):
    Black = [0, 0, 0, 2, 2, 2]
    bbb = input_color(image, Black)
    if bbb < 500: # порог, какое минимальное количество пикселей черного необходимо, чтобы робот понял, что видит QR код
        return 0
    else: return 1

def camera_analyzing_QR(image):

    Black = [0, 0, 0, 2, 2, 2]

    black_image = input_color_2(image, Black)

    coo = [[0, 0], [len(black_image[0]), 0], [0, len(black_image)], [len(black_image[0]), len(black_image)]]

    for i in range(len(black_image[0])):
        a = 0
        for u in range(len(black_image)):
            a += black_image[u][i]
        if a == 0:
            coo[0][0] += 1
            coo[2][0] += 1
        else:
            break
    coo[0][0] += 1
    coo[2][0] += 1

    i = len(black_image[0]) - 1
    while i >= 0:
        a = 0
        for u in range(len(black_image)):
            a += black_image[u][i]
        if a == 0:
            coo[1][0] -= 1
            coo[3][0] -= 1
        else:
            break
        i -= 1
    coo[1][0] -= 1
    coo[3][0] -= 1

    i = 0
    while len(black_image) > i:
        s = black_image[i][coo[0][0] + 1] + black_image[i][coo[0][0] + 2] + black_image[i][coo[0][0] + 3]
        if s == 0:
            i += 1
        else:
            break
    coo[0][1] = i

    i = 0
    while len(black_image) > i:
        s = black_image[i][coo[1][0] - 1] + black_image[i][coo[1][0] - 2] + black_image[i][coo[0][1] - 3]
        if s == 0:
            i += 1
        else:
            break
    coo[1][1] = i

    i = coo[2][1] - 1
    while i > 0:
        s = black_image[i][coo[2][0] + 1] + black_image[i][coo[2][0] + 2] + black_image[i][coo[2][0] + 3]
        if s == 0:
            i -= 1
        else:
            break
    coo[2][1] = i

    i = coo[3][1] - 1
    while i > 0:
        s = black_image[i][coo[3][0] - 1] + black_image[i][coo[3][0] - 2] + black_image[i][coo[3][0] - 3]
        if s == 0:
            i -= 1
        else:
            break
    coo[3][1] = i

    #print(coo)
    
    def my_rectangle(img, mas1, color, d):
        mas = []
        for i in range(len(mas1)):
            for u in range(len(mas1[i])):
                mas.append(mas1[i][u])
        #cv2.rectangle(img, (mas[0], mas[2]), (mas[1], mas[3]), color, d)
        cv2.line(img, (mas[0], mas[1]), (mas[2], mas[3]), color, d)
        cv2.line(img, (mas[0], mas[1]), (mas[4], mas[5]), color, d)
        cv2.line(img, (mas[4], mas[5]), (mas[6], mas[7]), color, d)
        cv2.line(img, (mas[6], mas[7]), (mas[2], mas[3]), color, d)
        return img
    
    if (0): cv_test(my_rectangle(image, coo, (0, 255, 255), 2))
    
    pts1 = np.float32(coo)
    pts2 = np.float32([[0, 0], [300, 0], [0, 300], [300, 300]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(image, M, (300, 300))
    image = deepcopy(dst)
    
    #cv_test(image)

    mas = []
    i = 1
    while (i<5):
        mas.append([])
        u = 1
        while (u<5):
            image1 = deepcopy(image)

            pts1 = np.float32([[50 * u, 50 * i], [50 * (u + 1), 50 * i], [50 * u, 50 * (i + 1)], [50 * (u + 1), 50 * (i + 1)]])
            pts2 = np.float32([[0, 0], [50, 0], [0, 50], [50, 50]])
            M = cv2.getPerspectiveTransform(pts1, pts2)
            dst = cv2.warpPerspective(image1, M, (50, 50))
            image1 = deepcopy(dst)

            cv2.destroyAllWindows()
            #print(input_color(image1, Black))
            #image1 = input_color_2(image1, Black)
            #a = 0
            #for b in range(len(image1)):
            #    a += sum(image1[b])
            #mas[i-1].append(int(deepcopy(a) / 637500 * 1.9))
            if (int(input_color(image1, Black)/1000)>=1): mas[i-1].append(1)
            else: mas[i-1].append(0)
            u+=1
        i+=1

    while mas[3][3] != 0:
        mas = deepcopy(reverse(mas))

    del mas[0][3]
    del mas[0][0]
    del mas[3][3]
    del mas[3][0]

    answer = []
    for i in range(len(mas)):
        for u in range(len(mas[i])):
            answer.append(mas[i][u])
    return answer

def camera_analyzing_color(image):
    
    Green = [50, 20, 20, 107, 255, 255]
    Blue = [88, 68, 0, 255, 255, 255]
    Red = [0, 239, 115, 17, 255, 255]
    Yellow = [15, 203, 93, 58, 255, 255]
    
    array = ["Green", "Blue", "Red", "Yellow"]
    mas = [input_color(image,Green),input_color(image,Blue),input_color(image,Red),input_color(image,Yellow)]
    #print(mas)
    aaa = max(mas)
    if (aaa>8000):
        gg = 1
        for i in range (4):
            if (i!=mas.index(aaa) and aaa/4<mas[i]): gg=0
        if (gg): return array[mas.index(aaa)]
    return "None"

if __name__ == "__main__":
    img = update_image() # считали картинку
    object_color = camera_analyzing_color(img) # определяем какой на ней цвет цвет
    print("answer color:", object_color)
    if (test_qr_code(img)): # проверяем, есть ли на ней QR код
        QR_code = camera_analyzing_QR(img) # определяем QR код
        print("QR answer:", QR_code)
    else: print("no QR code")
    qr = 0
