#!/usr/bin/python
import matplotlib.pyplot as plt
import numpy as np


def onpress(event):
	print (event.xdata, event.ydata)
	if event.button != 1:
		return
	x, y = event.xdata, event.ydata
	# axsrc.set_xlim(x - 0.1, x + 0.1)
	# axsrc.set_ylim(y - 0.1, y + 0.1)
	figsrc.canvas.draw()
	figzoom.canvas.draw()

def graph_four():
	figsrc, axsrc = plt.subplots()
	# figzoom, axzoom = plt.subplots()
	axsrc.set(xlim = (0, 1), ylim = (0, 1), autoscale_on = False, title = 'Click to zoom')
	# axzoom.set(xlim = (0.45, 0.55), ylim = (0.4, 0.6), autoscale_on = False, title = 'Zoom window')
	x, y, s, c = np.random.rand(4, 200)
	s *= 200
	axsrc.scatter(x, y, s, c)
	# axzoom.scatter(x, y, s, c)
	test = figsrc.canvas.mpl_connect('button_press_event', onpress)
	print test
	plt.show()





# def onpress(event):
# 	if event.button != 1:
# 		return
# 	x, y = event.xdata, event.ydata
# 	axzoom.set_xlim(x - 0.1, x + 0.1)
# 	axzoom.set_ylim(y - 0.1, y + 0.1)
# 	figzoom.canvas.draw()

# def graph_four():
# 	figsrc, axsrc = plt.subplots()
# 	figzoom, axzoom = plt.subplots()
# 	axsrc.set(xlim = (0, 1), ylim = (0, 1), autoscale_on = False, title = 'Click to zoom')
# 	axzoom.set(xlim = (0.45, 0.55), ylim = (0.4, 0.6), autoscale_on = False, title = 'Zoom window')
# 	x, y, s, c = np.random.rand(4, 200)
# 	s *= 200
# 	axsrc.scatter(x, y, s, c)
# 	axzoom.scatter(x, y, s, c)
# 	figsrc.canvas.mpl_connect('button_press_event', onpress)
# 	plt.show()

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting