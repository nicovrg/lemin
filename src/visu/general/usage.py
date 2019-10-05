#!/usr/bin/python
import os

def usage():
    os.system('clear')

    red = "\x1b[31m"
    orange = "\x1b[91m"
    blue = "\x1b[34m"
    green = "\x1b[32m"
    yellow = "\x1b[33m"
    purple = "\x1b[35m"
    pink = "\x1b[95m"
    cyan = "\x1b[36m"
    grey = "\x1b[40m"
    underline = "\x1b[4m"
    rev = "\x1b[7m"
    bold = "\x1b[1m"
    end = "\x1b[0m"

    print("  {}{}{}compile:{}".format(underline, bold, cyan, end))
    print
    print("\t{}{}make && ./lem-in < maps/sujet.map4 | python src/visu/main.py -option{}".format(bold, blue, end))
    print
    print("  {}{}{}visu options:{}".format(underline, bold, cyan, end))
    print
    print("\t{}-visu:{} start visu, you can use options below".format(green, end))
    print
    print("\t{}-help:{} print usage".format(green, end))
    print("\t{}-farm:{} print the farm structure in terminal".format(green, end))
    print("\t{}-fast:{} change the step settings from 5 to 2".format(green, end))
    print("\t{}-slow:{} change the step settings from 5 to 1".format(green, end))
    print("\t{}-repeat:{} change the repeat settings from False to True".format(green, end))
    print("\t{}-nodes_name:{} print rooms names in visu".format(green, end))
    print("\t{}-small_nodes:{} change the node size setting from 50 to 5000".format(green, end))
    print("\t{}-big_nodes:{} change the node size setting from 500 to 5000".format(green, end))
    print("\t{}-dark_theme:{} change the theme settings".format(green, end))
    print("\t{}-blue_theme:{} change the theme settings".format(green, end))
    print("\t{}-[color]_ant:{} change the ant color".format(green, end))
    print("\t{}-[color]_nodes{}: change the nodes color".format(green, end))
    print("\t{}-[color]_links:{} change the links color".format(green, end))
    print("\t{}-[color]_background:{} change the background color".format(green, end))
    print
    print("\t{}{}[colors]:{} {}red, {}orange, {}yellow, {}green, {}blue, {}darkblue, {}purple, {}pink".format(bold, green, end, red, orange, yellow, green, cyan, blue, purple, pink))
    print
    print("  {}{}{}matplotlib test options:{}".format(underline, bold, cyan, end))
    print
    print("\t{}-lib_trip:{} start lib test for fun, you can use options below".format(green, end))
    print
    print("\t{}-graph_one:{} draw first graph".format(green, end))
    print("\t{}-graph_two:{} draw second graph".format(green, end))
    print("\t{}-graph_three:{} draw third graph".format(green, end))
    print("\t{}-graph_four:{} draw fourth graph".format(green, end))
    print("\t{}-figure_one:{} draw first figure".format(green, end))
    print("\t{}-figure_two:{} draw second figure".format(green, end))
    print("\t{}-figure_three:{} draw third figure".format(green, end))
    print("\t{}-image_one:{} draw first image".format(green, end))
    print("\t{}-print_event:{} print event click on a random graph".format(green, end))
    print("\t{}-draw_subplots:{} draw 4 subplots on the window".format(green, end))
    print("\t{}-draw_line:{} draw a line on the window (interactive)".format(green, end))
    print("\t{}-draw_rectangle:{} draw a rectangle on the window (interactive)".format(green, end))
    print
    print("  {}{}{}events:{}".format(underline, bold, cyan, end))
    print    
    print("\t{}press key p:{} play/pause animation".format(green, end))
    print
  