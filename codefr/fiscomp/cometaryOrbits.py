import numpy as np
from pylab import xlabel, ylabel, grid, show, plot, title
from scipy import constants
from timeit import default_timer as timer

# Constants
G = constants.gravitational_constant
M = 1.9891e30
radius = lambda x,y: np.sqrt(x**2 + y**2)

# Calculating functions
def f(r):
    x = r[0]
    y = r[1]
    vx = r[2]
    vy = r[3]
    radi = radius(x,y)
    fx = vx
    fy = vy
    fvx = -G*M*x/(radi**3)
    fvy = -G*M*y/(radi**3)
    return np.array([fx, fy, fvx, fvy],float)

# Initial values
x0 = 4e12
y0 = 0.0
vx0 = 0.0
vy0 = 500

# Defining step size
ti = 0
tf = 3.3e9
h = 1.5e4

tpoints = np.arange(ti,tf,h)
xpoints = []
ypoints = []
vxpoints = []
vypoints = []
turns = 0

# Runge kutta - fixed size step
start = timer()
r = np.array([x0,y0,vx0,vy0],float)
for t in tpoints:
    xpoints.append(r[0])
    ypoints.append(r[1])
    vxpoints.append(r[2])
    vypoints.append(r[3])
    if turns == 2:
    	print('{:E}'.format(t))
    	break
    k1 = h*f(r)
    k2 = h*f(r+0.5*k1)
    k3 = h*f(r+0.5*k2)
    k4 = h*f(r+k3)
    r += (k1+2*k2+2*k3+k4)/6
    if r[1] > 0 and ypoints[-1] < 0 and len(ypoints) > 0:
    	turns += 1
end = timer()

print('Elapsed time: {}'.format(end - start))
print(ypoints[-1])

# Plottage
title('Comet\'s orbit')
xlabel('x')
ylabel('y')
grid()
plot(xpoints, ypoints)
show()