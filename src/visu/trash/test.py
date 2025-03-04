# !/usr/bin/python
import matplotlib.pyplot as plt
import matplotlib.animation as ani

fig, ax = plt.subplots()
txt = fig.text(0.5,0.5,'0')

def update_time():
	t = 0
	t_max = 10
	while t<t_max:
		t += anim.direction
		yield t

def update_plot(t):
	txt.set_text('%s'%t)
	return txt

def on_press(event):
	if event.key.isspace():
		if anim.running:
			anim.event_source.stop()
			print "=========================="
		else:
			anim.event_source.start()
		anim.running ^= True
	elif event.key == 'left':
		anim.direction = -1
	elif event.key == 'right':
		anim.direction = +1

	# Manually update the plot
	if event.key in ['left','right']:
		t = anim.frame_seq.next()
		update_plot(t)
		plt.draw()

fig.canvas.mpl_connect('key_press_event', on_press)
anim = ani.FuncAnimation(fig, update_plot, frames=update_time, interval=1000, repeat=True)
anim.running = True
anim.direction = +1
plt.show()