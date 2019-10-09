#!/usr/bin/python
import networkx as nx

def create_graph(farm):
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	return graph