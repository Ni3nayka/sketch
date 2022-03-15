# разрешенные версии для config файла
MORE_NAME = ["BILL calibrator v1.1","BILL calibrator v1.0"]
calibrator_NAME = "BILL calibrator v1.1"
NAME = "BILL checkers 1.0 demo"
ras = 50 # константа для графического поля

from BILL_checkers_eyes import *
FILE_FLAG = setup_eyes_area_analyser(MORE_NAME) # read file
from BILL_calibrator import * #configurator(0, calibrator_NAME, MORE_NAME) #configurator(camera_control, NAME, MORE_NAME)
from time import sleep
from time import time
from tkinter import *
import os.path
from random import * # x0 = randint(0, 100)

print("setup - successfully")

#https://docs.opencv.org/master/da/d6e/tutorial_py_geometric_transformations.html

controller = [0,0,0,0] # для графического контроллера

window = Tk()
window.title(NAME)
canvas = Canvas(window,width=12*ras,height=9*ras,bg="white")
canvas.pack()
file = "BILL.ico"
if (os.path.exists(file)):
    window.iconbitmap('BILL.ico')
    
#===================================================================================================================================================

def view_checkers(area,controller):
    #global wingow
    #global canvas
    canvas.delete("all")
    if (area==0):
        canvas.create_text(ras*4.5,ras*4.5,text="нет файла BILL_config.txt",font="Verdana 25",justify=CENTER,fill="black")
    elif (area==1):
        canvas.create_text(ras*4.5,ras*4.5,text="нет изображения image.jpg",font="Verdana 25",justify=CENTER,fill="black")
    else:
        '''
        x = 0 # shaska => damka
        while (x <= 7):
            if (area[0][x] == 1):
                area[0][x] = area[0][x] + 10
            x = x + 1
        x = 0
        while (x <= 7):
            if (area[7][x] == 2):
                area[7][x] = area[7][x] + 10
            x = x + 1
        '''
        x = 0
        y = 0
        # make area
        #canvas.create_line(0,0,600,600,width=5,fill="yellow")
        
        canvas.create_rectangle(0,0,ras*9,ras*9,fill="#feb")
        canvas.create_rectangle(ras*0.5,ras*0.5,ras*8.5,ras*8.5,fill="#feb")
        
        #canvas.create_text(ras/4+0*ras,ras/4+1*ras,text="A",font="Verdana 12",justify=CENTER,fill="black")
        canvas.create_text(ras*1,ras*0.25,text="a",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*2,ras*0.25,text="b",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*3,ras*0.25,text="c",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*4,ras*0.25,text="d",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*5,ras*0.25,text="e",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*6,ras*0.25,text="f",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*7,ras*0.25,text="g",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8,ras*0.25,text="h",font="Verdana 10",justify=CENTER,fill="black")
        
        canvas.create_text(ras*1,ras*8.75,text="a",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*2,ras*8.75,text="b",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*3,ras*8.75,text="c",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*4,ras*8.75,text="d",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*5,ras*8.75,text="e",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*6,ras*8.75,text="f",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*7,ras*8.75,text="g",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8,ras*8.75,text="h",font="Verdana 10",justify=CENTER,fill="black")

        canvas.create_text(ras*0.25,ras*1,text="8",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*2,text="7",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*3,text="6",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*4,text="5",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*5,text="4",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*6,text="3",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*7,text="2",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*0.25,ras*8,text="1",font="Verdana 10",justify=CENTER,fill="black")
        
        canvas.create_text(ras*8.75,ras*1,text="8",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*2,text="7",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*3,text="6",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*4,text="5",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*5,text="4",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*6,text="3",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*7,text="2",font="Verdana 10",justify=CENTER,fill="black")
        canvas.create_text(ras*8.75,ras*8,text="1",font="Verdana 10",justify=CENTER,fill="black")
        while (y < 8):
            x = 0
            while (x < 8):
                if (area[y][x]!=9):
                    canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2,x*ras+ras/2*3,y*ras+ras/2*3,fill="#c96",outline="#c96")
                    if (area[y][x]!=0 and area[y][x]<100 and 1):
                        wer = 0.05
                        canvas.create_oval([x*ras+ras/2+ras*wer+ras/10,(y-1)*ras+ras/2*3+ras/10+ras*wer],[x*ras+ras/2*3-ras/10+ras*wer,(y-1)*ras+ras/2*5-ras/10+ras*wer],fill="#643", outline="#643")
                        
                x = x + 1
            y = y + 1
        # make checkers
        x = 0
        y = 0
        while (y < 8):
            x = 0
            while (x < 8): 
                if ((area[y][x] != 9) and (area[y][x] != 0)):
                    if (area[y][x]%10==1):
                        canvas.create_oval([x*ras+ras/2+ras/10,(y-1)*ras+ras/2*3+ras/10],[x*ras+ras/2*3-ras/10,(y-1)*ras+ras/2*5-ras/10],fill="white", outline="white")
                    else:
                        qwe = 10
                        canvas.create_oval([x*ras+ras/2+ras/qwe,(y-1)*ras+ras/2*3+ras/qwe],[x*ras+ras/2*3-ras/qwe,(y-1)*ras+ras/2*5-ras/qwe],fill="black", outline="black")
                    if (int(area[y][x]/10)%10 >= 1):
                        if (area[y][x]%10==1):
                            canvas.create_oval([x*ras+ras/2+ras/5,(y-1)*ras+ras/2*3+ras/5],[x*ras+ras/2*3-ras/5,(y-1)*ras+ras/2*5-ras/5],fill="#bb9", outline="#bb9") 
                        else:
                            canvas.create_oval([x*ras+ras/2+ras/5,(y-1)*ras+ras/2*3+ras/5],[x*ras+ras/2*3-ras/5,(y-1)*ras+ras/2*5-ras/5],fill="#555", outline="#555") 
                    else:
                        if (area[y][x]%10==1):
                            canvas.create_oval([x*ras+ras/2+ras/5,(y-1)*ras+ras/2*3+ras/5],[x*ras+ras/2*3-ras/5,(y-1)*ras+ras/2*5-ras/5],fill="white", outline="grey")
                            canvas.create_oval([x*ras+ras/2+ras/3.3,(y-1)*ras+ras/2*3+ras/3.3],[x*ras+ras/2*3-ras/3.3,(y-1)*ras+ras/2*5-ras/3.3],fill="white", outline="grey")
                        else:
                            canvas.create_oval([x*ras+ras/2+ras/5,(y-1)*ras+ras/2*3+ras/5],[x*ras+ras/2*3-ras/5,(y-1)*ras+ras/2*5-ras/5],fill="black", outline="grey")
                            canvas.create_oval([x*ras+ras/2+ras/3.3,(y-1)*ras+ras/2*3+ras/3.3],[x*ras+ras/2*3-ras/3.3,(y-1)*ras+ras/2*5-ras/3.3],fill="black", outline="grey")
                    if (area[y][x]>100): 
                        canvas.create_line(x*ras+ras*0.8,y*ras+ras*0.55,x*ras+ras*1.45,y*ras+ras*1.0,width=3,fill="#c96")
                        canvas.create_line(x*ras+ras*0.55,y*ras+ras*1.4,x*ras+ras*1.2,y*ras+ras*0.6,width=5,fill="#c96")
                        canvas.create_line(x*ras+ras*1.5,y*ras+ras*1.2,x*ras+ras*0.5,y*ras+ras*1.4,width=4,fill="#c96")
                x = x + 1
            y = y + 1
            canvas.create_rectangle(ras*0.5,ras*0.5,ras*8.5,ras*8.5,width=2, outline="#c96")
    ############################################################################################################################################################################
    #controller
    window.update()

