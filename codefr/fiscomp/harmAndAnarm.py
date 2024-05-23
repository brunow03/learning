import numpy as np
from pylab import xlabel, ylabel, plot, show

omega = 1

def f(r,t):
	x = r[0]
	y = r[1]
	fx = y
	fy = -(omega**2) * (x**3)
	return np.array([fx, fy],float)

y0 = 0.0
x0 = 1

ti = 0.0
tf = 50.0
N = 5000	
h = (tf - ti)/N

tpoints = np.arange(ti,tf,h)
xpoints = []
ypoints = []

r = np.array([x0,y0],float)
for t in tpoints:
    xpoints.append(r[0])
    ypoints.append(r[1])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6

plot(tpoints, ypoints)
xlabel('Time')
ylabel('x')
show()