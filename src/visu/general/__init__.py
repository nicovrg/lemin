#!/usr/bin/python

def usage():
    print "options:" 
    print "\t-farm: print the farm structure in terminal"
    print "\t-nodes_name: print rooms names in visu"
    print "\t-dark_theme: change the theme settings"
    print "\t-blue_theme: change the theme settings"
    print "\t-fast: change the step settings from 5 to 2"
    print "\t-slow: change the step settings from 5 to 1"
    print "\t-repeat: change the repeat settings from False to True"
    print "\t[color]_ant: change the ant color"
    print "\t[color]_background}: change the background color"
    print "\t[color]: red, orange, yellow, green, blue, darkblue, purple, darkpurple, pink"
    print
    print "compile:"
    print "\tmake && ./lem-in < maps/sujet.map4 | python src/visu/main.py"
