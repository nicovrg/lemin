#!/usr/bin/python

def check_args(args, option):
    for arg in args:
        if arg == option:
            return True
    return False

def create_labels(farm, args):
	labels_dict = dict([(farm.start,"START"), (farm.end,"END")])
	if check_args(args, "-nodes_name") == True:
		rooms = farm.rooms
		for room in rooms:
			if room == farm.start or room == farm.end:
				pass
			else:
				room.lower()
				labels_dict[room] = room
	return labels_dict

def create_theme(args):
	theme = {}
	# color theme:
	if check_args(args, "-dark_theme") == True or check_args(args, "-dark_theme") == False:
		theme["steps"] = 5
		theme["repeat"] = False
		theme["link_color"] = "#101010"
		theme["text_color"] = "#EEEEEE"
		theme["background_color"] = "#15202b"
		theme["default_node_color"] = "#282828"
		theme["ant_colors_list"] = ['#B61515', '#B66615', '#B6B615', '#66B615', '#15B615', '#15B666', '#15B6B6', '#1515B6', '#6615B6', '#B615B6', '#B61566']
	if check_args(args, "-blue_theme") == True:
		theme["steps"] = 5
		theme["repeat"] = False
		theme["link_color"] = "#549EDD"
		theme["text_color"] = "#094DB9"
		theme["background_color"] = "#013FC1"
		theme["default_node_color"] = "#AAD1ED"
		theme["ant_colors_list"] = ["#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9"]

	# number of steps between rooms
	if check_args(args, "-fast") == True:
		theme["steps"] = 2
	elif check_args(args, "-slow") == True:
		theme["steps"] = 10

	# repeat
	if check_args(args, "-repeat") == True:
		theme["repeat"] = True
	return theme

# create_labels:
#	create a dictionary of keys farm.rooms and value farm.rooms value
#	set farm.start and farm.end names to START and END for lisibility
#	loop through farm.rooms to fill the dictionary of keys farm.rooms and value farm.rooms value

# create_theme:
#	set the colors according to the user theme choice
