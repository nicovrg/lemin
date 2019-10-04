#!/usr/bin/python

def create_labels(farm):
	labels_dict = dict([(farm.start,'START'), (farm.end,'END')])
	rooms = farm.rooms
	for room in rooms:
		if room == farm.start or room == farm.end:
			pass
		else:
			room.lower()
			labels_dict[room] = room
	return labels_dict

# create_labels:
#	create a dictionary of keys farm.rooms and value farm.rooms value
#	set farm.start and farm.end names to START and END for lisibility
#	loop through farm.rooms to fill the dictionary of keys farm.rooms and value farm.rooms value