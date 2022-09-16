import os

from aco import Aco
from utils import read_network

crt_dir = os.getcwd()

noOfAnts = 30
evaporation = 0.3
alphaParameter = 1
betaParameter = 5
probability = 0.6
noOfIterations = 10

file_path = os.path.join(crt_dir, 'data/', 'dj38.tsp')

network = read_network(file_path)

aco = Aco(network, noOfAnts, evaporation, alphaParameter, betaParameter, probability)

dinamic_graph = False
best_final = 0
print("dj38.tsp ")
for g in range(noOfIterations):
    aco.initialize()

    for i in range(1, network.number_of_nodes()):
        aco.ant_next_city()

    aco.ant_last_city()
    pheromones = aco.update_pheromones()
    best_ant = aco.best_ant()

    if g == 0:
        best_final = best_ant
        best_iteration = g
    elif best_ant.path_distance() <= best_final.path_distance() and len(best_ant.path) <= network.number_of_nodes()+1:
        best_final = best_ant
        best_iteration = g

    if dinamic_graph:
        aco.dinamic_graph_change()


print("The best distance " + str(best_final.path_distance()) + " with path " + str(best_final.path))


file_path = os.path.join(crt_dir, 'data/', 'wi29.tsp')
network = read_network(file_path)

aco = Aco(network, noOfAnts, evaporation, alphaParameter, betaParameter, probability)

dinamic_graph = False
best_final =0

print("wi29.tsp ")
for g in range(noOfIterations):
    aco.initialize()

    for i in range(1, network.number_of_nodes()):
        aco.ant_next_city()

    aco.ant_last_city()
    pheromones = aco.update_pheromones()
    best_ant = aco.best_ant()

    if g == 0:
        best_final = best_ant
        best_iteration = g
    elif best_ant.path_distance() <= best_final.path_distance() and len(best_ant.path) <= network.number_of_nodes()+1:
        best_final = best_ant
        best_iteration = g

    if dinamic_graph:
        aco.dinamic_graph_change()


print("The best distance " + str(best_final.path_distance()) + " with path " + str(best_final.path))

file_path = os.path.join(crt_dir, 'data/', 'dj38.tsp')

network = read_network(file_path)

aco = Aco(network, noOfAnts, evaporation, alphaParameter, betaParameter, probability)

dinamic_graph = True
best_final =0
print("dj38.tsp Dinamic")
for g in range(noOfIterations):
    aco.initialize()

    for i in range(1, network.number_of_nodes()):
        aco.ant_next_city()

    aco.ant_last_city()
    pheromones = aco.update_pheromones()
    best_ant = aco.best_ant()

    if g == 0:
        best_final = best_ant
        best_iteration = g
    elif best_ant.path_distance() <= best_final.path_distance() and len(best_ant.path) <= network.number_of_nodes()+1:
        best_final = best_ant
        best_iteration = g

    if dinamic_graph:
        aco.dinamic_graph_change()


print("The best distance " + str(best_final.path_distance()) + " with path " + str(best_final.path))


file_path = os.path.join(crt_dir, 'data/', 'wi29.tsp')
network = read_network(file_path)

aco = Aco(network, noOfAnts, evaporation, alphaParameter, betaParameter, probability)

dinamic_graph = True
best_final =0
print("wi29.tsp Dinamic")
for g in range(noOfIterations):
    aco.initialize()

    for i in range(1, network.number_of_nodes()):
        aco.ant_next_city()

    aco.ant_last_city()
    pheromones = aco.update_pheromones()
    best_ant = aco.best_ant()

    if g == 0:
        best_final = best_ant
        best_iteration = g
    elif best_ant.path_distance() <= best_final.path_distance() and len(best_ant.path) <= network.number_of_nodes()+1:
        best_final = best_ant
        best_iteration = g

    if dinamic_graph:
        aco.dinamic_graph_change()


print("The best distance " + str(best_final.path_distance()) + " with path " + str(best_final.path))
