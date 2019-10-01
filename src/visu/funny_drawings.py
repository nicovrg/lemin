#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def f(num):
    return np.exp(-num) * np.cos(2 * np.pi * num)

def draw_one():
	curve = np.arange(0.0, 5.0, 0.1)

	fig = plt.figure()
	fig.set_facecolor("#15202b")

	plt.subplot(111)
	plt.plot(curve, f(curve), 'bo')
	plt.axis('off')
	plt.show()

def draw_two():
	curve = np.arange(0.0, 5.0, 0.02)

	fig = plt.figure()
	fig.set_facecolor("#15202b")
	
	plt.subplot(111)
	plt.plot(curve, np.cos(2 * np.pi * curve), 'bo')
	plt.axis('off')
	plt.show()

def draw_three():
	fig = plt.figure()
	fig.set_facecolor("#15202b")

	data = {}
	data['a'] = np.arange(50)
	data['b'] = data['a'] + 10 * np.random.randn(50)
	data['c'] = np.random.randint(0, 50, 50)
	data['d'] = np.random.randn(50)
	data['d'] = np.abs(data['d']) * 100

	plt.scatter('a', 'b', c='c', s='d', data=data)
	plt.xlabel('entry a')
	plt.ylabel('entry b')
	plt.show()

# https://matplotlib.org/tutorials/introductory/pyplot.html