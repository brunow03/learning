import datetime as dt
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# create figure for plot
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
xs = []
ys = []

xk = 0 # initial value for x

# this is called periodically from FuncAnimation
def simulation(i, xs, ys):

	# model parameters
	a = .25
	b = 2

	# simulations parameters
	Ts = .1 # sampling rate
	uk = 1 # step response
	global xk # since we change x inside a function we define it as a global variable

	# model of discrete system
	xk1 = (1-a*Ts)+xk + Ts*b*uk
	xk=xk1

	# add x and y to lists
	xs.append(dt.datetime.now().strftime('%H:%M:%S.%f'))
	ys.append(xk1)

	N = 60 # limit x and y lists to N items
	xs = xs[-N:]
	ys = ys[-N:]

	# draw x and y lists
	ax.clear()
	ax.plot(xs,ys)

	# format plot
	plt.xticks(rotation=45, ha='right')
	plt.subplots_adjust(bottom=.3)
	plt.title('Simulation of dxdt = -ax + bu')
	plt.ylabel('x')
	plt.xlabel('t [s]')
	plt.grid()

# set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig, simulation, fargs=(xs, ys), interval=100)
plt.show()