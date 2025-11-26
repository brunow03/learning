from math import sin
from numpy import arange
from pylab import plot, show

def g(x, u):
	return """g of x and u"""

a = 0.0
b = 1.0
N = 10
h = (b-a)/N

upoints = arange(a,b,h)
tpoints = []
xpoints = []

x = 1.0
for u in upoints:
	tpoints.append(u/(1-u))
	xpoints.append(x)
	k1 = h*g(x, u)
	k2 = h*g(x + 0.5*k1, u + 0.5*h)
	k3 = h*g(x + 0.5*k2, u + 0.5*h)
	k4 = h*g(x + k3, u + h)
	x += (k1 + 2*k2 + 2*k3 + k4)/6

plot(tpoints, xpoints)
show()