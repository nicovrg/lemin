#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def graph_two():
	curve = np.arange(0.0, 5.0, 0.02)

	fig = plt.figure()
	fig.set_facecolor("#15202b")
	
	plt.subplot(111)
	plt.plot(curve, np.cos(2 * np.pi * curve), 'bo')
	plt.axis('off')
	plt.show()


# funny drawings from https://matplotlib.org/tutorials/introductory/pyplot.html
# nothing to do with our visu, just experimenting