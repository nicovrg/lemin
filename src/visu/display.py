#!/usr/bin/python
import networkx as nx
import matplotlib.pyplot as plt

def display(farm):
    graph = nx.Graph()
    graph.add_nodes_from(farm.rooms)
    graph.add_edges_from(farm.links)
    nx.draw(graph, with_labels=True)
    plt.show()
