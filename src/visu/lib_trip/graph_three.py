#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D

def graph_three():
	X = np.arange(-5, 5, 0.25)
	Y = np.arange(-5, 5, 0.25)
	X, Y = np.meshgrid(X, Y)
	R = np.sqrt(X**2 + Y**2)
	Z = np.sin(R)
	fig = plt.figure()
	ax = Axes3D(fig)
	ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap=cm.viridis)
	plt.show()

# funny drawings from https://matplotlib.org/tutorials/introductory/pyplot.html
# nothing to do with our visu, just experimenting
