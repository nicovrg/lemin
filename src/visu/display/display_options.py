#!/usr/bin/python

def check_args(args, option):
    for arg in args:
        if arg == option:
            return True
    return False

def color_theme(theme, args):
	if check_args(args, "-dark_theme") == True or check_args(args, "-dark_theme") == False:
		theme["steps"] = 5
		theme["repeat"] = False
		theme["link_color"] = "#101010"
		theme["text_color"] = "#EEEEEE"
		theme["background_color"] = "#15202b"
		theme["node_color"] = "#282828"
		theme["ant_colors_list"] = ['#15B6B6', '#15B6B6', '#1515B6', '#B615B6', '#6615B6', '#15B6B6', '#15B6B6', '#1515B6', '#B615B6', '#6615B6', '#6615B6']

	if check_args(args, "-blue_theme") == True:
		theme["steps"] = 5
		theme["repeat"] = False
		theme["link_color"] = "#549EDD"
		theme["text_color"] = "#094DB9"
		theme["background_color"] = "#013FC1"
		theme["node_color"] = "#AAD1ED"
		theme["ant_colors_list"] = ["#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9"]
	return theme

def color_background(theme, args):
	if check_args(args, "-red_background") == True:
		theme["background_color"] = "#B61515"
	elif check_args(args, "-orange_background") == True:
		theme["background_color"] = "#B66615"
	elif check_args(args, "-yellow_background") == True:
		theme["background_color"] = "#B6B615"
	elif check_args(args, "-green_background") == True:
		theme["background_color"] = "#15B615"
	elif check_args(args, "-blue_background") == True:
		theme["background_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_background") == True:
		theme["background_color"] = "#1515B6"
	elif check_args(args, "-purple_background") == True:
		theme["background_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_background") == True:
		theme["background_color"] = "#6615B6"
	elif check_args(args, "-pink_background") == True:
		theme["background_color"] = "#B61566"
	return theme

def color_nodes(theme, args):
	if check_args(args, "-red_nodes") == True:
		theme["node_color"] = "#B61515"
	elif check_args(args, "-orange_nodes") == True:
		theme["node_color"] = "#B66615"
	elif check_args(args, "-yellow_nodes") == True:
		theme["node_color"] = "#B6B615"
	elif check_args(args, "-green_nodes") == True:
		theme["node_color"] = "#15B615"
	elif check_args(args, "-blue_nodes") == True:
		theme["node_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_nodes") == True:
		theme["node_color"] = "#1515B6"
	elif check_args(args, "-purple_nodes") == True:
		theme["node_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_nodes") == True:
		theme["node_color"] = "#6615B6"
	elif check_args(args, "-pink_nodes") == True:
		theme["node_color"] = "#B61566"
	return theme

def color_links(theme, args):
	if check_args(args, "-red_links") == True:
		theme["link_color"] = "#B61515"
	elif check_args(args, "-orange_links") == True:
		theme["link_color"] = "#B66615"
	elif check_args(args, "-yellow_links") == True:
		theme["link_color"] = "#B6B615"
	elif check_args(args, "-green_links") == True:
		theme["link_color"] = "#15B615"
	elif check_args(args, "-blue_links") == True:
		theme["link_color"] = "#15B6B6"
	elif check_args(args, "-darkblue_links") == True:
		theme["link_color"] = "#1515B6"
	elif check_args(args, "-purple_links") == True:
		theme["link_color"] = "#B615B6"
	elif check_args(args, "-darkpurple_links") == True:
		theme["link_color"] = "#6615B6"
	elif check_args(args, "-pink_links") == True:
		theme["link_color"] = "#B61566"
	return theme

def color_ant(theme, args):
	if check_args(args, "-red_ant") == True:
		theme["ant_colors_list"] = ['#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515', '#B61515']
	elif check_args(args, "-orange_ant") == True:
		theme["ant_colors_list"] = ['#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615', '#B66615']
	elif check_args(args, "-yellow_ant") == True:
		theme["ant_colors_list"] = ['#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615', '#B6B615']
	elif check_args(args, "-green_ant") == True:
		theme["ant_colors_list"] = ['#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615', '#15B615']
	elif check_args(args, "-blue_ant") == True:
		theme["ant_colors_list"] = ['#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6', '#15B6B6']
	elif check_args(args, "-darkblue_ant") == True:
		theme["ant_colors_list"] = ['#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6']
	elif check_args(args, "-purple_ant") == True:
		theme["ant_colors_list"] = ['#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6', '#B615B6']
	elif check_args(args, "-darkpurple_ant") == True:
		theme["ant_colors_list"] = ['#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6']
	elif check_args(args, "-pink_ant") == True:
		theme["ant_colors_list"] = ['#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566', '#B61566']
	return theme


def create_theme(args):
	theme = {}
	theme = color_theme(theme, args)
	theme = color_background(theme, args)
	theme = color_nodes(theme, args)
	theme = color_links(theme, args)
	theme = color_ant(theme, args)

	if check_args(args, "-fast") == True:
		theme["steps"] = 2
	if check_args(args, "-slow") == True:
		theme["steps"] = 10
	if check_args(args, "-repeat") == True:
		theme["repeat"] = True

	return theme

# create_theme:
#	set the colors according to the user theme choice
