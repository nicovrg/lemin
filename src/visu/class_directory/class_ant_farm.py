#!/usr/bin/python
class Ant_farm_class:
	"""this class represent our graph"""

	def __init__(self):
		"""init a the data to none and empty"""
		self.ants		= None
		self.start		= None
		self.end		= None
		self.pos		= {}
		self.rooms		= []
		self.links		= []
		self.used_links	= []
		self.moves		= []

	def __repr__(self):
		"""print object structure"""
		return "{} - ants:\t{}\n{} - start:\t{}\n{} - end:\t{}\n\n{} - rooms: \n{}\n\n{} - pos: \n{}\n\n{} - links \n{}\n\n{} - moves \n{}".format(type(self.ants), self.ants, type(self.start), self.start, type(self.end), self.end, type(self.rooms), self.rooms, type(self.pos), self.pos, type(self.links), self.links, type(self.moves), self.moves)

	def print_ant_farm(self):
		"""print the object"""
		print "{} - ants:\t{}\n{} - start:\t{}\n{} - end:\t{}\n\n{} - rooms: \n{}\n\n{} - pos: \n{}\n\n{} - links \n{}\n\n{} - moves \n{}".format(type(self.ants), self.ants, type(self.start), self.start, type(self.end), self.end, type(self.rooms), self.rooms, type(self.pos), self.pos, type(self.links), self.links, type(self.moves), self.moves)

# this object contain all data from our graph
