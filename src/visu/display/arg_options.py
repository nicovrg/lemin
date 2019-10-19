#!/usr/bin/python
import sys
from general.check_args import check_args

def check_graph_size(farm, theme):
	if (len(farm.rooms)) > 1 and (len(farm.rooms)) < 100:
		theme["markersize"] = 20.0
		theme["node_size"] = 500
		theme["window_size"] = (6, 5)
	elif (len(farm.rooms)) > 100 and (len(farm.rooms)) < 1000:
		theme["markersize"] = 12.0
		theme["node_size"] = 50
		theme["window_size"] = (16, 12)
	else:
		theme["markersize"] = 5.0
		theme["node_size"] = 5
		theme["window_size"] = (18, 16)
	return theme

def color_theme(theme, args, farm):
	if check_args(args, "-dark_theme") == True or check_args(args, "-dark_theme") == False or flag == True:
		theme["steps"] = 15
		theme["window_size"] = None
		theme["repeat"] = False
		theme["link_color"] = "#101010"
		theme["text_color"] = "#EEEEEE"
		theme["background_color"] = "#15202B"
		theme["node_color"] = "#282828"
		theme["path_color"] = ["#15B6B6", "#0548C9", "#6615B6", "#62ADE9", "#15B6B6"]
		theme["ant_colors_list"] = ['#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6', '#6615B6']
	if check_args(args, "-blue_theme") == True and flag == False:
		theme["steps"] = 15
		theme["window_size"] = None
		theme["repeat"] = False
		theme["link_color"] = "#549EDD"
		theme["text_color"] = "#094DB9"
		theme["background_color"] = "#013FC1"
		theme["node_color"] = "#AAD1ED"
		theme["path_color"] = ["#15B6B6", "#15B6B6", "#15B6B6", "#0548C9", "#BFD9EA", "#62ADE9", "#0548C9", "#BFD9EA", "#62ADE9", "#15B6B6", "#15B6B6"]
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

def set_speed(theme, args):
	if check_args(args, "-fast") == True:
		theme["steps"] = 2
	if check_args(args, "-slow") == True:
		theme["steps"] = 10
	return theme

def set_repeat(theme, args):
	if check_args(args, "-repeat") == True:
		theme["repeat"] = True
	return theme

def set_size(theme, args):
	if check_args(args, "-small") == True:
		theme["node_size"] = 50
		theme["markersize"] = 5.0
	elif check_args(args, "-big") == True:
		theme["node_size"] = 5000
		theme["markersize"] = 50.0
	return theme

def set_window_size(theme, args):
	flag = False
	if check_args(args, "-window_size") == True:
		for arg in args:
			if (arg == "-window_size"):
				flag = True
		if flag == True:
			line = arg.split(" ")
		try:
			x = (int)(line[0])
			y = (int)(line[1])
		except Exception:
			print "default size taken, please choose a size between 0 and 20"
			return theme
		if (x >= 0 and x <= 20 and y >= 0 and y <= 20):
			theme["window_size"] = (x, y)
	return theme

def create_theme(args, farm):
	theme = {}
	theme = color_theme(theme, args, farm)
	theme = check_graph_size(farm, theme)
	theme = color_background(theme, args)
	theme = color_nodes(theme, args)
	theme = color_links(theme, args)
	theme = color_ant(theme, args)
	theme = set_speed(theme, args)
	theme = set_repeat(theme, args)
	theme = set_size(theme, args)
	theme = set_window_size(theme, args)
	return theme