#!/usr/bin/env python3

import sys
from robot_library.robot import *
import rospy
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


def reverse(mas):
    mas1 = []
    for i in range(4):
        mas1.append([mas[3][i], mas[2][i], mas[1][i], mas[0][i]])
    return mas1

def input_color_2(image, color):
    # global image
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


def camera_analyzing_2():
    global image
    robot = Robot()
    img = robot.getImage()
    image = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)

    Black = [0, 0, 0, 25, 25, 25]

    black_image_1 = input_color_2(image, Black)
    black_image = deepcopy(black_image_1)

    bbb = 0
    for i in range(len(black_image)):
        for u in range(len(black_image[i])):
            if black_image[i][u] > 0:
                bbb += 1
    if bbb < 500:
        return -1

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

    # плющим изображение в квадрат (по данным файла)
    pts1 = np.float32(coo)
    pts2 = np.float32([[0, 0], [300, 0], [0, 300], [300, 300]])
    M = cv2.getPerspectiveTransform(pts1, pts2)
    dst = cv2.warpPerspective(image, M, (300, 300))
    image = deepcopy(dst)

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
            image1 = input_color_2(image1, Black)
            a = 0
            for b in range(len(image1)):
                a += sum(image1[b])
            mas[i-1].append(int(deepcopy(a) / 637500 * 1.9))
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

area = [[9,0,9,0,9,0,9,0],
        [0,9,0,9,0,9,0,9],
        [9,0,9,0,9,0,9,0],
        [0,9,0,9,0,9,0,9],
        [9,0,9,0,9,0,9,0],
        [0,9,0,9,0,9,0,9],
        [9,0,9,0,9,0,9,0],
        [0,9,1,9,0,9,1,9]]

if __name__ == "__main__":
    object_color = camera_analyzing_2()
    print("answer", object_color)
