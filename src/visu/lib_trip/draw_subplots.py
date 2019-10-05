import matplotlib.pyplot as plt

def draw_subplots():
	fig = plt.figure()
	fig.add_subplot(221)   #top left
	fig.add_subplot(222)   #top right
	fig.add_subplot(223)   #bottom left
	fig.add_subplot(224)   #bottom right 
	plt.show()