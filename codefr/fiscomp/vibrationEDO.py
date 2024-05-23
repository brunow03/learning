import numpy as np
from pylab import xlabel, ylabel, plot, show, grid

k = 6
omega = 2
F1 = lambda t: np.cos(omega * t)
m = 1
N = 5

def f(r,t):
    X = []
    V = []

    for i in range(N):
        X.append(r[i])
        V.append(r[i+5])
    
    FX = [V[i] for i in range(N)]

    FV = [(k*(X[1] - X[0]) + F1(t))/m]
    for i in range(1,N-1):
        FV.append((k*(X[i+1] - X[i]) + k*(X[i-1] - X[i]))/m)
    FV.append((k*(X[N-2] - X[N-1]))/m)

    return np.array(FX + FV,float)

ti = 0.0
tf = 20.0
Npoints = 20000 
h = (tf - ti)/Npoints

tpoints = np.arange(ti,tf,h)
dxsipoints = list([] for i in range(N))
vxsipoints = list([] for i in range(N))

r = np.zeros(2*N, dtype=float)
for t in tpoints:
    for i in range(N):
        dxsipoints[i].append(r[i])
        vxsipoints[i].append(r[i+5])
    k1 = h*f(r,t)
    k2 = h*f(r+0.5*k1,t+0.5*h)
    k3 = h*f(r+0.5*k2,t+0.5*h)
    k4 = h*f(r+k3,t+h)
    r += (k1+2*k2+2*k3+k4)/6

for i in range(N):
    plot(tpoints, dxsipoints[i])
xlabel('time')
ylabel('displacement')
grid()
show()