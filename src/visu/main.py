#!/usr/bin/python
import sys
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import class_directory.class_ant as c_ant

from import_dirty import *

def on_click(event):
	print("button: {}".format(event.button))

def on_key(event):
	print("key: {}\tevent source: {}".format(event.key, animation.event_source))
	global anim_running
	if (event.key == "p"):
		if anim_running:
			animation.event_source.stop()
			anim_running = False
		else:
			animation.event_source.start()
			anim_running = True
	if (event.key == "o"):
		theme["background_color"] = "#15B6B6"

def callback_draw(num, graph, nodes_coord, steps, farm, list_ant, fig, theme, args):
	fig.clear()
	id_key = fig.canvas.mpl_connect("key_press_event", on_key)
	id_mouse = fig.canvas.mpl_connect("button_press_event", on_click)
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

args = sys.argv
try:
	test = args[1]
	if check_args(args, "-visu") == True:
		farm = parse(args)
		theme = create_theme(args, farm)
		graph = create_graph(farm)
		nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
		list_ant = create_ants(farm, graph, nodes_coord, theme["steps"], theme)
		set_links_colors(farm, list_ant)
		fig = plt.figure(figsize = theme["window_size"])
		anim_running = True
		animation = anim.FuncAnimation(fig, callback_draw, fargs = (graph, nodes_coord, theme["steps"], farm, list_ant, fig, theme, args), frames = len(farm.moves) * theme["steps"], interval = 1, repeat = theme["repeat"])
		plt.show()
	if check_args(args, "-lib_trip") == True:
		lib_trip(args)
	if check_args(args, "-help") == True:
		usage()
except IndexError:
	usage()


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