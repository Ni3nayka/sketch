'''
this program writing Bakay Egor, Moscow, Russia, 2020
checkers_eyes writing for checkers program BARS, version checkers_eyes: 1.0
download: https://yadi.sk/d/QsL3RJtT-QnlLA

for exit enter "Esc"
'''

import cv2
import numpy as np
from copy import deepcopy
from time import sleep
from time import time
import os.path

#print("$ import <BILL_calibrator>")

# configurator(0, "BILL calibrator v1.1", ["BILL calibrator v1.1"])

def configurator(camera_control, my_data): # MORE_NAME - массив разрешенных имен (версий) при проверке файла, NAME = реальное имя
    RAS = 400 # до какого размера по ширине обжать фото
    
    #camera_control = 0 # 0 - photo, 1 - camera

    #NAME = "BILL calibrator v1.0"

    #print(NAME,  "- started")

    #==================================================================================================================
    # hello

    #print("BILL_calibrator - started")

    #==================================================================================================================

#    # цветовые константы:
#    # красная метка
#    red_label = [0,111,147, 55,255,255] # yellow
#    limit = [100,100,200,100,100,200,200,200] # LRUG
#
#    # белая шашка
#    white_checker = [87,26,84, 152,255,255]
#
#    # черная шашка
#    black_checker = [0,112,100, 6,141,103]
#
#    # зеленая метка - дамка
#    green_label = [0,0,10, 0,0,0]
#
#    gradus = 0

    # цветовые константы:
    # красная метка
    red_label = [0,0,10, 0,0,0] # yellow
    limit = [my_data[1],my_data[2],my_data[3],my_data[4],my_data[5],my_data[6],my_data[7],my_data[8]] # LRUG

    # белая шашка
    white_checker = [my_data[15],my_data[16],my_data[17], my_data[18],my_data[19],my_data[20]]

    # черная шашка
    black_checker = [my_data[21],my_data[22],my_data[23], my_data[24],my_data[25],my_data[26]]

    # зеленая метка - дамка
    green_label = [my_data[9],my_data[10],my_data[11], my_data[12],my_data[13],my_data[14]]

    gradus = my_data[0]

    def test_version(S,mas):
        i = 0
        while (i<len(mas)):
            if (S==str(mas[i]+'\n')):
                return 1
            i += 1
        return 0
    
    #==================================================================================================================

    def nothing(*arg):
            pass
        
    def my_rectangle(img, mas, color, d):
        '''
        #cv2.rectangle(img, (mas[0], mas[2]), (mas[1], mas[3]), color, d)
        cv2.line(img, (mas[0], mas[1]), (mas[2], mas[3]), color, d)
        cv2.line(img, (mas[0], mas[1]), (mas[4], mas[5]), color, d)
        cv2.line(img, (mas[4], mas[5]), (mas[6], mas[7]), color, d)
        cv2.line(img, (mas[6], mas[7]), (mas[2], mas[3]), color, d)
        return img
        '''
        d = 1
        cv2.line(img, (mas[0], mas[1]), (mas[2], mas[3]), (0, 255, 255), d)
        cv2.line(img, (mas[0], mas[1]), (mas[4], mas[5]), (0, 255, 255), d)
        cv2.line(img, (mas[4], mas[5]), (mas[6], mas[7]), (0, 123, 255), d)
        cv2.line(img, (mas[6], mas[7]), (mas[2], mas[3]), (0, 255, 255), d)
        cv2.circle(img, (mas[4], mas[5]), 1, (0,0,255) , 2)
        return img

    NAME_W = "white"
    NAME_B = "black"
    NAME_D = "dama"
    NAME2 = "tool"
    NAME4 = "coord"
    NAME3 = "monitor"

    cv2.namedWindow( NAME_W ) # создаем окно настроек цвета белых шашек
    cv2.namedWindow( NAME_B ) # создаем окно настроек цвета черных шашек
    cv2.namedWindow( NAME_D ) # создаем окно настроек цвета меток дамок
    cv2.namedWindow( NAME2 ) # создаем окно управления настройками
    cv2.namedWindow( NAME4 ) # создаем окно настроек координат
    cv2.namedWindow( NAME3 ) # создаем окно вывода картинки
    cap = cv2.VideoCapture(0)

    cv2.createTrackbar('h1', NAME_W, white_checker[0], 255, nothing) # (*, *, начальное положение, макс положение, *)
    cv2.createTrackbar('s1', NAME_W, white_checker[1], 255, nothing)
    cv2.createTrackbar('v1', NAME_W, white_checker[2], 255, nothing)
    cv2.createTrackbar('h2', NAME_W, white_checker[3], 255, nothing)
    cv2.createTrackbar('s2', NAME_W, white_checker[4], 255, nothing)
    cv2.createTrackbar('v2', NAME_W, white_checker[5], 255, nothing)
    cv2.createTrackbar('h1', NAME_B, black_checker[0], 255, nothing) # (*, *, начальное положение, макс положение, *)
    cv2.createTrackbar('s1', NAME_B, black_checker[1], 255, nothing)
    cv2.createTrackbar('v1', NAME_B, black_checker[2], 255, nothing)
    cv2.createTrackbar('h2', NAME_B, black_checker[3], 255, nothing)
    cv2.createTrackbar('s2', NAME_B, black_checker[4], 255, nothing)
    cv2.createTrackbar('v2', NAME_B, black_checker[5], 255, nothing)
    cv2.createTrackbar('h1', NAME_D, green_label[0], 255, nothing) # (*, *, начальное положение, макс положение, *)
    cv2.createTrackbar('s1', NAME_D, green_label[1], 255, nothing)
    cv2.createTrackbar('v1', NAME_D, green_label[2], 255, nothing)
    cv2.createTrackbar('h2', NAME_D, green_label[3], 255, nothing)
    cv2.createTrackbar('s2', NAME_D, green_label[4], 255, nothing)
    cv2.createTrackbar('v2', NAME_D, green_label[5], 255, nothing)
    cv2.createTrackbar('*C', NAME2, gradus, 3, nothing)
    cv2.createTrackbar('GDWB', NAME2, 0, 3, nothing)
    cv2.createTrackbar('x1', NAME4, limit[0], 400, nothing)
    cv2.createTrackbar('y1', NAME4, limit[1], 400, nothing)
    cv2.createTrackbar('x2', NAME4, limit[2], 400, nothing)
    cv2.createTrackbar('y2', NAME4, limit[3], 400, nothing)
    cv2.createTrackbar('x3', NAME4, limit[4], 400, nothing)
    cv2.createTrackbar('y3', NAME4, limit[5], 400, nothing)
    cv2.createTrackbar('x4', NAME2, limit[6], 400, nothing)
    cv2.createTrackbar('y4', NAME2, limit[7], 400, nothing)

    crange = [0,0,0, 0,0,0]
    GDWB = 0

    while True:
        if (camera_control==1):
            flag, img = cap.read()
        else:
            img = cv2.imread("eyes\image.jpg")
            
        # уменьшаем картинку
        final_wide = RAS # ширина
        r = float(final_wide) / img.shape[1]
        dim = (final_wide, int(img.shape[0] * r))
        # уменьшаем изображение до подготовленных размеров
        img_save = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)
        
        gradus = cv2.getTrackbarPos('*C', NAME2)
        if (0!=gradus):
            # переворачиваем изображение при необходимости (крутим вокруг своей оси)
            (h, w) = img_save.shape[:2] # получим размеры изображения для поворота
            center = (w / 2, h / 2)     # вычислим центр изображения
            M = cv2.getRotationMatrix2D(center, (0-gradus)*90, 1.0) # повернем изображение на 180 градусов (вокруг центра) 
            img_save = cv2.warpAffine(img_save, M, (w, h))
        
        img = deepcopy(img_save)
        #img=cv2.flip(img, 0)
     
        GDWB = cv2.getTrackbarPos('GDWB', NAME2)
        if (GDWB!=0):
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV )
        
            # считываем значения бегунков
            if (GDWB==1):
                h1 = cv2.getTrackbarPos('h1', NAME_D)
                s1 = cv2.getTrackbarPos('s1', NAME_D)
                v1 = cv2.getTrackbarPos('v1', NAME_D)
                h2 = cv2.getTrackbarPos('h2', NAME_D)
                s2 = cv2.getTrackbarPos('s2', NAME_D)
                v2 = cv2.getTrackbarPos('v2', NAME_D)
                green_label = [h1,s1,v1,h2,s2,v2]
            if (GDWB==2):
                h1 = cv2.getTrackbarPos('h1', NAME_W)
                s1 = cv2.getTrackbarPos('s1', NAME_W)
                v1 = cv2.getTrackbarPos('v1', NAME_W)
                h2 = cv2.getTrackbarPos('h2', NAME_W)
                s2 = cv2.getTrackbarPos('s2', NAME_W)
                v2 = cv2.getTrackbarPos('v2', NAME_W)
                white_checker = [h1,s1,v1,h2,s2,v2]
            if (GDWB==3):
                h1 = cv2.getTrackbarPos('h1', NAME_B)
                s1 = cv2.getTrackbarPos('s1', NAME_B)
                v1 = cv2.getTrackbarPos('v1', NAME_B)
                h2 = cv2.getTrackbarPos('h2', NAME_B)
                s2 = cv2.getTrackbarPos('s2', NAME_B)
                v2 = cv2.getTrackbarPos('v2', NAME_B)
                black_checker = [h1,s1,v1,h2,s2,v2]

            # формируем начальный и конечный цвет фильтра
            h_min = np.array((h1, s1, v1), np.uint8)
            h_max = np.array((h2, s2, v2), np.uint8)

            # накладываем фильтр на кадр в модели HSV
            thresh = cv2.inRange(hsv, h_min, h_max)
            
            cv2.imshow(NAME3, thresh) # вывод картинки 
        else: # настраиваем границы поля
            limit = [cv2.getTrackbarPos('x1', NAME4),cv2.getTrackbarPos('y1', NAME4),cv2.getTrackbarPos('x2', NAME4),cv2.getTrackbarPos('y2', NAME4),cv2.getTrackbarPos('x3', NAME4),cv2.getTrackbarPos('y3', NAME4),cv2.getTrackbarPos('x4', NAME2),cv2.getTrackbarPos('y4', NAME2)]
            thresh = deepcopy(img)
            #cv2.rectangle(thresh, (L, U), (R, D), (0, 255, 255), 2)
            thresh = my_rectangle(thresh, limit, (0, 255, 255), 2)
            cv2.imshow(NAME3, thresh)
     
        ch = cv2.waitKey(5)
        if ch == 27:
            break

    cap.release()
    cv2.destroyAllWindows()

    my_data = []
    my_data.append(gradus)
    for i in range(len(limit)):
        my_data.append(limit[i])
    for i in range(len(green_label)):
        my_data.append(green_label[i])
    for i in range(len(white_checker)):
        my_data.append(white_checker[i])
    for i in range(len(black_checker)):
        my_data.append(black_checker[i])
        
    return my_data


#if __name__ == "__main__":
#    camera_control = 0
#    my_name = "protocol v1.1"
#    configurator(camera_control, my_name, [my_name])
#else:
#    print("$ import <BILL_calibrator_coo>")
