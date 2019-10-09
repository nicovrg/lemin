#!/usr/bin/python

def check_args(args, option):
	for arg in args:
		if arg == option:
			return True
	return False
