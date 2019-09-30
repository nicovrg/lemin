#!/usr/bin/python
from parse import parse
from display import display

def main():
    display(parse())

main()

# make && ./lem-in < maps/sujet.map4 | python src/visu/visu.py
# make && ./lem-in < maps/sujet.map4 | python src/visu/test.py