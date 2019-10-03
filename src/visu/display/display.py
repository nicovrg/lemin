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

def animation(graph, nodes_coord, steps, farm, list_ant, fig):
	fig.clear()
	ani = anim.FuncAnimation(fig, update_image, fargs = (graph, nodes_coord, steps, farm, list_ant, fig), frames = len(farm.moves) * steps, interval = 200, repeat = False)
	plt.show()

def update_image(num, graph, nodes_coord, steps, farm, list_ant, fig):
	fig.clear()
	node_size = 500
	tunnels = nx.draw_networkx_edges(graph, nodes_coord, edge_color=link_color, width=2.0)
	nodes = draw_nodes(graph, farm, nodes_coord, default_node_color, node_size, link_color)
	draw_ants(list_ant, num)
	labels_dict = create_labels(farm)
	room_names = nx.draw_networkx_labels(graph, nodes_coord, font_size = 8, labels = labels_dict, font_family = 'sans-serif', font_color = text_color)
	fig.set_facecolor(background_color)
	plt.axis('off')

def create_graph(farm):
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	return graph

def display(farm):
	"""principal display function"""
	steps = 5
	fig = plt.figure()
	graph = create_graph(farm)
	nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = 'weight', scale = 1.0)
	list_ant = create_ants(farm, graph, nodes_coord, steps)
	animation(graph, nodes_coord, steps, farm, list_ant, fig)



# display:
#	set the number of steps
#	create the image container using plt.figure
#	get graph object from function create_graph (doc below)
#	get nodes_coord (a dict) from nx,nx.spring_layout (return a dict of nodes positions)
#	get list_ant from create_ants (doc in draw_ants and class ant)
#	call animation (the function using update image as callback - see doc bellow)

# create_graph:
#	create a nx object graph and add it nodes and edges from our farm object rooms and links

# update_image:
#	