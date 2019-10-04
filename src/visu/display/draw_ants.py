#!/usr/bin/python
import matplotlib.pyplot as plt
import class_directory.class_ant as c_ant

def draw_ant(position, color):
	ant = plt.plot([position[0]], [position[1]], color = color, marker = '.', markersize = 20.0)
	return (ant)

def draw_ants(list_ant, num):
	for ant in list_ant:
		if num < len(ant.journey):
			draw_ant(ant.journey[num], ant.color)

def create_ants(farm, graph, nodes_coord, steps, theme):
	list_ant = []
	for num in range (1, int(farm.ants) + 1):
		ant = c_ant.ant_class(num)
		ant.set_node_path(farm)
		ant.set_location(farm, nodes_coord)
		ant.set_journey(farm, nodes_coord, theme["steps"])
		ant.color = theme["ant_colors_list"][num % 11]
		list_ant.append(ant)
	return (list_ant)

# create ants:
#	create a list of ant and a list of ant colors
#	loop from ant 1 to number of ants + 1
#	create an object ant
#	call it's method to set it's path, location, journey and color
#	append it to list of ants
#	return list_ant

# draw ants:
#	loop through ant and check if ant number is less than the lenght of the ant journey
#	call draw_ant

# draw ant:
#	call matplotlib plot method that will take x - y coordinates, color, type and size of the plot to draw	
