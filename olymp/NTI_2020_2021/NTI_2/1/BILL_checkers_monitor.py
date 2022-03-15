from tkinter import *
import os.path # для определения наличия файла
#import tkinter as tk

print("$ import <BILL_checkers_monitor>")

ras = 50

#def setup_monitor():
#    global window
#    global canvas
NAME = "BILL checkers 1.0 demo"

window = Tk()
window.title(NAME)
canvas = Canvas(window,width=12*ras,height=9*ras,bg="white")
canvas.pack()
file = "BILL.ico"
if (os.path.exists(file)):
    window.iconbitmap('BILL.ico')
    
    
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

'''
def click1(event):
    pass

canvas.bind("<Button-1>", click1)
'''
#canvas.bind("<Button-3>", click2)

#view_checkers(area)

#window.mainloop()