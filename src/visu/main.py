#!/usr/bin/python
import sys
import parse.parse as parse
import display.display as display
import general.usage as usage

import lib_trip.graph_one as graph_one
import lib_trip.graph_two as graph_two
import lib_trip.graph_three as graph_three
import lib_trip.draw_line_event as draw_line
import lib_trip.draw_rectangle_event as draw_rectangle

def check_args(args, option):
    for arg in args:
        if arg == option:
            return True
    return False

def lib_trip(args):
    if check_args(args, "-graph_one") == True:
        graph_one.graph_one()
    if check_args(args, "-graph_two") == True:
        graph_two.graph_two()
    if check_args(args, "-graph_three") == True:
        graph_three.graph_three()
    if check_args(args, "-draw_line") == True:
        draw_line.draw_line()
    if check_args(args, "-draw_rectangle") == True:
        draw_line.draw_line()

def visu_or_libtrip(args):
    test = args[1]
    if check_args(args, "-visu") == True:
        display.display(parse.parse(args), args)
    if check_args(args, "-lib_trip") == True:
        lib_trip(args)
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
#   we get the command line arguments

#   visu_or_libtrip
#       we try to copy argv[1] in a variable
#       if it works, we don't had IndexError we check if user want to use visu, trip with matplotlib or see help
#       else we capture the error and display usage

# main call display
#   display:
#       parse: ->
#         create and object farm
#         precompile regex we will use for parsing 
#         read on lemin output on stdin to fill farm
#       return the object farm

#   retrun in display:
#	    set the number of steps
#	    create the image container using plt.figure
#	    get graph object from function create_graph (doc below)
#	    get nodes_coord (a dict) from nx,nx.spring_layout (return a dict of nodes positions)
#	    get list_ant from create_ants (doc in draw_ants and class ant)
#	    call animation (the function using update image as callback - see doc bellow)

# options: 
#   -theme: add more theme
#   -path: highlight paths
#   -zoom: events

# pause drawing function

# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -blue_theme -darkblue_background -orange_ant -purple_nodes -red_links -help