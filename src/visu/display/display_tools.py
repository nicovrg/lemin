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
