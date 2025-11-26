from math import sin
from numpy import arange, floor
from pylab import plot, show, ylabel, xlabel

RC = 1
Vout0 = 0.0
ti = 0.0
tf = 10.0
N = 1000000
h = (tf-ti)/N

def Vin(t):
	if floor(2*t)%2 == 0:
		return 1
	else:
		return -1

def f(x, t):
	return (Vin(t) - x)/RC

tpoints = arange(ti,tf,h)
xpoints = []
x = Vout0

for t in tpoints:
	xpoints.append(x)
	k1 = h*f(x, t)
	k2 = h*f(x + 0.5*k1, t + 0.5*h)
	k3 = h*f(x + 0.5*k2, t + 0.5*h)
	k4 = h*f(x + k3, t + h)
	x += (k1 + 2*k2 + 2*k3 + k4)/6

plot(tpoints, xpoints)
ylabel('Voltage Out')
xlabel('Time')

vin = [0.4*Vin(t) for t in tpoints]
plot(tpoints, vin)

show()

