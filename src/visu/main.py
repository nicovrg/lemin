#!/usr/bin/python
import sys
import parse.parse as parse
import display.display as display

def check_args(args, option):
    for arg in args:
        if arg == option:
            return True
    return False

def usage():
    print "options:" 
    print "\t-farm: print the farm structure in terminal"
    print "\t-nodes_name: print rooms names in visu"
    print "\t-dark_theme: change the theme settings"
    print "\t-blue_theme: change the theme settings"
    print "\t-fast: change the step settings from 5 to 2"
    print "\t-slow: change the step settings from 5 to 1"
    print "\t-repeat: change the repeat settings from False to True"
    print "\t[color]_ant}: change the ant color"
    print "\t[color]_background}: change the background color"
    print "\t[color]: red, orange, yellow, green, blue, darkblue, purple, darkpurple, pink"
    print
    print "compile:"
    print "\tmake && ./lem-in < maps/sujet.map4 | python src/visu/main.py"

def main():
    args = sys.argv
    if check_args(args, "-help") == True:
        usage()
    display.display(parse.parse(args), args)

main()

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
