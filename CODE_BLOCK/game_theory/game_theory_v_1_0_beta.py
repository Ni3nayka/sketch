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


# setup
max_sum = 79
heap_1 = 9
heap_2_max = 69
max_go = 3

go_plus = 2 # прибавить
go_mult = 2 # умножить в

print("Данная программа разработана для решения задач ЕГЭ по информатике на")
print("игровые модели:              Бакай Егор     Москва 2020    v1.0 beta")
print("======================================================================")
print("Имеется две кучи камней (N(данная) и S(искомая))")
print("действия: добавить в одну из куч A камней или увеличить кол-во камней")
print(" в B раз в одной из куч по выбору")
print("выигрывает тот, при ходе которого сумма камней в кучах больше С")
print("Петя всегда ходит первым")
print("В ответ идет количество S камней (2-ая куча)")
print("======================================================================")

if (1):
    max_sum = int(input("введите кол-во камней для победы (окончания игры) "))
    heap_1 = int(input("введите число камней в первой куче "))
    heap_2_max = int(input("введите максимальное число камней во второй куче "))
    #max_go = input("введите число,")
    go_plus = int(input("введите число, на которое можно увеличить кол-во камней в куче "))
    go_mult = int(input("введите число, во сколько раз можно увеличить кол-во камней в куче "))
    print("======================================================================")
    

print("решения:")
print("Ваня выиграет после неудачного хода Пети (S min):")
mas = operating(max_sum,heap_1,heap_2_max,2,go_plus,go_mult)
S = 0
for i in range (heap_2_max+1):
    if (S==0 and len(mas[i])>0):
        S = i
print("S =", S)
#print("")
#print("")

#for i in range (heap_2_max+1):
#    print(i, mas[i])






















print("======================================================================")
#end_program_time()
input("Для выхода нажмите Enter")
