#!/usr/bin/python
import re
import sys
import networkx as nx
import matplotlib.pyplot as plt

# import class_farm

class farm:
    """this class represent our graph"""

    def __init__(self):
        self.ants   = int(0)
        self.start  = None
        self.end    = None
        self.rooms  = []
        self.links  = []
        # self.moves  = []

def parser():
    i = 0
    line = None
    line_list = []
    ant_farm = farm()
    
    for line in sys.stdin:
        line_list.append(line.strip().split())
        i += 1
    ant_farm.ants = line_list[0][0]

    
    
    
    
    print "i: ", i, "\n"
    print "ant_farm.ants: ", ant_farm.ants, "\n"
    print "\n"
    print "line_list: \n", line_list


def main():
    parser()

main()

# G = nx.Graph()
# G.add_node(1)
# nx.draw(g, with_labels=True)
# plt.show()
# make && ./lem-in < maps/sujet.map4 | python src/visu/visu.py
# make && ./lem-in < maps/sujet.map4 | python src/visu/test.py
