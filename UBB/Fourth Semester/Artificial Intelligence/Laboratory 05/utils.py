from cmath import sqrt

import tsplib95


def read_network(file_path):
    return tsplib95.load(file_path).get_graph()
