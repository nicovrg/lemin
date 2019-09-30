#!/usr/bin/python

class   :
    """this class represent our graph"""

    def __init__(self):
        """init a the data to none and empty"""
        self.ants   = None
        self.start  = None
        self.end    = None
        self.rooms  = []
        self.pos    = {}
        self.links  = []
        self.moves  = []

    def print_ant_farm(self):
        """print the object"""
        print "Ants:\t", self.ants
        print "Start:\t", self.start
        print "End:\t", self.end
        print "\nrooms:\n", self.rooms
        print "\npos:\n", self.pos
        print "\nlinks:\n", self.links
        print "\nmoves:\n", self.moves
