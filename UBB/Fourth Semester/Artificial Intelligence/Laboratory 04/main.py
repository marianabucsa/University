import os
from random import sample

from utils.GeneticAlgorithm import GeneticAlgorithm
from utils.Utils import read_network


def main(genetic_network, generations_number, population_size):
    gen_index = 1  # from first generation
    genetic_network.generate_population(population_size)  # generate initial population
    genetic_network.populationSize = population_size

    while gen_index <= generations_number:
        gen_index += 1
        p = 1
        new_population = list()
        while p <= genetic_network.populationSize:
            p += 1
            parents = sample(range(genetic_network.populationSize), 2)
            child = genetic_network.crossover(genetic_network.population[parents[0]],
                                              genetic_network.population[parents[1]])
            child.mutation()
            fit = genetic_network.fitness(child)
            genetic_network.results.append((child, fit))
            new_population.append(child)
            if child.__repr__() not in genetic_network.bestResult.keys() and genetic_network.bestResultFitness == fit:
                genetic_network.bestResult[child.__repr__()] = fit
            else:
                if genetic_network.bestResultFitness > fit:
                    genetic_network.bestResult.clear()
                    genetic_network.bestResult[child.__repr__()] = fit
                    genetic_network.bestResultFitness = fit
        genetic_network.selection(genetic_network.population, new_population)
    return genetic_network.bestResult


crt_dir = os.getcwd()

file_path = os.path.join(crt_dir, 'TSP/', 'easy_01_tsp.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 100, 50)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_redusa_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 100, 50)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_redusa_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 100, 50)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_medie_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 500, 100)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_medie_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 500, 100)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_mare_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 1000, 500)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_mare_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main(genetic_network, 1000, 500)
for item in result.items():
    print(item)


def main_2(genetic_network, generations_number, population_size, source):
    gen_index = 1  # from first generation
    genetic_network.generate_population_source(population_size, source)  # generate initial population
    genetic_network.populationSize = population_size

    while gen_index <= generations_number:
        gen_index += 1
        p = 1
        new_population = list()
        while p <= genetic_network.populationSize:
            p += 1
            parents = sample(range(genetic_network.populationSize), 2)
            child = genetic_network.crossover(genetic_network.population[parents[0]],
                                              genetic_network.population[parents[1]])
            child.mutation()
            fit = genetic_network.fitness(child)
            genetic_network.results.append((child, fit))
            new_population.append(child)
            if child.__repr__() not in genetic_network.bestResult.keys() and genetic_network.bestResultFitness == fit:
                genetic_network.bestResult[child.__repr__()] = fit
            else:
                if genetic_network.bestResultFitness > fit:
                    genetic_network.bestResult.clear()
                    genetic_network.bestResult[child.__repr__()] = fit
                    genetic_network.bestResultFitness = fit
        genetic_network.selection(genetic_network.population, new_population)
    return genetic_network.bestResult


print("\n")
print("=======================================")
print("============= Source = 1 ==============")
print("=======================================")
print("\n")
file_path = os.path.join(crt_dir, 'TSP/', 'easy_01_tsp.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 100, 50, 1)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_redusa_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 100, 50, 1)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_redusa_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 100, 50, 1)
for item in result:
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_medie_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 500, 100, 1)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_medie_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 500, 100, 1)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_mare_1.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 1000, 500, 1)
for item in result.items():
    print(item)

print("\n")
print("=======================================")
print("=======================================")
print("\n")

file_path = os.path.join(crt_dir, 'TSP/', 'dificultate_mare_2.txt')
network = read_network(file_path)
genetic_network = GeneticAlgorithm(network)
result = main_2(genetic_network, 1000, 500, 1)
for item in result.items():
    print(item)
