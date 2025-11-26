import numpy as np
from pylab import plot, show, xlabel, ylabel

# Constants
g = 9.81
l = 0.1
C = 2.0
OMEGA = 5.0

# Initial Conditions
theta0 = 0.0
omega0 = 0.0

# ODEs
def f(r,t):
	theta = r[0]
	omega = r[1]
	ftheta = omega
	fomega = -(g/l) * np.sin(theta) + C * np.cos(theta) * np.sin(OMEGA*t)
	return np.array([ftheta, fomega],float)

ti = 0.0
tf = 100.0
N = 10000
h = (tf-ti)/N

tpoints = np.arange(ti,tf,h)
omegapoints = []    
thetapoints = []

# 4th order Runge Kuta Loop
r = np.array([theta0,omega0],float)
for t in tpoints:
    thetapoints.append(r[0])
    omegapoints.append(r[1])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6

# Plotting graph
plot(tpoints, thetapoints)
xlabel('Time')
ylabel('Theta')
show()