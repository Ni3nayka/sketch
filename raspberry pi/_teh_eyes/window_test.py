from tkinter import *
from tkinter.ttk import Combobox
from tkinter.ttk import Checkbutton
from tkinter.ttk import Radiobutton 

def clicked():  
    #lbl.configure(text="Я же просил...")
    res = "Я же просил... {}".format(txt.get())  
    lbl.configure(text=res) 

def clicked1():
   lbl = Label(window, text="qwerty")
   lbl.grid(column=5, row=1)

def clicked2():
   lbl = Label(window, text="qwerty")
   lbl.grid(column=5, row=2)
 
def clicked3():  
    lbl.configure(text=selected.get())  

# создать окно
window = Tk()  
window.title("Добро пожаловать в приложение PythonRu")

# задать размеры окна
window.geometry('800x480')

# вывести текст (такого-то размера)
lbl = Label(window, text="Привет")
#lbl = Label(window, text="Привет", font=("Arial Bold", 50)) # сделать определенного шрифта
lbl.grid(column=0, row=0) # где отображаться в окне (x => column, y => row)

# создать кнопку
#btn = Button(window, text="Не нажимать!")
#btn = Button(window, text="Не нажимать!", bg="black", fg="red") # сделать определенного цвета
btn = Button(window, text="Не нажимать!", command=clicked) # если нажата кнопка, то перейти к данной подпрограмме
btn.grid(column=1, row=0) 

# добавить текстовый ввод
txt = Entry(window,width=10)  
txt.grid(column=2, row=0)
#txt.focus() # хз как работает и для чего оно
#txt = Entry(window,width=10, state='disabled') # Отключить виджет ввода

# Добавление виджета Combobox
combo = Combobox(window)  
combo['values'] = (1, 2, 3, 4, 5, "Текст")  
combo.current(1)  # установите вариант по умолчанию  
combo.grid(column=3, row=0)
eee = combo.get() # получить элемент select, но хз как запустить

# Добавление виджета Checkbutton
chk_state = BooleanVar()  
chk_state.set(True)  # задайте проверку состояния чекбокса  
chk = Checkbutton(window, text='Выбрать', var=chk_state)  
chk.grid(column=4, row=0)

# Добавление виджетов Radio Button
selected = IntVar()  
rad1 = Radiobutton(window,text='Первый', value=1, variable=selected)  
rad2 = Radiobutton(window,text='Второй', value=2, variable=selected)  
rad3 = Radiobutton(window,text='Третий', value=3, variable=selected)  
btn = Button(window, text="Клик", command=clicked3)  
lbl = Label(window)  
rad1.grid(column=0, row=1)  
rad2.grid(column=1, row=1)  
rad3.grid(column=2, row=1)  
btn.grid(column=3, row=1)  
lbl.grid(column=4, row=1)
# или
rad1 = Radiobutton(window, text='Первая', value=1, command=clicked2) 
rad2 = Radiobutton(window, text='Второй', value=2)  
rad3 = Radiobutton(window, text='Третий', value=3)  
rad1.grid(column=0, row=2)  
rad2.grid(column=1, row=2)  
rad3.grid(column=2, row=2)

# Добавление SpinBox
#var = IntVar() # если надо установить значение по умолчанию
#var.set(36)
#spin = Spinbox(window, from_=0, to=100, width=5, textvariable=var)
spin = Spinbox(window, from_=0, to=100, width=5)  
spin.grid(column=0, row=3)  
#spin = Spinbox(window, values=(3, 8, 11), width=5) # вместо использования всего диапазона


#просто должно быть
window.mainloop()



