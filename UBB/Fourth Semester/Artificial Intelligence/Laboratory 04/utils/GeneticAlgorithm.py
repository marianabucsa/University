from random import randint, sample

from utils.RealChromosome import Chromosome


class GeneticAlgorithm:
    def __init__(self, network):
        self.network = network
        self.chromosome_length = network["noCities"] + 1
        self.population = []
        self.populationSize = 0
        self.results = []
        self.bestResult = {}
        self.bestResultFitness = float('inf')

    def generate_chromosome(self):
        # generates random path from source to destination, gets a chromosome
        chromosome = sample(list(set(range(1, self.network["noCities"] + 1))), self.chromosome_length - 1)
        chromosome.append(chromosome[0])
        return Chromosome(chromosome)

    def generate_population(self, chromosome_number):
        # generates a population of chromosomes
        chromosomes = list()
        for i in range(chromosome_number):
            chromosomes.append(self.generate_chromosome())
        self.population = chromosomes

    def generate_chromosome_source(self, source):
        # generates random path from source to destination, gets a chromosome
        chromosome = sample(list(set(range(1, self.network["noCities"] + 1)) - {source}), self.chromosome_length - 2)
        chromosome.insert(0, source)
        chromosome.append(source)
        return Chromosome(chromosome)

    def generate_population_source(self, chromosome_number, source):
        # generates a population of chromosomes
        chromosomes = list()
        for i in range(chromosome_number):
            chromosomes.append(self.generate_chromosome_source(source))
        self.population = chromosomes

    def crossover(self, first_parent, second_parent):
        # generates child
        first_parent_list = first_parent.get()[:-1]
        second_parent_list = second_parent.get()[:-1]
        cut = randint(0, self.chromosome_length - 1)
        child1 = first_parent_list[0:cut]
        child2 = [item for item in second_parent_list if item not in child1]
        child = child1 + child2
        child.append(child[0])
        return Chromosome(child)

    def fitness(self, chromosome):
        # fitness function
        chromosome_list = chromosome.get()
        return sum([self.network["mat"][i - 1][j - 1] for i, j in zip(chromosome_list[:-1], chromosome_list[1:])])

    def selection(self, previous_generation, current_generation):
        # generates a new population
        previous_generation.extend(current_generation)
        previous_generation.sort(key=lambda x: self.fitness(x))
        self.population = previous_generation[:self.populationSize]
