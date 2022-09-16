from random import randint

import networkx as nx

from ant import Ant


class Aco:
    def __init__(self, network, noOfAnts, evaporation, alphaParameter, betaParameter, probability):
        self.network = network
        self.noOfAnts = noOfAnts
        self.evaporation = evaporation
        self.alphaParameter = alphaParameter
        self.betaParameter = betaParameter
        self.probability = probability
        self.pheromones = [[0 for _ in range(network.number_of_nodes())] for _ in
                           range(network.number_of_nodes())]  # initialize pheromones with 0
        self.ants = []

    def initialize(self):
        for _ in range(self.noOfAnts):
            ant = Ant(self.network, self.alphaParameter, self.betaParameter, self.probability, self.pheromones)
            self.ants.append(ant)

    def ant_next_city(self):
        for ant in self.ants:
            ant.get_next_city()

    def ant_last_city(self):
        for ant in self.ants:
            ant.return_to_start()

    def best_ant(self):
        index = 0
        while len(self.ants[index].path) > self.network.number_of_nodes() + 1 and index <= len(self.ants[index].path):
            index += 1
        best = self.ants[index]
        for ant in self.ants:
            if len(ant.path) <= self.network.number_of_nodes() + 1:
                if ant.path_distance() < best.path_distance():
                    best = ant
        return best

    def update_pheromones(self):
        for i in range(self.network.number_of_nodes()):
            for j in range(self.network.number_of_nodes()):
                new_pheromone = 0
                for ant in self.ants:
                    if ant.pheromoneL[i][j] == 1:
                        new_pheromone += 1 / ant.path_distance()
                self.pheromones[i][j] = (1 - self.evaporation) * self.pheromones[i][
                    j] + self.evaporation * new_pheromone
        return self.pheromones

    def dinamic_graph_change(self):
        x = randint(1, self.network.number_of_nodes())
        y = randint(1, self.network.number_of_nodes())

        while x == y and self.network.get_edge_data(x, y)['weight'] == 0:
            y = randint(1, self.network.number_of_nodes())

        print("Dynamic graph was changed")

        nx.set_edge_attributes(self.network, {(x, y): {"weight": 0}})
        nx.set_edge_attributes(self.network, {(y, x): {"weight": 0}})

        self.pheromones[x - 1][y - 1] = 0
        self.pheromones[y - 1][x - 1] = 0
