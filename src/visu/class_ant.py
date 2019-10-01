#!/usr/bin/python
import numpy as np

class ant_class():
    """this class represent an ant"""

    def __init__(self):
        self.number = 0
        self.node_path = None
        self.journey = None
        self.color = 'g.'

    def set_node_path(self, farm):
        self.node_path = []
        started = False
        self.node_path.append(farm['start'])
        for turn in farm['turns']:
            for move in turn:
                if move[0] == str(self.number):
                    self.node_path.append(move[1])
                    started = True
            if not started:
                self.node_path.append(farm['start'])

    def set_location(self, pos, farm):
        location = pos[farm['start']]
        self.current_location = location

    def set_journey(self, pos, num_steps, farm):
        location_list = []
        for i in range(len(self.node_path)):
            if i != 0:
                start_pos = pos[self.node_path[i - 1]]
                end_pos = pos[self.node_path[i]]
                x = np.linspace(start_pos[0], end_pos[0], num=num_steps)
                y = np.linspace(start_pos[1], end_pos[1], num=num_steps)
                location_list.extend(list(zip(x, y)))
            i += 1
        self.journey = location_list
