import numpy as np
from pylab import xlabel, ylabel, plot, show

M = 10
L = 2
G = 1

def f(r,t):
    x = r[0]
    y = r[1]
    vx = r[2]
    vy = r[3]
    radi = (x**2 + y**2)**0.5
    fx = vx
    fy = vy
    fvx = -G*M*(x/(radi**2 * np.sqrt(radi**2 + 0.25*L**2)))
    fvy = -G*M*(y/(radi**2 * np.sqrt(radi**2 + 0.25*L**2)))
    return np.array([fx, fy, fvx, fvy],float)

y0 = 0.0
x0 = 1.0
vx0 = 0.0
vy0 = 1.0

ti = 0.0
tf = 20.0
N = 100000
h = (tf - ti)/N

tpoints = np.arange(ti,tf,h)
xpoints = []
ypoints = []
vxpoints = []
vypoints = []

r = np.array([x0,y0,vx0,vy0],float)
for t in tpoints:
    xpoints.append(r[0])
    ypoints.append(r[1])
    vxpoints.append(r[2])
    vypoints.append(r[3])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6

plot(xpoints, ypoints)
xlabel('x')
ylabel('y')
show()