def map_a(x, in_min, in_max, out_min, out_max):
        return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
    
def millis():
    return int(time()*1000)

def cut(i, a):
    
    if (abs(i) > a):
        i = abs(i)/i*a
        i = int(i)
    return i

def znak(a):
    if   (a > 0):
        return  1
    elif (a < 0):
        return -1
    else:
        return  0
    
#===================================================================================================================================================

area_zero = [[9, 0, 9, 0, 9, 0, 9, 0],
             [0, 9, 0, 9, 0, 9, 0, 9],
             [9, 0, 9, 0, 9, 0, 9, 0],
             [0, 9, 0, 9, 0, 9, 0, 9],
             [9, 0, 9, 0, 9, 0, 9, 0],
             [0, 9, 0, 9, 0, 9, 0, 9],
             [9, 0, 9, 0, 9, 0, 9, 0],
             [0, 9, 0, 9, 0, 9, 0, 9]]

'''
area = [[9, 1, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 0, 9],
        [9, 2, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 0, 9],
        [9, 12, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 0, 9],
        [9, 11, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 511, 9]]
'''
area = deepcopy(area_zero)
x = 0
y = 0
while (y<=7):
    if (area[y][x]!=9 and randint(0, 1)==1):
        area[y][x] = randint(1, 4)
        if (area[y][x]==3 or area[y][x]==4):
            area[y][x] += 8
    if (x>=7):
        x = 0
        y += 1
    else:
        x += 1

#===================================================================================================================================================
# hello
view_checkers(area,controller)
sleep(1)
view_checkers(area_zero,controller)
area = deepcopy(area_zero)
#===================================================================================================================================================

def click(event):
    global window
    global canvas
    x = event.x
    y = event.y
    if (x>=0 and x<=ras*9 and y>=0 and y<=ras*9):
        if (FILE_FLAG==1):
            if (os.path.exists("image.jpg")):
                view_checkers(eyes_area_analyser(),controller)
            else:
                view_checkers(1,controller)
        else:
            view_checkers(0,controller)
    else:
        window.destroy()
        #sleep(1)
        configurator(0, calibrator_NAME, MORE_NAME)
        #########
        window = Tk()
        window.title(NAME)
        canvas = Canvas(window,width=12*ras,height=9*ras,bg="white")
        canvas.pack()
        file = "BILL.ico"
        if (os.path.exists(file)):
            window.iconbitmap('BILL.ico')
        canvas.bind("<Button-1>", click)
        view_checkers(area_zero,controller)
        area = deepcopy(area_zero)

#timer = millis()
#while (timer+3000>millis()):
#    pass

#window.destroy()
#sleep(1)

if (0):
    window = Tk()
    window.title(NAME)
    canvas = Canvas(window,width=12*ras,height=9*ras,bg="white")
    canvas.pack()
    file = "BILL.ico"
    if (os.path.exists(file)):
        window.iconbitmap('BILL.ico')
    canvas.bind("<Button-1>", click)

    view_checkers(area,controller) 
'''
if (FILE_FLAG==1):
    if (os.path.exists("image.jpg")):
        view_checkers(eyes_area_analyser())
    else:
        view_checkers(1)
else:
    view_checkers(0)
    
window.mainloop()
'''
canvas.bind("<Button-1>", click)
window.mainloop()