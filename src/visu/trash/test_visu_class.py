# #!/usr/bin/python
# import sys
# import networkx as nx
# import matplotlib.pyplot as plt
# import matplotlib.animation as anim
# import class_directory.class_ant as c_ant

# from draw_nodes import draw_nodes
# from draw_ants import create_ants, draw_ants
# from display_tools import create_labels
# from display_options import create_theme

# def create_graph(farm):
# 	graph = nx.Graph()
# 	graph.add_nodes_from(farm.rooms)
# 	graph.add_edges_from(farm.links)
# 	return graph

# def display(farm, args):
# 	visu = Visu_class(args, farm)

# class Visu_class:

# 	def __init__(self, args, farm):
# 		self.args = args
# 		self.farm = farm
# 		self.theme = create_theme(self.args)
# 		self.graph = create_graph(self.farm)
# 		self.nodes_coord = nx.spring_layout(self.graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = "weight", scale = 1.0)
# 		self.list_ant = create_ants(self.farm, self.graph, self.nodes_coord, self.theme["steps"], self.theme)
# 		self.fig = plt.figure(figsize = self.theme["window_size"])
# 		self.key = None
# 		self.click = None
# 		self.connect()
# 		self.animation()

# 	def connect(self):
# 		self.id_key = self.fig.canvas.mpl_connect('key_press_event', self.on_key)
# 		self.id_click = self.fig.canvas.mpl_connect('button_press_event', self.on_click)

# 	def on_click(event):
# 		self.click = event.click
# 		print("button: {}".format(event.button))
# 		# self.anim.FuncAnimation.pause

# 	def on_key(event):
# 		self.key = event.key
# 		print("key: {}".format(event.key))
# 		# self.anim.FuncAnimation.pause

# 	def disconnect(self):
# 		self.fig.canvas.mpl_disconnect(self.id_key)
# 		self.fig.canvas.mpl_disconnect(self.id_click)

# 	def update_image(graph, nodes_coord, farm, list_ant, fig, theme, args):
# 		self.fig.clear()
# 		links = nx.draw_networkx_edges(self.graph, self.nodes_coord, edge_color = self.theme["link_color"], width = 2.0)
# 		nodes = draw_nodes(self.graph, self.farm, self.nodes_coord, self.theme["node_color"], self.theme["node_size"], self.theme["link_color"])
# 		draw_ants(self.list_ant, num)
# 		labels_dict = create_labels(self.farm, self.args)
# 		room_names = nx.draw_networkx_labels(self.graph, self.nodes_coord, font_size = 8, labels = labels_dict, font_family = "sans-serif", font_color = self.theme["text_color"])
# 		self.fig.set_facecolor(theme["background_color"])
# 		plt.axis("off")

# 	# def animation(self):
# 	self.anim = anim.FuncAnimation(
# 		self.fig,
# 		self.update_image,
# 		fargs = (self.graph, self.nodes_coord, self.farm, self.list_ant, self.fig, self.theme, self.args),
# 		frames = (len(self.farm.moves) * self.theme["steps"]),
# 		interval = 1,
# 		repeat = self.theme["repeat"])
# 	plt.show()