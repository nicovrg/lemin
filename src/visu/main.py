#!/usr/bin/python
import sys
import dirty_import
from dirty_import import parse, display, usage, lib_trip, image_one, draw_subplots, graph_one, graph_two, graph_three, graph_four, figure_one, figure_two, figure_three, print_event, draw_line, draw_rectangle

def check_args(args, option):
	for arg in args:
		if arg == option:
			return True
	return False

def visu_or_libtrip(args):
	test = args[1]
	if check_args(args, "-visu") == True:
		display.display(parse.parse(args), args)
	if check_args(args, "-lib_trip") == True:
		lib_trip.lib_trip(args)
	if check_args(args, "-help") == True:
		usage.usage()

def main():
	args = sys.argv
	try:
		visu_or_libtrip(args)
	except IndexError:
		usage.usage()

main()

# main
#	we get the command line arguments

#	visu_or_libtrip
#		we try to copy argv[1] in a variable
#		if it works, we don't had IndexError we check if user want to use visu, trip with matplotlib or see help
#		else we capture the error and display usage

# main call display
#	display:
#		parse: ->
#			create and object farm
#			precompile regex we will use for parsing 
#			read on lemin output on stdin to fill farm
#		return the object farm

#	retrun in display:
#		set the number of steps
#		create the image container using plt.figure
#		get graph object from function create_graph (doc below)
#		get nodes_coord (a dict) from nx,nx.spring_layout (return a dict of nodes positions)
#		get list_ant from create_ants (doc in draw_ants and class ant)
#		call animation (the function using update image as callback - see doc bellow)

# options: 
#	-theme: add more theme
#	-path: highlight paths
#	-zoom: events
#	-background_image: 

# pause drawing function

# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -blue_theme -darkblue_background -orange_ant -purple_nodes -red_links -help
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -lib_trip -draw_subplots -graph_one -graph_two -graph_three -graph_four -figure_one -figure_two -print_event -draw_line -draw_rectangle -image_one