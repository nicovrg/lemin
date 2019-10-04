#!/usr/bin/python
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
from matplotlib.path import Path
from matplotlib.patches import PathPatch

def graph_four():
	delta = 0.025
	x = y = np.arange(-3.0, 3.0, delta)
	X, Y = np.meshgrid(x, y)
	Z1 = np.exp(-X**2 - Y**2)
	Z2 = np.exp(-(X - 1)**2 - (Y - 1)**2)
	Z = (Z1 - Z2) * 2

	fig, ax = plt.subplots()
	im = ax.imshow(Z, interpolation = 'bilinear', cmap = cm.RdYlGn, origin = 'lower', extent = [-3, 3, -3, 3], vmax = abs(Z).max(), vmin = -abs(Z).max())
	plt.show()

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting