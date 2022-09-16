import os
from collections import Counter

import networkx as nx

from utils.GeneticAlgorithm import GA
from utils.RealChromosome import Chromosome
from utils.Utils import plot_network, read_network


def first_modularity(communities):
    noNodes = network.number_of_nodes()
    mat = nx.to_numpy_matrix(network)
    M = 2 * network.number_of_edges()
    Q = 0.0
    for i in range(0, noNodes):
        for j in range(0, noNodes):
            if communities[i] == communities[j]:
                Q += (mat.item((i, j)) - network.degree[i] * network.degree[j] / M)
    return (Q * 1) / (4 * M)


def main(k):
    # initialise de GA parameters
    gaParam = {'popSize': 100, 'noGen': 50}
    # problem parameters
    problParam = {'min': 1, 'max': k, 'function': first_modularity,
                  'noDim': network.number_of_nodes()}

    ga = GA(gaParam, problParam)
    ga.initialisation()
    ga.evaluation()

    best_real_chromosome = Chromosome(problParam)

    allBestFitnesses = []
    allAvgFitnesses = []
    generations = []

    for g in range(gaParam['noGen']):
        # plotting preparation
        bestSol = ga.bestChromosome()
        # allBestFitnesses.append(bestSolY)
        # allAvgFitnesses.append(sum(allPotentialSolutionsY) / len(allPotentialSolutionsY))
        generations.append(g)

        # logic alg
        ga.oneGeneration()
        # ga.oneGenerationElitism()
        # ga.oneGenerationSteadyState()

        if bestSol.fitness > best_real_chromosome.fitness:
            best_real_chromosome = bestSol

        print('Best solution in generation ' + str(g) + ': communities number ' + str(
            len(Counter(bestSol.repres).keys())) + ' : Fitness f(x) = ' + str(
            bestSol.fitness) + ' : Representation  x = ' + str(bestSol.repres))

    print('Overall result: ')
    print("Communities: " + str(len(Counter(best_real_chromosome.repres).keys())))
    print("Best representation: " + str(best_real_chromosome.repres) + '\n')
    print("Best fitness: " + str(best_real_chromosome.fitness) + '\n')

    plot_network(network, best_real_chromosome.repres)


crt_dir = os.getcwd()
file_path = os.path.join(crt_dir, 'data/dolphins', 'dolphins.gml')
network = read_network(file_path)
main(2)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/football', 'football.gml')
network = read_network(file_path)
main(12)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/karate', 'karate.gml')
network = read_network(file_path)
main(2)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/krebs', 'krebs.gml')
network = read_network(file_path)
main(3)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/', 'test3.gml')
network = read_network(file_path)
main(3)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/', 'test4.gml')
network = read_network(file_path)
main(5)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/', 'test5.gml')
network = read_network(file_path)
main(2)
print('******* ')
print('******* ')
print('******* ')

file_path = os.path.join(crt_dir, 'data/', 'test6.gml')
network = read_network(file_path)
main(7)
