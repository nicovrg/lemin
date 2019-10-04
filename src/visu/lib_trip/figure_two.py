#!/usr/bin/python
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
from matplotlib.path import Path
from matplotlib.patches import PathPatch

def figure_two():
	x = np.arange(120).reshape((10, 12))

	interp = 'bilinear'
	fig, axs = plt.subplots(nrows = 2, sharex = True, figsize = (3, 5))
	axs[0].set_title('blue should be up')
	axs[0].imshow(x, origin = 'upper', interpolation = interp)

	axs[1].set_title('blue should be down')
	axs[1].imshow(x, origin = 'lower', interpolation = interp)
	plt.show()

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting