#!/usr/bin/python
import numpy as np

class ant_class():
    """this class represent an ant"""

    def __init__(self, num):
		self.number = num
		self.current_location = None
		self.node_path = None
		self.journey = None
		self.color = None

    def set_location(self, dict_nodes_pos, farm):
        self.current_location = dict_nodes_pos[farm.start]

    def set_node_path(self, farm):
		started = False
		self.node_path = []
		self.node_path.append(farm.start)
		for turn in farm.moves:
			for swap in turn:
				if swap[0] == str(self.number):
					self.node_path.append(swap[1])
					started = True
			if not started:
				self.node_path.append(farm.start)
		print (self.node_path)

    def set_journey(self, dict_nodes_pos, num_steps, farm):
        location_list = []
        for i in range(len(self.node_path)):
            if i != 0:
                start_pos = dict_nodes_pos[self.node_path[i - 1]]
                end_pos = dict_nodes_pos[self.node_path[i]]
                x = np.linspace(start_pos[0], end_pos[0], num = num_steps)
                y = np.linspace(start_pos[1], end_pos[1], num = num_steps)
                location_list.extend(list(zip(x, y)))
            i += 1
        self.journey = location_list
