from random import randint


class Chromosome:
    def __init__(self, array_representation):
        self.array_representation = array_representation

    def __repr__(self):
        # chromosome representation in a string format
        return str(self.array_representation)

    def get(self):
        # get chromosome representation
        return self.array_representation

    def __eq__(self, other):
        self.array_representation = other.array_representation

    def __sizeof__(self):
        # size of the chromosome
        return len(self.array_representation)

    def path_value(self):
        # get the value of the path that the chromosome has given
        return sum(self.array_representation)

    def mutation(self):
        # executes mutation for the chromosome( maintain genetic diversity)
        pos1 = randint(1, self.__sizeof__() - 2)
        pos2 = randint(1, self.__sizeof__() - 2)
        aux = self.array_representation[pos1]
        self.array_representation[pos1] = self.array_representation[pos2]
        self.array_representation[pos2] = aux
