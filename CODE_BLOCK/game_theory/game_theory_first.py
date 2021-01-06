#from arduino_function import *
#arduino_function_version("1.2+") # test version
from copy import deepcopy
'''
# setup
max_sum = 49
heap_1 = 7
heap_2_max = 41
max_go = 4

go_plus = 1 # прибавить
go_mult = 2 # умножить в
'''
'''
# setup
max_sum = 82
heap_1 = 9
heap_2_max = 72
max_go = 3

go_plus = 2 # прибавить
go_mult = 2 # умножить в
'''
# setup
max_sum = 79
heap_1 = 9
heap_2_max = 69
max_go = 3

go_plus = 2 # прибавить
go_mult = 2 # умножить в


# operating
mas = []
heap_2 = 1 # подбираем
#global max_sum, max_go, mas

for i in range (heap_2_max+1):
    mas.append([])

def game(I, heap1, heap2, go, history1):
    global max_sum, max_go, mas, go_plus, go_mult
    history = deepcopy(history1)
    heap_1 = deepcopy(heap1)
    heap_2 = deepcopy(heap2)
        
    if (heap1+heap2>=max_sum):
        mas[I].append(history)  
    elif (max_go>go):
        go += 1
        history.append(1)
        game(I,heap1+go_plus, heap2, go, history)
        del history[len(history)-1]
        history.append(2)
        game(I,heap1*go_mult, heap2, go, history)
        del history[len(history)-1]
        history.append(3)
        game(I,heap1, heap2+go_plus, go, history)
        del history[len(history)-1]
        history.append(4)
        game(I,heap1, heap2*go_mult, go, history)
        del history[len(history)-1]
        
        
    



while (heap_2<=heap_2_max):
    game(heap_2, heap_1,heap_2,0,[])
    heap_2 += 1

for i in range (heap_2_max+1):
    print(i, mas[i])






















#end_program_time()
