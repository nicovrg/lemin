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

def create_ants(farm, graph, nodes_coord, steps):
	list_ant = []
	ant_colors_list = ['#B61515', '#B66615', '#B6B615', '#66B615', '#15B615', '#15B666', '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566']
	for num in range (1, int(farm.ants) + 1):
		ant = c_ant.ant_class(num)
		ant.set_node_path(farm)
		ant.set_location(farm, nodes_coord)
		ant.set_journey(farm, nodes_coord, steps)
		ant.color = ant_colors_list[num % 11]
		list_ant.append(ant)
	return (list_ant)