#!/usr/bin/python
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import matplotlib.cbook as cbook
from matplotlib.path import Path
from matplotlib.patches import PathPatch
	
def image_one():
	with cbook.get_sample_data('ada.png') as image_file:
		image = plt.imread(image_file)
	fig, ax = plt.subplots()
	ax.imshow(image)
	ax.axis('off')
	w, h = 512, 512
	with cbook.get_sample_data('ct.raw.gz') as datafile:
		s = datafile.read()
	A = np.frombuffer(s, np.uint16).astype(float).reshape((w, h))
	A /= A.max()
	fig, ax = plt.subplots()
	extent = (0, 25, 0, 25)
	im = ax.imshow(A, cmap = plt.cm.hot, origin = 'upper', extent = extent)
	markers = [(15.9, 14.5), (16.8, 15)]
	x, y = zip(*markers)
	ax.plot(x, y, 'o')
	ax.set_title('CT density')
	plt.show()

# funny drawings from https://matplotlib.org/gallery/images_contours_and_fields/image_demo.html
# nothing to do with our visu, just experimenting
