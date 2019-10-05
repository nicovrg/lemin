#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

def onclick(event):
    print("click event: button={}, x={}, y={}".format(event.button, event.x, event.y))

def on_key(event):
    print("key event", event.key, event.xdata, event.ydata)

def print_event():
    fig, ax = plt.subplots()
    ax.plot(np.random.rand(10))
    cid = fig.canvas.mpl_connect("button_press_event", onclick)
    cid = fig.canvas.mpl_connect("key_press_event", on_key)
    plt.show()

# def print_event():
#     fig, ax = plt.subplots()
#     ax.plot(np.random.rand(10))
#     cid = fig.canvas.mpl_connect("button_press_event", onclick)
#     plt.show()