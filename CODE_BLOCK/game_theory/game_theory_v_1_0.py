#from arduino_function import *
#arduino_function_version("1.2+") # test version
from copy import deepcopy

def operating(max_sum1,heap_11,heap_2_max1,max_go1,go_plus1,go_mult1):
    #setup
    max_sum = deepcopy(max_sum1)
    heap_1 = deepcopy(heap_11)
    heap_2_max = deepcopy(heap_2_max1)
    max_go = deepcopy(max_go1)
    go_plus = deepcopy(go_plus1)
    go_mult = deepcopy(go_mult1)
    # operating
    mas = []
    heap_2 = 1 # подбираем
    #global max_sum, max_go, mas

    for i in range (heap_2_max+1):
        mas.append([])

    def game(I, heap1, heap2, go, history1,max_sum, max_go, mas, go_plus, go_mult):
        history = deepcopy(history1)
        heap_1 = deepcopy(heap1)
        heap_2 = deepcopy(heap2)
            
        if (heap1+heap2>=max_sum):
            mas[I].append(history)  
        elif (max_go>go):
            go += 1
            history.append(1)
            game(I,heap1+go_plus, heap2, go, history,max_sum, max_go, mas, go_plus, go_mult)
            del history[len(history)-1]
            history.append(2)
            game(I,heap1*go_mult, heap2, go, history,max_sum, max_go, mas, go_plus, go_mult)
            del history[len(history)-1]
            history.append(3)
            game(I,heap1, heap2+go_plus, go, history,max_sum, max_go, mas, go_plus, go_mult)
            del history[len(history)-1]
            history.append(4)
            game(I,heap1, heap2*go_mult, go, history,max_sum, max_go, mas, go_plus, go_mult)
            del history[len(history)-1]
            
    while (heap_2<=heap_2_max):
        game(heap_2, heap_1,heap_2,0,[],max_sum, max_go, mas, go_plus, go_mult)
        heap_2 += 1
        
    return mas

def vvod(S=0):
    a = 0
    while (a==0):
        a = input(S)
        if (a.isdigit()):
            return int(a)
        else:
            a = 0
# setup
max_sum = 77
heap_1 = 7
heap_2_max = 69
max_go = 3

go_plus = 1 # прибавить
go_mult = 2 # умножить в

print("Данная программа разработана для решения задач ЕГЭ по информатике на")
print("игровые модели          автор: Бакай Егор      версия программы: 1.0")
print("программа написана на ЯП python3                         Москва 2020")
print("======================================================================")
print("1) Имеется две кучи камней (N(данная) и S(искомая))")
print("2) Действия: добавить в одну из куч A камней или увеличить кол-во ")
print(" камней в B раз в одной из куч по выбору")
print("3) выигрывает тот, при ходе которого сумма камней в кучах больше С")
print("4) Петя всегда ходит первым")
print("5) В ответ идет количество S камней (2-ая куча)")
print("======================================================================")

if (1):
    max_sum = vvod("Введите кол-во камней для победы (окончания игры) ")
    heap_1 = vvod("Введите число камней в первой куче ")
    heap_2_max = vvod("Введите максимальное число камней во второй куче ")
    go_plus = vvod("Введите число, на которое можно увеличить кол-во камней в куче ")
    go_mult = vvod("Введите число, во сколько раз можно увеличить кол-во камней в куче ")
    print("======================================================================")
    

print("Решения:")
print()
print("1) Ваня выиграет после первого неудачного хода Пети (S min):")
mas = operating(max_sum,heap_1,heap_2_max,2,go_plus,go_mult)
S = 0
for i in range (heap_2_max+1):
    if (S==0 and len(mas[i])>0):
        S = i
print("S =", S)
print()
#print("")
###############################################################################
print("2) Значения S, при которых у Пети есть выигрышная стратегия, причём:")
print(" Петя не может выиграть за один ход и Петя может выиграть своим")
print(" вторым ходом независимо от того, как будет ходить Ваня")

mas = operating(max_sum,heap_1,heap_2_max,3,go_plus,go_mult)

for i in range (heap_2_max+1):
    # mas[i] - анализ этой строки
    u = 0
    while (u<len(mas[i])):
        if (len(mas[i][u])==3):
            flag = 0
            array = []
            array.append(mas[i][u])
            u+=1
            while (u<len(mas[i]) and flag==0):
                flag = 1
                if (mas[i][u][0]==array[0][0] and len(mas[i][u])==3):
                    array.append(mas[i][u])
                    u+=1
                    flag = 0
            if (len(array)>=4):
                #print(array)
                array_f = [i,1,1,1,1]
                for y in range (len(array)):
                    for x in range (len(array_f)):
                        if (x==0):
                            x+=1
                        if (array[y][1]==x):
                            array_f[x] = 0
                if (array_f[1]==0 and array_f[2]==0 and array_f[3]==0 and array_f[4]==0):
                    print("S =", i)
                #else:
                #    print(array_f,array)
        else:
            u+=1
    


print()



print("3) S при котором у Вани есть выигрышная стратегия, позволяющая ему") 
print(" выиграть первым или вторым ходом при любой игре Пети и у Вани нет")
print(" стратегии, которая позволит ему гарантированно выиграть первым ходом")

mas = operating(max_sum,heap_1,heap_2_max,4,go_plus,go_mult)

#for i in range (heap_2_max+1):
#    print(i, len(mas[i]))

for i in range (heap_2_max+1):
    # mas[i] - анализ этой строки
    flag = 1
    for u in range(len(mas[i])):
        if (len(mas[i][u])<2):
            flag = 0
            break
    if (flag): ######################################  and i==29
        flag = 0
        for u in range(len(mas[i])):
            if (len(mas[i][u])==2):
                flag = 1
                break
        if (flag): #  and len(mas[i])>=17
            # выбрали варианты победы в два хода
            #print(mas[i])
            array = []
            for u in range (64):
                array.append(1)
            for u in range (len(mas[i])):
                if (len(mas[i][u])==4):
                    array[(mas[i][u][0]-1)*16+(mas[i][u][1]-1)*4+(mas[i][u][2]-1)] = 0
                elif (len(mas[i][u])==2):
                    for x in range(4):
                        array[(mas[i][u][0]-1)*16+(mas[i][u][1]-1)*4+x] = 0
            for u1 in range (4):
                flag = 0
                for u2 in range (4):
                    a = 0
                    for u3 in range (4):
                        a+=array[u1*16+u2*4+u3]
                    if (a==0):
                        flag = 1
                        break
                if (flag):
                    for u2 in range (16):
                        array[u1*16+u2] = 0
                        
            #print(i, sum(array), end=' ')
            #for u in range (64):
            #    print(array[u], end='')
            #print()
            
            if (sum(array)==0):
                print("S =", i)

#print(mas[18])
print()
#print(mas[30])

###############################################################################
print("======================================================================")
#end_program_time()
print("для выхода введите <exit>")
while (1):
    a = input()
    if (a=="exit"):
        break

