from tkinter import *
from random import * # x0 = randint(0, 100)
import time
from time import sleep
from time import time
Time = int(time()*1000)
ras = 50

# 9  - нельзя занимать - белая
# 0  - свободная черная клетка
# 1  - белая шашка
# 11 - белая дамка
# 2  - черная шашка
# 12 - черная дамка
area = [[9, 2, 9, 2, 9, 2, 9, 2],
        [2, 9, 2, 9, 2, 9, 2, 9],
        [9, 0, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 0, 9],
        [9, 0, 9, 0, 9, 0, 9, 0],
        [0, 9, 0, 9, 0, 9, 0, 9],
        [9, 1, 9, 1, 9, 1, 9, 1],
        [1, 9, 1, 9, 1, 9, 1, 9]]

click_flag = 0;
click_x = -1
click_y = -1
x = -1
y = -1


def qwerty():
    global area
    global click_flag
    global click_x
    global click_y
    global x
    global y
    
    out_window = Tk()
    out_window.title('OUTPUT')
    #window.geometry('900x900')
    canvas = Canvas(out_window,width=9*ras,height=9*ras,bg="grey") # ,cursor="pencil"

    in_window = Tk()
    in_window.title('INPUT')
    in_window.geometry('400x250')

    #===================================================================================================================================================================================================

    def clicked():
        #res = "Привет {}".format(txt.get())
        #lbl.configure(text=res)
        print(txt.get())

    lbl = Label(in_window, text="Привет")  
    lbl.grid(column=0, row=0)  
    txt = Entry(in_window,width=10)  
    txt.grid(column=1, row=0)  
    btn = Button(in_window, text="Не нажимать!", command=clicked)  
    btn.grid(column=2, row=0) 

    #===================================================================================================================================================================================================
    def map(x, in_min, in_max, out_min, out_max):
        return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);

    def millis():
        return int(time()*1000);

    def cut(i, a):
        if (abs(i) > a):
            i = abs(i)/i*a;
            i = int(i);
        return i;
    
    def craft_field():
        x = 0
        y = 0
        #canvas.create_line(0,0,600,600,width=5,fill="yellow")
        while (y < 8):
            x = 0
            while (x < 8):
                canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2,x*ras+ras/2*3,y*ras+ras/2*3,fill="white",outline="white")
                canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2*3,x*ras+ras/2*3,y*ras+ras/2*5,fill="black",outline="black")
                x = x + 1
                canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2,x*ras+ras/2*3,y*ras+ras/2*3,fill="black",outline="black")
                canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2*3,x*ras+ras/2*3,y*ras+ras/2*5,fill="white",outline="white")
                x = x + 1
            y = y + 2
        #canvas.create_text(ras/4+0*ras,ras/4+1*ras,text="A",font="Verdana 12",justify=CENTER,fill="black")

    def reboot_checkers():
        global area
        global Time
        x = 0
        y = 0
        while (y < 8):
            x = 0
            #print(area[y][0], area[y][1], area[y][2], area[y][3], area[y][4], area[y][5], area[y][6], area[y][7])
            while (x < 8): 
                if ((area[y][x] != 9) and (area[y][x] != 0)):
                    if (area[y][x]%10 == 1):
                        canvas.create_oval([x*ras+ras/2+ras/10,(y-1)*ras+ras/2*3+ras/10],[x*ras+ras/2*3-ras/10,(y-1)*ras+ras/2*5-ras/10],fill="white")
                    else:
                        canvas.create_oval([x*ras+ras/2+ras/10,(y-1)*ras+ras/2*3+ras/10],[x*ras+ras/2*3-ras/10,(y-1)*ras+ras/2*5-ras/10],fill="grey")
                elif ((area[y][x] != 0) and (y < 7)):
                    canvas.create_rectangle(x*ras+ras/2,y*ras+ras/2*3,x*ras+ras/2*3,y*ras+ras/2*5,fill="black",outline="black")
                    
                x = x + 1
            y = y + 1

    #===================================================================================================================================================================================================

    craft_field()
    reboot_checkers()
    
    def click(event):
        global area
        global click_flag
        global click_x
        global click_y
        #root.quit()
        x = event.x
        y = event.y
        #print(x, y)
        if ((x >= ras/2) and (x <= ras/2*17) and (y >= ras/2) and (y <= ras/2*17)): 
            x = map(x, ras/2, ras/2*17, 0, 8)
            y = map(y, ras/2, ras/2*17, 0, 8)
            if ((click_x == -1) and (area[y][x] != 9)):
                click_x = x
                click_y = y
                click_flag = 1
            elif (area[y][x] != 9):
                #============================
                q = area[click_y][click_x]
                area[click_y][click_x] = 0
                area[y][x] = q
                #============================
                x = -1
                y = -1
                click_x = -1
                click_y = -1
                click_flag = 0
                #out_window.update()
        else:
            click_x = -1
            click_y = -1
            
        reboot_checkers()
        if (click_flag == 1):
            print(click_x, click_y)
            
            
    canvas.bind("<Button-1>", click)

    if (Time + 2000 < millis()):
    #i = 2
    #if (i == '1'):
        #print(area[2][1])
        area[2][1] = 2
        area[1][2] = 0
        reboot_checkers()

    canvas.pack()
    out_window.mainloop()
    in_window.mainloop()

qwerty()
