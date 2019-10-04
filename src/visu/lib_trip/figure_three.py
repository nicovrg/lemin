#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

def figure_three():
	image = plt.imread('/Users/nivergne/Desktop/charizard.png')
	fig, ax = plt.subplots()
	ax.imshow(image)
	ax.axis('off')
	plt.show()
	# print(img)

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting