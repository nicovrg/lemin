#!/usr/bin/python
from parse import parse
from display import display

def main():
    # parse()
    display(parse())

main()

# main call display
#   display call parse
#       parse 
#         create and object farm
#         precompile regex we will use for parsing 
#         read on lemin output on stdin to fill farm
#           - str -> number of ants 
#           - str -> start room
#           - str -> end room
#           - list -> rooms
#           - dict -> name of rooms as keys
#               - tuple -> position of the room
#           - list -> links
#           - list -> moves 
#       return the object farm
#   create an empty graph with no nodes and no edges
#
#
#
#
#
#
#
#
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
