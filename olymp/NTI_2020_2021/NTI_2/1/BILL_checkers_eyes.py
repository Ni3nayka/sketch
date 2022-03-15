'''
this program writing Bakay Egor, Moscow, Russia, 2020
minerva_eyes writing for checkers program BARS, version checkers_eyes: 1.0
download: https://yadi.sk/d/QsL3RJtT-QnlLA

eyes_area_analyser()
for exit enter "Esc"

https://docs.opencv.org/master/d1/dc5/tutorial_background_subtraction.html

https://docs.opencv.org/master/d8/d4b/tutorial_py_knn_opencv.html
https://docs.opencv.org/master/dd/d3b/tutorial_py_svm_opencv.html
'''

import cv2
import numpy as np
from copy import deepcopy
from time import sleep
from time import time
import os.path

camera_control = 0 # 0 - photo, 1 - camera
DEBUG = 0 # make camera monitor

name_calibrator = "BILL calibrator v1.0" # разрешенная версия calibrator 

#==================================================================================================================
# hello

print("$ import <BILL_checkers_eyes>")

#==================================================================================================================
# цветовые константы:

red_label = [0,0,0,0,0,0] # красная метка # yellow # края
limit = [0,0,0,0,0,0,0,0] # края вычисленные через calibrator
white_checker = [0,0,0,0,0,0] # белая шашка
black_checker = [0,0,0,0,0,0] # черная шашка
green_label = [0,0,0,0,0,0] # зеленая метка - дамка
gradus = 0

#==================================================================================================================
# read data from file

FILE_FLAG = 0

#if (1):
def setup_eyes_area_analyser(MORE_NAME):
    global FILE_FLAG
    global red_label
    global limit
    global white_checker
    global black_checker
    global green_label
    global gradus
    
    FILE_FLAG = 1
    
    def test_version(S,mas):
        i = 0
        while (i<len(mas)):
            if (S==str(mas[i]+'\n')):
                return 1
            i += 1
        return 0
    
    file = "BILL_config.txt"
    if (os.path.exists(file)):
        file = open('BILL_config.txt')
        if (test_version(str(file.readline()),MORE_NAME)): # testing file
            print("$ import <BILL_config.txt> for <BILL_checkers_eyes>")
            #file.readline() # name
            gradus = int(file.readline())
            limit = [int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline())]
            green_label = [int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline())]
            white_checker = [int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline())]
            black_checker = [int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline()),int(file.readline())]
        else:
            print("ERROR <BILL_checkers_eyes>: <BILL_config.txt> have error or more version")
            FILE_FLAG = 0
        file.close()
    else:
        print("$ ERROR <BILL_checkers_eyes>: no file <BILL_config.txt>")
        FILE_FLAG = 0
    return FILE_FLAG

#==================================================================================================================

'''
def eyes_version():
    return 1.0 #str()
'''

def test():
    def print_mas(mas):
        i = 0
        while (i<len(mas)):
            print(mas[i])
            i = i + 1
            
    print_mas(eyes_area_analyser())

