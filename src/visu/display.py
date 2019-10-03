#!/usr/bin/python
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim

from class_ant import ant_class

link_color = '#282828'
text_color = '#EEEEEE'
background_color = '#15202b'
default_node_color = '#282828'
ant_colors_list = ['#B61515', '#B66615', '#B6B615', '#66B615', '#15B615', '#15B666', '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566']

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


def draw_ant(position, color):
	ant = plt.plot([position[0]], [position[1]], color = color, marker = '.', markersize = 20.0)
	return (ant)


def create_labels(farm):
	labels_dict = dict([(farm.start,'START'), (farm.end,'END')])
	rooms = farm.rooms
	for room in rooms:
		if room == farm.start or room == farm.end:
			pass
		else:
			room.lower()
			labels_dict[room] = room
	return labels_dict

def update(num, graph, dict_nodes_pos, num_steps, farm, list_ant, fig):
	fig.clear()
	node_size = 500
	# default nodes & tunnels:
	tunnels = nx.draw_networkx_edges(graph, dict_nodes_pos, edge_color=link_color, width=2.0)
	nodes = draw_nodes(graph, farm, dict_nodes_pos, default_node_color, node_size, link_color)
	# draw all the ants:
	for ant in list_ant:
		if num < len(ant.journey):
			draw_ant(ant.journey[num], ant.color)
	labels_dict = create_labels(farm)
	room_names = nx.draw_networkx_labels(graph,
										 dict_nodes_pos,
										 font_size = 8,
										 labels = labels_dict,
										 font_family = 'sans-serif',
										 font_color = text_color)
	fig.set_facecolor(background_color)
	plt.axis('off')


def create_ants(farm, graph, dict_nodes_pos, num_steps):
	list_ant = []
	for num in range (1, int(farm.ants) + 1):
		ant = ant_class(num)
		ant.set_node_path(farm)
		ant.set_location(farm, dict_nodes_pos)
		ant.set_journey(farm, dict_nodes_pos, num_steps)
		ant.color = ant_colors_list[num % 11]
		list_ant.append(ant)
	return (list_ant)

def display(farm):
	"""principal display function"""
	#set the graph
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	dict_nodes_pos = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = 'weight', scale = 1.0)
	
	#generate ants
	num_steps = 5
	list_ant = create_ants(farm, graph, dict_nodes_pos, num_steps)

	#animation
	fig = plt.figure()
	fig.clear()
	ani = anim.FuncAnimation(
			fig,
			update,
			fargs = (graph, dict_nodes_pos, num_steps, farm, list_ant, fig),
			frames = len(farm.moves) * num_steps,
			interval = 350,
			repeat = True)
	plt.show()

# create an empty graph object with no nodes and no edges
# add the list of rooms as nodes to the graph object 
# add the list of links as edges to the graph object 
# create a dict of positions of each node in the graph object, key is name and store tuples of x, y
# set the number of step
# call create ant (return a list of ants)
#   we create a list of ants
#   for each ant we give it a number, path, location, journey and color (check doc in class_ant.py for more info)
#   then we return that list
# we then build a figure with matplotlib plt.figure (it's like the top level component of the window)
# then we call matplotlib animation function
#	
