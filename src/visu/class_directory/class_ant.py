#!/usr/bin/python
import numpy as np

class ant_class():
	"""this class represent an ant -- see doc belows"""

	def __init__(self, num):
		self.current_location = None
		self.number = num
		self.node_path = None
		self.journey = None
		self.color = None

	def set_location(self, farm, nodes_coord):
		self.current_location = nodes_coord[farm.start]

	def set_node_path(self, farm):
		chill_in_start = True
		self.node_path = []
		self.node_path.append(farm.start)
		for turn in farm.moves:
			for swap in turn:
				if swap[0] == str(self.number):
					self.node_path.append(swap[1])
					chill_in_start = False
			if chill_in_start:
				self.node_path.append(farm.start)

	def set_journey(self, farm, nodes_coord, steps):
		i = 0
		location_list = []
		while i < len(self.node_path) - 1:
				start = nodes_coord[self.node_path[i]]
				end = nodes_coord[self.node_path[i + 1]]
				x = np.linspace(start[0], end[0], num = steps)
				y = np.linspace(start[1], end[1], num = steps)
				location_list.extend(zip(x, y))
				i += 1
		self.journey = location_list

# set_location:
# 	the ant will start in start room so we must give it
#	the position nx.spring_layout gave to our start room

# set_node_path:
# 	we add to the ant object a list of room it must visit
#	we iterate on lemin output, if we see the ant we are creating link to any_room, we append that room to the path of our ant
# 	turn represent a line of lemin output, and move is an element of that line
# 	swap[0]: ant 
# 	swap[1]: room
#	chill_in_start is a trick variable:
#	if there is no move from ant_num_x on this line, we add start to it's path
#	so if ant_10 is moving after 5 turns, it will chill in start room during 5 turns!

# set_journey:
#	we iterate through the path of this ant
#	we set the start position at the first node and the end position to the following node
#	we call numpy linspace that return an evenly spaced numbers over a specified interval under an numpy .ndarray object
#	we zip() x and y into a tuple, then append it to location_list with .extend
