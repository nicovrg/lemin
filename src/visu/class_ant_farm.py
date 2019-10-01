#!/usr/bin/python
class ant_farm_class:
    """this class represent our graph"""

    def __init__(self):
        """init a the data to none and empty"""
        self.ants   = None
        self.start  = None
        self.end    = None
        self.pos    = {}
        self.rooms  = []
        self.links  = []
        self.moves  = []

    def __repr__(self):
        """print object structure"""
        return "ants: {}\nstart: {}\nend: {}\n\nrooms: {}\n\npos: {}\n\nlinks {}\n\nmoves {}\n\n".format(self.ants, self.start, self.end, self.rooms, self.pos, self.links, self.moves)

    def __getitem__(self):
        return self

    def print_ant_farm(self):
        """print the object"""
        print "Ants:\t", self.ants
        print "Start:\t", self.start
        print "End:\t", self.end
        print "\nrooms:\n", self.rooms
        print "\npos:\n", self.pos
        print "\nlinks:\n", self.links
        print "\nmoves:\n", self.moves

# this object contain all data from our graph
