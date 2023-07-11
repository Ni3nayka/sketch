# https://github.com/ahmedfgad/GeneticAlgorithmPython
# pip install pygad

import pygad
import numpy
from time import time

DEBUG_PRINT = False

function_inputs0 = [1,1,1]
function_inputs1 = [1,0,1]
# function_inputs = [1,1,1]
# function_inputs = [1,1,1]
# function_inputs = [1,1,1]

function_inputs = function_inputs0

desired_output = 44

def fitness_func(ga_instance, solution, solution_idx):
    #print(solution_idx)
    output = numpy.sum(solution*function_inputs)
    #fitness = 1.0 / (numpy.abs(output - desired_output) + 0.000001)
    fitness = 1.0 / (numpy.abs(output - desired_output) + 0.000001)
    print(fitness)
    return fitness

fitness_function = fitness_func

def on_start(ga_instance):
    if DEBUG_PRINT: print("on_start()")

def on_fitness(ga_instance, population_fitness):
    if DEBUG_PRINT: print("on_fitness()")

def on_parents(ga_instance, selected_parents):
    if DEBUG_PRINT: print("on_parents()")

def on_crossover(ga_instance, offspring_crossover):
    if DEBUG_PRINT: print("on_crossover()")

def on_mutation(ga_instance, offspring_mutation):
    global function_inputs
    if DEBUG_PRINT: print("on_mutation()")
    if function_inputs==function_inputs0: function_inputs = function_inputs1
    else: function_inputs = function_inputs0

def on_generation(ga_instance):
    if DEBUG_PRINT: print("on_generation()")

def on_stop(ga_instance, last_population_fitness):
    if DEBUG_PRINT: print("on_stop()")

if __name__ == '__main__':
    ga_instance = pygad.GA(num_generations=999,  # 3 # генерация
                        num_parents_mating=6, # 5 - чисто экспериментально = sol_per_pop/2
                        fitness_func=fitness_function,
                        suppress_warnings=True,
                        sol_per_pop=12, # 10 # в одном поколении
                        num_genes=len(function_inputs),
                        on_start=on_start,
                        on_fitness=on_fitness,
                        on_parents=on_parents,
                        on_crossover=on_crossover,
                        on_mutation=on_mutation,
                        on_generation=on_generation,
                        on_stop=on_stop,
                        #parallel_processing=["process", 10],
                        #parallel_processing=["thread", 10],
                        #mutation_type=None
                        )

    t = time()
    ga_instance.run()
    print("run time:",time()-t)

    # Returning the details of the best solution.
    solution, solution_fitness, solution_idx = ga_instance.best_solution()
    print("Parameters of the best solution : {solution}".format(solution=solution))