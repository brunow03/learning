from math import sin
from numpy import array,arange
from pylab import plot,xlabel,show

# Constants
alpha = 1
beta = 0.5
gamma = 0.5
delta = 2

# Initial conditions
x0 = 2.0
y0 = 2.0

def f(r,t):
    x = r[0]
    y = r[1]
    fx = alpha*x - beta*x*y     # x(t)
    fy = gamma*x*y - delta*y    # y(t)
    return array([fx,fy],float)

ti = 0.0
tf = 30.0
N = 15000
h = (tf-ti)/N

tpoints = arange(ti,tf,h)
xpoints = []
ypoints = []

# Loop
r = array([x0,y0],float)
for t in tpoints:
    xpoints.append(r[0])
    ypoints.append(r[1])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6
    
plot(tpoints,xpoints, "b")
plot(tpoints,ypoints, "orange")
xlabel("t")
show()
