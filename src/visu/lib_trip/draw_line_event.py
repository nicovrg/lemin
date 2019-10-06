#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

class LineBuilder:
	def __init__(self, line):
		self.line = line
		self.xs = list(line.get_xdata())
		self.ys = list(line.get_ydata())
		self.cid = line.figure.canvas.mpl_connect('button_press_event', self)

	def __call__(self, event):
		print('click', event)
		if event.inaxes!=self.line.axes: return
		self.xs.append(event.xdata)
		self.ys.append(event.ydata)
		self.line.set_data(self.xs, self.ys)
		self.line.figure.canvas.draw()

def draw_line():
	fig = plt.figure()
	fig.set_facecolor("#101010")
	ax = fig.add_subplot(111)
	plt.axis("off")
	line, = ax.plot([0], [0]) # empty line
	linebuilder = LineBuilder(line)
	plt.show()
