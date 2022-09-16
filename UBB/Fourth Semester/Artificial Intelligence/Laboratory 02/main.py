import itertools
import warnings  # for warning control
from sys import argv

import matplotlib.pyplot as plt  # for graphic view
import networkx as nx  # for working with complex networks
import numpy as np  # for working with matrices
from igraph import *

warnings.simplefilter('ignore')


def read_network(file_path):
    # read the network details
    # input: file_name  os path
    # output: returns network - nx graph
    network = nx.read_gml(file_path, label='id')
    return network


def find_removable_edge(G):
    # finds the next removable edge based on the edge betweenness value
    # input : G - a graph in nx format
    # output: next removable edge
    edge_betweenness = nx.edge_betweenness_centrality(G)  # returns a dictionary
    sorted_edge_betweenness = dict(sorted(edge_betweenness.items(), key=lambda item: item[1], reverse=True))
    return list(sorted_edge_betweenness.keys())[0]


def girvan_newman(G, k):
    # girvan newman algorithm
    # input: G - nx graph
    #        k - integer, number of communities searched for
    # output: the connected components after the algorithm is finished
    connected_components = nx.connected_components(G)
    n = nx.number_connected_components(G)
    while n < k:
        r = find_removable_edge(G)
        G.remove_edge(r[0], r[1])
        connected_components = nx.connected_components(G)
        n = nx.number_connected_components(G)
    return connected_components


def community_girvan_newman(G, k):
    # collects all the communities represented by list of nodes
    # input: G - nx graph
    #        k - integer, number of communities searched for
    # output: list of lists of nodes for the communities
    components = []
    for com in girvan_newman(G, k):
        components.append(list(com))
    return components


def greedy_communities_detection_by_tool(network, k):
    # identifies the communities ( by a tool ) and plot them
    # input: network - nx graph
    #        k - integer, number of communities searched for
    # output: list of communities index (for every node)
    top_level_communities = community_girvan_newman(network, k)
    print(top_level_communities)
    communities = [0 for node in range(network.number_of_nodes())]
    index = 1
    for community in sorted(map(sorted, top_level_communities)):
        for node in community:
            communities[node] = index
        index += 1
    return communities


def plot_network(network, communities=[1, 1, 1, 1, 1, 1]):
    # plot a network
    # input: network - nx graph
    # output: show the plot of the network
    np.random.seed(123)  # to freeze the graph's view( networks uses a random view)
    pos = nx.spring_layout(network)  # compute graph layout
    plt.figure(figsize=(4, 4))  # image is 8x8 inches
    nx.draw_networkx_nodes(network, pos, node_size=600, cmap=plt.cm.RdYlBu, node_color=communities)
    nx.draw_networkx_edges(network, pos, alpha=0.3)
    plt.show()


def get_nr_nodes_community(communities):
    # returns the number of nodes in each community
    # input: - tuple of sets of nodes
    # output: returns a list with the number of nodes in each community
    l = []
    for e in communities:
        l.append(len(e))
    return l


def test_community_girvan_newman():
    # test for girvan newman algorithm
    from networkx.algorithms import community
    crt_dir = os.getcwd()
    file_path = os.path.join(crt_dir, 'data/', 'test5.gml')
    network = read_network(file_path)
    com = community_girvan_newman(network.copy(), 2)
    communities_generator = community.girvan_newman(network)
    communities = itertools.islice(communities_generator, 1)
    for last in communities:
        pass
    comm = []
    for e in com:
        comm.append(set(e))
    assert sorted(get_nr_nodes_community(tuple(comm))) == sorted(get_nr_nodes_community(last))
    file_path = os.path.join(crt_dir, 'data/', 'test6.gml')
    network = read_network(file_path)
    com = community_girvan_newman(network.copy(), 5)
    communities_generator = community.girvan_newman(network)
    communities = itertools.islice(communities_generator, 4)
    for last in communities:
        pass
    comm = []
    for e in com:
        comm.append(set(e))
    assert sorted(get_nr_nodes_community(tuple(comm))) == sorted(get_nr_nodes_community(last))


# load and plot a network
crt_dir = os.getcwd()
file_path = os.path.join(crt_dir, 'data/', 'test6.gml')
network = read_network(file_path)
k = int(argv[1])  # numbers of communities searched for
greedy_communities_detection_by_tool(network.copy(), 2)
print('\n')
print('\n')

#test_community_girvan_newman()
#print("Test passed!")
#plot_network(network, greedy_communities_detection_by_tool(network.copy(), k))

