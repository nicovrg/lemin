#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def graph_three():
	fig = plt.figure()
	fig.set_facecolor("#15202b")

	data = {}
	data['a'] = np.arange(50)
	data['b'] = data['a'] + 10 * np.random.randn(50)
	data['c'] = np.random.randint(0, 50, 50)
	data['d'] = np.random.randn(50)
	data['d'] = np.abs(data['d']) * 100

	plt.scatter('a', 'b', c = 'c', s = 'd', data = data)
	plt.xlabel('entry a')
	plt.ylabel('entry b')
	plt.show()

# funny drawings from https://matplotlib.org/tutorials/introductory/pyplot.html
# nothing to do with our visu, just experimenting