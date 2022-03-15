from copy import deepcopy
from tkinter import *
import os.path

# canvas.create_rectangle(0,0,ras*9,ras*9,fill="#feb") #<=====================================

def image_make(NAME="01.txt"): # , mas1

    def map_a(x,in_min,in_max,out_min,out_max):
        return int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)


    def translater(a):
        array = "0123456789abcdef"
        return str(str(array[map_a(a[0],0,255,0,16)])+str(array[map_a(a[1],0,255,0,16)])+str(array[map_a(a[2],0,255,0,16)]))

    def read_line(S):
        mas = []
        for i in range(160):
            mas.append(0)
        S = list(S)
        #print(S)
        array = "0123456789abcdef"
        array = list(array)
        i = len(S)-2
        I = 160-1
        while (i>=0):
            # a = a*16+array.index(S[i])
            a = [0,0,0]
            if (S[i]!=' '):
                a[0]+=array.index(S[i])
                i-=1
            if (S[i]!=' '):
                a[0]+=array.index(S[i])*16
                i-=1
            if (S[i]!=' '):
                a[1]+=array.index(S[i])#*256
                i-=1
            if (S[i]!=' '):
                a[1]+=array.index(S[i])*16#4096
                i-=1
            if (S[i]!=' '):
                a[2]+=array.index(S[i])#*65536
                i-=1
            if (S[i]!=' '):
                a[2]+=array.index(S[i])*16#1048576
                i-=1
            if (a!=0):
                #mas[I] = add_color(a)
                mas[I] = deepcopy(translater(a)) #deepcopy(filtr(a))
            I-=1
            i-=1
        return(mas)


    if (not os.path.exists(NAME)):
        return "no file"

    file = open(NAME)
    #S = sys.stdin.read() # пропускаем первую строчку
    i = 0
    S = " "
    img = []
    while (len(S)>0):
        S = file.readline()
        #print(S)
        if (len(S)>0):
            img.append(deepcopy(read_line(S)))

    #print("!")
    print(len(img))
    print(len(img[0]))
    print(len(img[0][0]))
    #for i in range (len(img)):
    #    print(len(img[i]))


    file.close()

    del img[len(img)-1] # kostil
    for i in range (len(img)):
        del img[i][len(img[i])-1]

    #NAME = "test"
    K = 5
    out_window = Tk()
    out_window.title(NAME)
    canvas = Canvas(out_window,width=len(img[0])*K,height=len(img)*K,bg="white")
    for i in range (len(img)):
        for u in range (len(img[i])):
            if (img[i][u]):
                canvas.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill=str("#"+str(img[i][u])),outline=str("#"+str(img[i][u])))

    def click1(event):
        x = event.x
        y = event.y
        K = 5
        x = x//K
        y = y//K
        print(x,y,img[y][x])
        for i in range (len(img)):
            for u in range (len(img[i])):
                if (img[i][u]):
                    canvas.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill=str("#"+str(img[i][u])),outline=str("#"+str(img[i][u])))

        '''
        NAME = "test_result"
        K = 5
        out_window_1 = Tk()
        out_window_1.title(NAME)
        canvas = Canvas(out_window_1,width=len(mas1[0])*K,height=len(mas1)*K,bg="white")
        #canvas.create_rectangle(0,0,len(mas1[0])*K,len(mas1)*K,fill="yellow")
        for i in range (len(mas1)):
            for u in range (len(mas1[i])):
                if (mas1[i][u]):
                    canvas.create_rectangle(u*K,i*K,(u+1)*K,(i+1)*K,fill="black")
        '''

    canvas.bind("<Button-1>", click1)

    #print(img)

    canvas.pack()
    out_window.mainloop()
    return "yes"
    # 542 - brown
    # 588 - blue
    # 000 - black

if __name__ == "__main__":
    print(image_make("01.txt"))
