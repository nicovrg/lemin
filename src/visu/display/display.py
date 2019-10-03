#!/usr/bin/python
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import class_directory.class_ant as c_ant

from draw_nodes import draw_nodes
from draw_ants import create_ants, draw_ants
from display_tools import create_labels

link_color = '#101010'
text_color = '#EEEEEE'
background_color = '#15202b'
default_node_color = '#282828'

def update(num, graph, dict_nodes_pos, num_steps, farm, list_ant, fig):
	fig.clear()
	node_size = 500
	tunnels = nx.draw_networkx_edges(graph, dict_nodes_pos, edge_color=link_color, width=2.0)
	nodes = draw_nodes(graph, farm, dict_nodes_pos, default_node_color, node_size, link_color)
	draw_ants(list_ant, num)
	labels_dict = create_labels(farm)
	room_names = nx.draw_networkx_labels(graph, dict_nodes_pos, font_size = 8, labels = labels_dict, font_family = 'sans-serif', font_color = text_color)
	fig.set_facecolor(background_color)
	plt.axis('off')

def create_graph(farm):
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	return graph

def display(farm):
	"""principal display function"""
	graph = create_graph(farm)
	dict_nodes_pos = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = 'weight', scale = 1.0)
	
	num_steps = 5
	list_ant = create_ants(farm, graph, dict_nodes_pos, num_steps)

	fig = plt.figure()
	fig.clear()
	ani = anim.FuncAnimation(fig, update, fargs = (graph, dict_nodes_pos, num_steps, farm, list_ant, fig), frames = len(farm.moves) * num_steps, interval = 200, repeat = False)
	plt.show()

# create an empty graph object with no nodes and no edges
# add the list of rooms as nodes to the graph object 
# add the list of links as edges to the graph object 
# create a dict of positions of each node in the graph object, key is name and store tuples of x, y
# set the number of step

# call create ant (return a list of ants)
#	we create a list of ants
#   for each ant we give it a number, path, location, journey and color (check doc in class_ant.py for more info)
#   then we return that list

# we then build a figure with matplotlib plt.figure (it's like the top level component of the window)

# then we call matplotlib animation function
#	we give it the fig object, the name of the callback function, the parameters to pass to that function, the number of frames to draw, the intervall between frames in milliseconds, a bool to say to loop
#	
#	
#	
#	