#!/usr/bin/python
import parse.parse as parse
import display.display as display

def main():
    display.display(parse.parse())

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

# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
