#!/usr/bin/python

print "import class_farm succesfull"

class farm:
    """this class represent our graph"""

    def __init__(self):
        self.links  = []
        self.nodes  = []
        self.moves  = []
        self.start  = None
        self.end    = None
        self.ants   = int(0)
