import math
import random
import sys


def euclidean_distance(x, y):
    dist = 0
    for i in range(len(x)):
        dist += math.pow(x[i] - y[i], 2)
    return math.sqrt(dist)


class K_Means:
    def __init__(self, data):
        self.data = data
        self.means = []
        self.clusters = []

    def initialize_means(self):
        indexes = [i for i in range(len(self.data.train_inputs))]
        random_ind = random.sample(indexes, 2)
        for i in random_ind:
            self.means.append(self.data.train_inputs[i])

    def obtain_clusters(self):
        self.clusters = [[] for _ in range(len(self.means))]
        for i in range(len(self.data.test_inputs)):
            index = self.classify(self.data.test_inputs[i])
            self.clusters[index].append(i)

    def update_mean(self, n, mean):
        new_mean = [0 for _ in range(len(mean))]
        for i in range(len(self.data.train_inputs)):
            for j in range(len(self.data.train_inputs[i])):
                new_mean[j] += self.data.train_inputs[i][j]
        for i in range(len(new_mean)):
            if n != 0:
                new_mean[i] /= n
        return new_mean

    def calculate_means(self, max_iterations=10):
        self.initialize_means()
        cluster_sizes = [0 for _ in range(len(self.means))]
        belongs_to = [0 for _ in range(len(self.data.train_inputs))]
        for iteration in range(max_iterations):
            for i in range(len(self.data.train_inputs)):
                belongs_to[i] = self.classify(self.data.train_inputs[i])
                cluster_sizes[belongs_to[i]] += 1
            for index in range(len(self.means)):
                self.means[index] = self.update_mean(cluster_sizes[index], self.means[index])

    def classify(self, item):
        index = -1
        minimum = sys.maxsize
        for i in range(len(self.means)):
            distance = euclidean_distance(item, self.means[i])
            if distance < minimum:
                minimum = distance
                index = i
        return index
