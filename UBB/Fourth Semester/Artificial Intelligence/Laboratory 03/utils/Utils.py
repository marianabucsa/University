import os
from random import randint

import matplotlib.pyplot as plt
import networkx as nx
import numpy as np


def generateNewValue(lim1, lim2):
    return randint(lim1, lim2)


def binToInt(x):
    val = 0
    # x.reverse()
    for bit in x:
        val = val * 2 + bit
    return val


def read_network(file_path):
    # read the network details
    # input: file_name  os path
    # output: returns network - nx graph
    network = nx.read_gml(file_path, label='id')
    return network


def plot_network(network, communities=[]):
    # plot a network
    # input: network - nx graph
    # output: show the plot of the network
    np.random.seed(123)  # to freeze the graph's view( networks uses a random view)
    pos = nx.spring_layout(network)  # compute graph layout
    plt.figure(figsize=(4, 4))  # image is 8x8 inches
    nx.draw_networkx_nodes(network, pos, node_size=600, cmap=plt.cm.RdYlBu, node_color=communities)
    nx.draw_networkx_edges(network, pos, alpha=0.3)
    plt.show()




