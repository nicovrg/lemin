#!/usr/bin/python
import sys
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import class_directory.class_ant as c_ant

from draw_nodes import draw_nodes
from draw_ants import create_ants, draw_ants
from display_tools import create_labels
from display_options import create_theme

def convert_path_to_links(paths):
	links = []
	all_links = []
	for path in paths:
		for node, next in zip(path, path[1:]):
			link = [node, next]
			links.append(link)
		all_links.append(links)
		links = []
	return (all_links)

def get_ants(farm):
	ants = []
	for move in farm.moves[0]:
		ants.append(move[0])
	return (ants)

def get_paths(farm, list_ant, ants):
	paths = []
	for ant in ants:
		paths.append(list_ant[int(ant) - 1].node_path)
	return (paths)

def remove_links_in_original_list(farm):
	for path in farm.used_links:
		for link in path:
			if link in farm.links:
				farm.links.remove(link)
			link = list(reversed(link))
			if link in farm.links:
				farm.links.remove(link)

def set_links_colors(farm, list_ant):
	nb_path = len(farm.moves[0])
	ants = get_ants(farm)
	paths = get_paths(farm, list_ant, ants)
	farm.used_links = convert_path_to_links(paths)
	remove_links_in_original_list(farm)

def onclick(event):
	print("button: {}".format(event.button))

def on_key(event):
	print("key: {}".format(event.key))
	if (event.key == "a"):
		animation.event_source.stop()

# def call_animation(graph, nodes_coord, steps, farm, list_ant, fig, theme, args):
# 	animation = anim.FuncAnimation(fig, update_image, fargs = (graph, nodes_coord, steps, farm, list_ant, fig, theme, args), frames = len(farm.moves) * steps, interval = 1, repeat = theme["repeat"])
# 	plt.show()

def update_image(num, graph, nodes_coord, steps, farm, list_ant, fig, theme, args):
	fig.clear()
	id_key = fig.canvas.mpl_connect("key_press_event", on_key)
	id_mouse = fig.canvas.mpl_connect("button_press_event", onclick)
	node_size = theme["node_size"]
	tunnels = nx.draw_networkx_edges(graph, nodes_coord, edgelist = farm.links, edge_color = theme["link_color"], width = 2.0)
	for path in farm.used_links:
		nx.draw_networkx_edges(graph, nodes_coord, edgelist = path, edge_color = "#15B6B6", width = 2.0)
	nodes = draw_nodes(graph, farm, nodes_coord, theme["node_color"], node_size, theme["link_color"])
	draw_ants(list_ant, num, theme)
	labels_dict = create_labels(farm, args)
	room_names = nx.draw_networkx_labels(graph, nodes_coord, font_size = 8, labels = labels_dict, font_family = "sans-serif", font_color = theme["text_color"])
	fig.set_facecolor(theme["background_color"])
	plt.axis("off")

def create_graph(farm):
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	return graph

# def display(farm, args):
# 	"""principal display function"""
# 	theme = create_theme(args, farm)
# 	fig = plt.figure(figsize = theme["window_size"])
# 	graph = create_graph(farm)
# 	nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
# 	list_ant = create_ants(farm, graph, nodes_coord, theme["steps"], theme)
# 	set_links_colors(farm, list_ant)
# 	call_animation(graph, nodes_coord, theme["steps"], farm, list_ant, fig, theme, args)

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
#	as update will be call to refresh the drawing, we need to clear our figure
#	we choose the size of the node in px
#	we drawn nodes
#	we draw tunnels
#	we draw ants
#	we draw nodes names 
#	we set the background color
#	we unable the axis

# animation:
#	we call matplotlib.animation.FuncAnimation
#	we give it all the parameters:
#		fig: the image container
#		update_image: the callback function that FuncAnimation will call again and again
#		fargs: the list of args that update_image need
#		frames: the number of frames to draw
#		interval: the time in milisec before drawing each frame
#		repeat: to set if we want to auto restart when all frames are drawn
