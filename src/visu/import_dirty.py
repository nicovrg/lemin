#!/usr/bin/python
from parse.parse import parse

from display.draw_nodes import draw_nodes
from display.draw_ants import create_ants, draw_ants
from display.create_graph import create_graph
from display.display_tools import create_labels
from display.arg_options import create_theme
from display.event_options import *
from display.highlight_path import set_links_colors

from general.usage import usage
from general.check_args import check_args

from lib_trip.lib_trip import lib_trip
from lib_trip.image_one import image_one
from lib_trip.draw_subplots import draw_subplots
from lib_trip.graph_one import graph_one
from lib_trip.graph_two import graph_two
from lib_trip.graph_three import graph_three
from lib_trip.graph_four import graph_four
from lib_trip.figure_one import figure_one
from lib_trip.figure_two import figure_two
from lib_trip.figure_three import figure_three
from lib_trip.print_event import print_event
from lib_trip.draw_line_event import draw_line
from lib_trip.draw_rectangle_event import draw_rectangle
from lib_trip.zoom_test import zoom_test
