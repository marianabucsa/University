from random import randint, random, choices


class Ant:
    def __init__(self, network, alphaParameter, betaParameter, probability, pheromones):
        self.network = network
        self.alphaParameter = alphaParameter
        self.betaParameter = betaParameter
        self.probability = probability
        self.path = [str(randint(1, self.network.number_of_nodes()))]  # add first node
        self.pheromoneL = [[0 for _ in range(network.number_of_nodes())] for _ in
                           range(network.number_of_nodes())]
        self.pheromones = pheromones

    def path_distance(self):
        dist = 0
        for i in range(len(self.path) - 1):
            dist += self.network.get_edge_data(int(self.path[i]), int(self.path[i + 1]))['weight']
        dist += self.network.get_edge_data(int(self.path[len(self.path) - 1]), int(self.path[0]))['weight']
        return dist

    def get_next_city(self):
        city_choices = []
        total = 0.0
        for city_index in range(1, self.network.number_of_nodes() + 1):
            city_choices.append(0)
            if str(city_index) not in self.path:
                if self.pheromones[int(self.path[-1]) - 1][city_index - 1] == 0:  # if the city was not visited
                    t = 1
                else:
                    t = self.pheromones[int(self.path[-1]) - 1][
                            city_index - 1] ** self.alphaParameter  # if the city was visited change pheromone by alpha parameter

                if self.network.get_edge_data(int(self.path[-1]) - 1, city_index - 1):
                    if self.network.get_edge_data(int(self.path[-1]) - 1, city_index - 1)['weight'] != 0:
                        n = (1 / self.network.get_edge_data(int(self.path[-1]) - 1, city_index - 1)[
                            'weight']) ** self.betaParameter
                    else:
                        n = 1
                else:
                    n = 1
                city_choices[-1] = t * n
                total += city_choices[-1]

        p = random()
        # probability for city choosing
        if p < self.probability:
            maxim = 0
            city = 0
            for index in range(self.network.number_of_nodes()-1):
                if city_choices[index] > maxim:
                    maxim = city_choices[index]
                    city = index
            if (city+1) not in self.path:
                self.path.append(str(city+1))
        else:
            cities = []
            weights = []
            for j in range(self.network.number_of_nodes()):
                if city_choices[j] != 0:
                    cities.append(j)
                    weights.append(city_choices[j] / total)

            if (len(weights) != 0):
                city = choices(cities, weights=weights)[0]
                self.path.append(str(city + 1))

        self.pheromoneL[int(self.path[-2]) - 1][int(self.path[-1]) - 1] = 1
        self.pheromoneL[int(self.path[-1]) - 1][int(self.path[-2]) - 1] = 1

    def return_to_start(self):
        self.path.append(self.path[0])
        self.pheromoneL[int(self.path[-2]) - 1][int(self.path[-1]) - 1] = 1
        self.pheromoneL[int(self.path[-1]) - 1][int(self.path[-2]) - 1] = 1
