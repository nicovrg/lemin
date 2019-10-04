#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def f(num):
    return np.exp(-num) * np.cos(2 * np.pi * num)

def graph_one():
	curve = np.arange(0.0, 5.0, 0.1)

	fig = plt.figure()
	fig.set_facecolor("#15202b")

	plt.subplot(111)
	plt.plot(curve, f(curve), 'bo')
	plt.axis('off')
	plt.show()

# funny drawings from https://matplotlib.org/tutorials/introductory/pyplot.html
# nothing to do with our visu, just experimenting