def eyes_area_analyser():
    if (FILE_FLAG==0):
        print("$ ERROR <BILL_checkers_eyes>: no data from file <BILL_config.txt>")
        return 0 # no file
    else:
        def millis():
            return int(time()*1000)

        if (DEBUG):
            cv2.namedWindow( "result" ) # создаем главное окно
            cv2.namedWindow( "work" ) # создаем главное окно

        cap = cv2.VideoCapture(0)
        crange = [0,0,0, 0,0,0]

        #area = []

        area = [[9, 0, 9, 0, 9, 0, 9, 0],
                [0, 9, 0, 9, 0, 9, 0, 9],
                [9, 0, 9, 0, 9, 0, 9, 0],
                [0, 9, 0, 9, 0, 9, 0, 9],
                [9, 0, 9, 0, 9, 0, 9, 0],
                [0, 9, 0, 9, 0, 9, 0, 9],
                [9, 0, 9, 0, 9, 0, 9, 0],
                [0, 9, 0, 9, 0, 9, 0, 9]]

        #==================================================================================================================
        # функции для поиска обьектов на картинке
        
        def checker_analyzer(image):
            # заносим цветове параметры шашек
            #global white_checker
            #global black_checker
            #global green_label
            
            def input_color(color):
                img = deepcopy(image)
                hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV )
            
                # переносим значения из массива в переменные
                h1 = color[0]
                s1 = color[1]
                v1 = color[2]
                h2 = color[3]
                s2 = color[4]
                v2 = color[5]

                # формируем начальный и конечный цвет фильтра
                h_min = np.array((h1, s1, v1), np.uint8)
                h_max = np.array((h2, s2, v2), np.uint8)

                # накладываем фильтр на кадр в модели HSV
                thresh = cv2.inRange(hsv, h_min, h_max)
                
                if 1:
                    # вычисляем моменты изображения
                    moments = cv2.moments(thresh, 1)
                    dM01 = moments['m01']
                    dM10 = moments['m10']
                    dArea = moments['m00']
                    # будем реагировать только на те моменты,
                    # которые содержать больше n пикселей
                    if dArea > 10:
                        return 1
                    else:
                        return 0
                    
            if (input_color(white_checker)):
                if (input_color(green_label)):
                    return 11
                else:
                    return 1
            elif (input_color(black_checker)):
                if (input_color(green_label)):
                    return 12
                else:
                    return 2
            else:
                return 0
            

        def output_image(image, delay):
            if (DEBUG):
                t = millis()
                while (t+delay>millis()):
                    cv2.imshow("work", image)
                    ch = cv2.waitKey(5)
                    if ch == 27:
                        break
                    
        def output_image2(image, delay):
            if (DEBUG):
                t = millis()
                while (t+delay>millis()):
                    cv2.imshow("result", image)
                    ch = cv2.waitKey(5)
                    if ch == 27:
                        break
                
        def print_mas(mas):
            i = 0
            while (i<len(mas)):
                print(mas[i])
                i = i + 1
                    
        #==================================================================================================================
        
        img = 0
        if (camera_control==0):
            # заносим картинку в программу
            img = cv2.imread("image.jpg")
        else:
            flag, img = cap.read()
        #ras_img = img.shape # узнаем размер изображения

        # уменьшаем картинку
        final_wide = 400 # ширина
        r = float(final_wide) / img.shape[1]
        dim = (final_wide, int(img.shape[0] * r))
        # уменьшаем изображение до подготовленных размеров
        img_save = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)
        img = deepcopy(img_save)
        final_height = img_save.shape[0] # высота

        # узнаем полученый размер
        #print(img_save.shape) 

        # смотрим картинку при необходимости
        output_image(img_save, 2000)
        
        # плющим изображение в квадрат (по данным файла)
        #img = cv2.imread('image.jpg')
        rows,cols,ch = img.shape
        #output_image(img, 2000)
        pts1 = np.float32([[limit[0],limit[1]],[limit[2],limit[3]],[limit[4],limit[5]],[limit[6],limit[7]]])
        pts2 = np.float32([[0,0],[300,0],[0,300],[300,300]])
        M = cv2.getPerspectiveTransform(pts1,pts2)
        dst = cv2.warpPerspective(img,M,(300,300))
        output_image(dst, 2000)
        img_save = deepcopy(dst)
        
        '''
        coo = [limit[2],limit[3],limit[0],limit[1]]
        #cropped = img_save[0:150, 0:200]
        cropped = img_save[coo[0]:coo[1], coo[2]:coo[3]]
        img_save = deepcopy(cropped)
        '''
        output_image(img_save, 2000)
        
        # переворачиваем изображение при необходимости (крутим вокруг своей оси)
        if (gradus!=0):
            (h, w) = img_save.shape[:2] # получим размеры изображения для поворота
            center = (w / 2, h / 2)     # вычислим центр изображения
            M = cv2.getRotationMatrix2D(center, 90*gradus, 1.0) # повернем изображение на 180 градусов (вокруг центра) 
            img_save = cv2.warpAffine(img_save, M, (w, h))
            output_image(img_save, 2000)

        #отразим изображение по горизонтали
        #flip_image = cv2.flip(image,1)
        #output_image(img_save, 2000)

        # запоминаем новые параметры изображения
        #print(img_save.shape) 
        final_wide   = img_save.shape[1] # ширина
        final_height = img_save.shape[0] # высота
        #cv2.imshow("work", cropped)
        #cv2.waitKey(0)

        # вырезаем одну клетку поля
        #cropped = img_save[int(final_height/8)*3:int(final_height/8)*4, int(final_wide/8)*4:int(final_wide/8)*5]
        #output_image(cropped, 2000)

        # смотрим положение шашек (разрезая поле)
        x = 0
        y = 0
        while (y<=7):
            if (area[y][x]==0):
                # вырезаем одну клетку поля
                cropped = img_save[int(final_height/8)*y:int(final_height/8)*(y+1), int(final_wide/8)*x:int(final_wide/8)*(x+1)]
                output_image2(cropped, 1000)
                area[y][x] = checker_analyzer(cropped)
            if (x>=7):
                x = 0
                y += 1
            else:
                x += 1
        
        if (DEBUG): 
            print_mas(area)

        cap.release()
        cv2.destroyAllWindows()
        return area

#eyes_area_analyser()
