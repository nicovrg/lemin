#!/usr/bin/python

def convert_path_to_links(paths):
	links = []
	all_links = []
	for path in paths:
		for node, next in zip(path, path[1:]):
			link = [node, next]
			links.append(link)
		all_links.append(links)
		links = []
	return (all_links)

def get_ants(farm):
	ants = []
	for move in farm.moves[0]:
		ants.append(move[0])
	return (ants)

def get_paths(farm, list_ant, ants):
	paths = []
	for ant in ants:
		paths.append(list_ant[int(ant) - 1].node_path)
	return (paths)

def remove_links_in_original_list(farm):
	for path in farm.used_links:
		for link in path:
			if link in farm.links:
				farm.links.remove(link)
			link = list(reversed(link))
			if link in farm.links:
				farm.links.remove(link)

def set_links_colors(farm, list_ant):
	nb_path = len(farm.moves[0])
	ants = get_ants(farm)
	paths = get_paths(farm, list_ant, ants)
	farm.used_links = convert_path_to_links(paths)
	remove_links_in_original_list(farm)
