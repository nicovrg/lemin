#!/usr/bin/python

def play_pause(animation, anim_running):
	if anim_running:
		animation.event_source.stop()
		anim_running = False
	else:
		animation.event_source.start()
		anim_running = True
	return anim_running

def up_node_size(theme):
	theme["node_size"] += 20

def down_node_size(theme):
	theme["node_size"] -= 20

def up_ant_size(theme):
	theme["markersize"] += 3

def down_ant_size(theme):
	theme["markersize"] -= 3

def reset_theme(theme):
	theme["steps"] = 15
	theme["window_size"] = None
	theme["repeat"] = False
	theme["link_color"] = "#101010"
	theme["text_color"] = "#EEEEEE"
	theme["background_color"] = "#15202B"
	theme["node_color"] = "#282828"
	theme["ant_colors_list"] = ['#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6', '#1515B6']

def switch_background_color(theme):
	if theme["background_color"] == "#15202B":
		theme["background_color"] = "#1515B6"
	elif theme["background_color"] == "#1515B6":
		theme["background_color"] = "#15B6B6"
	elif theme["background_color"] == "#15B6B6":
		theme["background_color"] = "#6615B6"
	elif theme["background_color"] == "#6615B6":
		theme["background_color"] = "#B61566"
	elif theme["background_color"] == "#B61566":
		theme["background_color"] = "#B66615"
	elif theme["background_color"] == "#B66615":
		theme["background_color"] = "#B61515"
	elif theme["background_color"] == "#B61515":
		theme["background_color"] = "#B6B615"
	elif theme["background_color"] == "#B6B615":
		theme["background_color"] = "#15B615"
	elif theme["background_color"] == "#15B615":
		theme["background_color"] = "#15202B"

def switch_node_color(theme):
	if theme["node_color"] == "#282828":
		theme["node_color"] = "#1515B6"
	elif theme["node_color"] == "#1515B6":
		theme["node_color"] = "#15B6B6"
	elif theme["node_color"] == "#15B6B6":
		theme["node_color"] = "#6615B6"
	elif theme["node_color"] == "#6615B6":
		theme["node_color"] = "#B61566"
	elif theme["node_color"] == "#B61566":
		theme["node_color"] = "#B66615"
	elif theme["node_color"] == "#B66615":
		theme["node_color"] = "#B61515"
	elif theme["node_color"] == "#B61515":
		theme["node_color"] = "#B6B615"
	elif theme["node_color"] == "#B6B615":
		theme["node_color"] = "#15B615"
	elif theme["node_color"] == "#15B615":
		theme["node_color"] = "#282828"

def switch_link_color(theme):
	if theme["link_color"] == "#101010":
		theme["link_color"] = "#1515B6"
	elif theme["link_color"] == "#1515B6":
		theme["link_color"] = "#15B6B6"
	elif theme["link_color"] == "#15B6B6":
		theme["link_color"] = "#6615B6"
	elif theme["link_color"] == "#6615B6":
		theme["link_color"] = "#B61566"
	elif theme["link_color"] == "#B61566":
		theme["link_color"] = "#B66615"
	elif theme["link_color"] == "#B66615":
		theme["link_color"] = "#B61515"
	elif theme["link_color"] == "#B61515":
		theme["link_color"] = "#B6B615"
	elif theme["link_color"] == "#B6B615":
		theme["link_color"] = "#15B615"
	elif theme["link_color"] == "#15B615":
		theme["link_color"] = "#101010"
