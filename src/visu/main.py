#!/usr/bin/python
import parse.parse as parse
import display.display as display

def main():
    display.display(parse.parse())

main()

# main call display
#   display call parse
#       parse: ->
#         create and object farm
#         precompile regex we will use for parsing 
#         read on lemin output on stdin to fill farm
#           - str -> number of ants 
#           - str -> start room
#           - str -> end room
#           - list -> rooms
#           - dict -> name of rooms as keys
#               - tuple -> position of the room
#           - list of list -> links
#           - list of list -> moves 
#       return the object farm
#   display: <-
#
#
#
#
#
#
#
#
# make && ./lem-in < maps/sujet.map4 | python src/visu/main.py
