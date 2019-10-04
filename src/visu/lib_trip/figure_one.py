#!/usr/bin/python
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
from matplotlib.path import Path
from matplotlib.patches import PathPatch

def figure_one():
	A = np.random.rand(5, 5)

	fig, axs = plt.subplots(1, 3, figsize = (10, 3))
	for ax, interp in zip(axs, ['nearest', 'bilinear', 'bicubic']):
		ax.imshow(A, interpolation = interp)
    	ax.set_title(interp.capitalize())

	plt.show()

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting