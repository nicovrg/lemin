#!/usr/bin/python
import re
import sys
import class_directory.class_ant_farm as c_farm
from parse_tools import get_ants, get_start, get_end, get_room, get_link, get_move

def check_args(args, option):
	for arg in args:
		if arg == option:
			return True
	return False

def regex_compile():
	"""pre compile all regex we need to parse map"""
	reg_dict = {}
	reg_dict["is_comment"] = re.compile(r"^#")
	reg_dict["is_start"] = re.compile(r"^#{2}(start)")
	reg_dict["is_end"] = re.compile(r"^#{2}(end)")
	reg_dict["is_room"] = re.compile(r"^([\d\w]+) \d+ \d+\n$")
	reg_dict["is_link"] = re.compile(r"^([\d\w]+)-([\d\w]+)\n$")
	reg_dict["is_move"] = re.compile(r"L([\d\w]+)-([\d\w]+)")
	return (reg_dict)

def check_status(farm, status, line):
	"""deal with previous loop iteration comment to pass or add start | end"""
	if (status == None):
		return status
	elif (status == "start"):
		get_start(farm, line)
	elif (status == "end"):
		get_end(farm, line)
	elif (status == "comment"):
		pass
	status = None
	return status

def parse(args):
	"""parse lemin outpout to create, set and return the ant_farm object"""
	status = None
	farm = c_farm.ant_farm_class()
	reg_dict = regex_compile()
	
	get_ants(farm)
	for line in sys.stdin:
		status = check_status(farm, status, line)
		if (reg_dict["is_start"].search(line)):
			status = "start"
		elif (reg_dict["is_end"].search(line)):
			status = "end"
		elif (reg_dict["is_comment"].search(line)):
			status = "comment"
		elif (reg_dict["is_room"].search(line)):
			get_room(farm, line)
		elif (reg_dict["is_move"].search(line)):
			get_move(farm, line)
		elif (reg_dict["is_link"].search(line)):
			get_link(farm, line)
	if check_args(args, "-farm") == True:
		farm.print_ant_farm()
	return farm

# parse
#	create and object farm
#	precompile regex we will use for parsing 
#	read on lemin output on stdin to fill farm
#		- str -> number of ants 
#		- str -> start room
#		- str -> end room
#		- list -> rooms
#		- dict -> name of rooms as keys
#			- tuple -> position of the room
#		- list of list -> links
#		- list of list -> moves 
#	return the object farm

