#!/usr/bin/python
import networkx as nx

def highlight_node(node, highlight_color):
	node.set_color(highlight_color)
	node.set_edgecolor(link_color)

def draw_node(graph, dict_nodes_pos, node_name, node_color, node_size, link_color):
	node_list = []
	node_list.append(node_name)
	node = nx.draw_networkx_nodes(graph, dict_nodes_pos, nodelist = node_list, node_color = node_color, node_size = node_size)
	node.set_edgecolor(link_color)
	return (node)

def draw_nodes(graph, farm, dict_nodes_pos, node_color, node_size, link_color):
	nodes = {}
	for name in farm.rooms:
		if name == farm.start or name == farm.end:
			node = draw_node(graph, dict_nodes_pos, name, node_color, node_size * 2.5, link_color)
		else:
			node = draw_node(graph, dict_nodes_pos, name, node_color, node_size, link_color)
		nodes[name] = node
	return (nodes)
