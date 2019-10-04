#!/usr/bin/python
import networkx as nx

def draw_node(graph, nodes_coord, node_name, node_color, node_size, link_color):
	node_list = []
	node_list.append(node_name)
	node = nx.draw_networkx_nodes(graph, nodes_coord, nodelist = node_list, node_color = node_color, node_size = node_size)
	node.set_edgecolor(link_color)
	return (node)

def draw_nodes(graph, farm, nodes_coord, node_color, node_size, link_color):
	nodes = {}
	for name in farm.rooms:
		if name == farm.start or name == farm.end:
			node = draw_node(graph, nodes_coord, name, node_color, node_size * 2.5, link_color)
		else:
			node = draw_node(graph, nodes_coord, name, node_color, node_size, link_color)
		nodes[name] = node
	return (nodes)

# draw nodes:
#	create a list of nodes
#	for each room we call draw_node
#	if the room is start / end we give different parameters to make it bigger

# draw node:
#	we call networkx method draw_networkx_nodes to draw the node
