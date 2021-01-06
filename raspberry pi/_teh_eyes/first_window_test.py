from tkinter import *

def qwerty():
    print("yes");

def PDU():
    def PDU_forward():  
        print("PDU_forward");

    def PDU_backward():  
        print("PDU_backward");

    def PDU_stop():  
        print("PDU_stop");

    def PDU_left():  
        print("PDU_left");

    def PDU_right():  
        print("PDU_right");

    window = Tk()  
    window.title("teh_eyes_PDU")
    window.geometry('120x70')

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

    window.mainloop()


#print("PDU end");

PDU();


