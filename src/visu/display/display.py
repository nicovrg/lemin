#!/usr/bin/python
import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.animation as anim
import class_directory.class_ant as c_ant

from draw_nodes import draw_nodes
from draw_ants import create_ants, draw_ants
from display_tools import create_labels
from display_options import create_theme

def onclick(event):
    print("button_press_event: button = {}, x1 = {}, y1 = {}, x2 = {}, y2 = {}".format(event.button, event.x, event.y, event.xdata, event.ydata))

def on_key(event, theme):
	print("key_press_event: key = {}, x = {}, y = {}".format(event.key, event.xdata, event.ydata))
	return event.key, theme
	# if (event.key == "a"):
	# 	animation.event_source.start()
		# print "CA MARCHE!!!"
		# theme["node_color"] = "#B61515"

def animation(graph, nodes_coord, steps, farm, list_ant, fig, theme, args):
	id_key = fig.canvas.mpl_connect("key_press_event", on_key)
	id_mouse = fig.canvas.mpl_connect("button_press_event", onclick)
	test = on_key
	if (test == "a"):
		print "CA MARCHE!!!"
		animation.event_source.stop()
		# animation.event_source.start()
	animation = anim.FuncAnimation(fig, update_image, fargs = (graph, nodes_coord, steps, farm, list_ant, fig, theme, args), frames = len(farm.moves) * steps, interval = 200, repeat = theme["repeat"])
	plt.show()

def update_image(num, graph, nodes_coord, steps, farm, list_ant, fig, theme, args):
	fig.clear()
	node_size = theme["node_size"]
	tunnels = nx.draw_networkx_edges(graph, nodes_coord, edge_color = theme["link_color"], width = 2.0)
	nodes = draw_nodes(graph, farm, nodes_coord, theme["node_color"], node_size, theme["link_color"])
	draw_ants(list_ant, num)
	labels_dict = create_labels(farm, args)
	room_names = nx.draw_networkx_labels(graph, nodes_coord, font_size = 8, labels = labels_dict, font_family = "sans-serif", font_color = theme["text_color"])
	fig.set_facecolor(theme["background_color"])
	plt.axis("off")

def create_graph(farm):
	graph = nx.Graph()
	graph.add_nodes_from(farm.rooms)
	graph.add_edges_from(farm.links)
	return graph

def display(farm, args):
	"""principal display function"""
	fig = plt.figure()
	theme = create_theme(args)
	graph = create_graph(farm)
	nodes_coord = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
	list_ant = create_ants(farm, graph, nodes_coord, theme["steps"], theme)
	animation(graph, nodes_coord, theme["steps"], farm, list_ant, fig, theme, args)

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
