# simulation of a discrete model
import numpy as np
import matplotlib.pyplot as plt

# model parameters
a = .25
b = 2

# simulations parameters
Ts = .1
Tstop = 30
uk = 1 # step response
xk = 0
N = int(Tstop/Ts) # simulation length
data = []
data.append(xk)

plt.axis([0,N,0,10])

for k in range(N):
	xk1 = (1-a*Ts)*xk + Ts*b*uk
	xk = xk1
	data.append(xk1)

	plt.scatter(k,xk1)
	plt.pause(Ts)

plt.show()