from copy import deepcopy
from tkinter import *
from time import sleep

# canvas.create_rectangle(0,0,ras*9,ras*9,fill="#feb") #<=====================================

def window_output(mas,mas1): # , mas1
    NAME = "test"
    K = 5
    out_window = Tk()
    out_window.title(NAME)
    canvas = Canvas(out_window,width=160*K,height=120*K,bg="white")
    for i in range (120):
        for u in range (160):
            if (mas[i][u]):
                canvas.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill="black")
    
    #out_window.update()
    #sleep(2)
    #canvas.delete("all")
    
    def click11(event):
        canvas.delete("all")
        canvas.create_rectangle(0,0,len(mas1[0])*K,len(mas1)*K,fill="yellow")
        for i in range (len(mas1)):
            for u in range (len(mas1[i])):
                if (mas1[i][u]):
                    canvas.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill="black")
                    
    def click1(event):
        NAME = "test_result"
        K = 5
        out_window_1 = Tk()
        out_window_1.title(NAME)
        canvas1 = Canvas(out_window_1,width=len(mas1[0])*K,height=len(mas1)*K,bg="white")
        #canvas.create_rectangle(0,0,len(mas1[0])*K,len(mas1)*K,fill="yellow")
        for i in range (len(mas1)):
            for u in range (len(mas1[i])):
                if (mas1[i][u]):
                    canvas1.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill="black")
        canvas1.pack()
        out_window_1.mainloop()
        
    canvas.bind("<Button-1>", click1)
    
    canvas.pack()
    out_window.mainloop()
    
if __name__ == "__main__":
    mas = []
    window_output(mas)