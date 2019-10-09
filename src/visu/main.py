#!/usr/bin/python
import sys
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import class_directory.class_ant as c_ant

import dirty_import
from dirty_import import parse, display, usage, lib_trip, image_one, draw_subplots, graph_one, graph_two, graph_three, graph_four, figure_one, figure_two, figure_three, print_event, draw_line, draw_rectangle, draw_nodes, create_ants, draw_ants, create_labels, create_theme

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


def check_args(args, option):
	for arg in args:
		if arg == option:
			return True
	return False

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


args = sys.argv
try:
	test = args[1]
	if check_args(args, "-visu") == True:
		farm = parse.parse(args)
		theme = create_theme(args, farm)
		graph = create_graph(farm)
		nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
		list_ant = create_ants(farm, graph, nodes_coord, theme["steps"], theme)
		set_links_colors(farm, list_ant)
		fig = plt.figure(figsize = theme["window_size"])
		animation = anim.FuncAnimation(fig, update_image, fargs = (graph, nodes_coord, theme["steps"], farm, list_ant, fig, theme, args), frames = len(farm.moves) * theme["steps"], interval = 1, repeat = theme["repeat"])
		plt.show()
	if check_args(args, "-lib_trip") == True:
		lib_trip.lib_trip(args)
	if check_args(args, "-help") == True:
		usage.usage()
except IndexError:
	usage.usage()


# theme = create_theme(args)
# fig = plt.figure(figsize = theme["window_size"])
# graph = create_graph(farm)
# nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
# list_ant = create_ants(farm, graph, nodes_coord, theme["steps"], theme)
# animation(graph, nodes_coord, theme["steps"], farm, list_ant, fig, theme, args)

# def onclick(event):
# 	print("button_press_event: button = {}, x1 = {}, y1 = {}, x2 = {}, y2 = {}".format(event.button, event.x, event.y, event.xdata, event.ydata))

# main
#	we get the command line arguments

#	visu_or_libtrip
#		we try to copy argv[1] in a variable
#		if it works, we don't had IndexError we check if user want to use visu, trip with matplotlib or see help
#		else we capture the error and display usage

# main call display
#	display:
#		parse: ->
#			create and object farm
#			precompile regex we will use for parsing 
#			read on lemin output on stdin to fill farm
#		return the object farm

#	retrun in display:
#		set the number of steps
#		create the image container using plt.figure
#		get graph object from function create_graph (doc below)
#		get nodes_coord (a dict) from nx,nx.spring_layout (return a dict of nodes positions)
#		get list_ant from create_ants (doc in draw_ants and class ant)
#		call animation (the function using update image as callback - see doc bellow)

# options: 
#	-theme: add more theme
#	-path: highlight paths
#	-zoom: events
#	-background_image:

# pause drawing function

# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -blue_theme -darkblue_background -orange_ant -purple_nodes -red_links -help
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -lib_trip -draw_subplots -graph_one -graph_two -graph_three -graph_four -figure_one -figure_two -print_event -draw_line -draw_rectangle -image_one