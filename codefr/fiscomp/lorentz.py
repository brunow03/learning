from math import sin
from numpy import array,arange
from pylab import plot,xlabel,show

# Constants
sigma = 10 
b = 8/3
r_ = 28

# Initial conditions
x0 = 0.0
y0 = 1.0
z0 = 0.0

def f(r,t):
    x = r[0]
    y = r[1]
    z = r[2]
    fx = sigma * (y-x)
    fy = r_ * x - y - x*z
    fz = x*y - b*z
    return array([fx,fy,fz],float)

ti = 0.0
tf = 50.0
N = 100000
h = (tf-ti)/N

tpoints = arange(ti,tf,h)
xpoints = []
ypoints = []
zpoints = []

# Loop
r = array([x0,y0,z0],float)
for t in tpoints:
    xpoints.append(r[0])
    ypoints.append(r[1])
    zpoints.append(r[2])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6
    
plot(xpoints,zpoints)
xlabel("t")
show()
