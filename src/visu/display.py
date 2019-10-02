#!/usr/bin/python
import networkx as nx
import matplotlib.pyplot as plt
from class_ant import ant_class

link_color = '#282828'
text_color = '#EEEEEE'
background_color = '#15202b'
default_node_color = '#282828'
ant_colors_list = ['#B61515', '#B66615', '#B6B615', '#66B615', '#15B615', '#15B666', '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566']



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
    graph = nx.Graph()
    graph.add_nodes_from(farm.rooms)
    graph.add_edges_from(farm.links)
    dict_nodes_pos = nx.spring_layout(graph, dim = 2, k = None, pos = None, fixed = None, iterations = 50, weight = 'weight', scale = 1.0)
    
    num_steps = 10
    list_ant = create_ants(farm, graph, dict_nodes_pos, num_steps)
    # fig = plt.figure()
    # fig.set_facecolor("#15202b")
    # nx.draw(graph, with_labels = True)
    # plt.show()




# create an empty graph object with no nodes and no edges
# add the list of rooms as nodes to the graph object 
# add the list of links as edges to the graph object 
# create a dict of positions of each node in the graph object, key is name and store tuples of x, y
# call create ant
#   we create a list of ants
#   for each ant we give it a number, path, location, journey and color
#   then we return that list
# 
# 
