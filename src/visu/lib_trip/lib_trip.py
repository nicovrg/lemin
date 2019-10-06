#!/usr/bin/python

import figure_one, figure_three, figure_two, graph_four, graph_one, graph_three, graph_two, image_one, lib_trip, print_event, draw_line_event, draw_rectangle_event, draw_subplots, zoom_test

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
    if check_args(args, "-graph_four") == True:
        graph_four.graph_four()
    if check_args(args, "-image_one") == True:
        image_one.image_one()
    if check_args(args, "-draw_subplots") == True:
        draw_subplots.draw_subplots()
    if check_args(args, "-figure_one") == True:
        figure_one.figure_one()
    if check_args(args, "-figure_two") == True:
        figure_two.figure_two()
    if check_args(args, "-figure_three") == True:
        figure_three.figure_three()
    if check_args(args, "-draw_line") == True:
        draw_line_event.draw_line()
    if check_args(args, "-draw_rectangle") == True:
        draw_rectangle_event.draw_rectangle()
    if check_args(args, "-print_event") == True:
        print_event.print_event()
    if check_args(args, "-zoom_test") == True:
        zoom_test.zoom_test()
