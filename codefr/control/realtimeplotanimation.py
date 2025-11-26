import datetime as dt
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# create figure for plotting
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
xs = []
ys = []

# this function is called periodicaly from FuncAnitaion
def animate(i, xs, ys):

	temp_c = round(np.random.random(),2)

	# add x and u to lists
	xs.append(dt.datetime.now().strftime('%H:%M:%S.%f'))
	ys.append(temp_c)

	# limit x and y lists to 20 items
	xs = xs[-20:]
	ys = ys[-20:]

	# draw x and y lists
	ax.clear()
	ax.plot(xs, ys)

	# format plot 
	plt.xticks(rotation=45, ha='right')
	plt.subplots_adjust(bottom=.3)
	plt.title('Temperature data')
	plt.ylabel('Temperature (deg C)')

# set up plot to call animate() function periodically
ani = animation.FuncAnimation(fig, animate, fargs=(xs,ys), interval=1000)
plt.show()