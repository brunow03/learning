import numpy as np
from matplotlib.pylab import show,plot,xlabel,ylabel,savefig,grid

theta = np.linspace(0,np.pi,500)

M = R = g = 1
m1 = .7*M 
m2 = .8*M

def potential(theta, m):
	return -m*g*R*theta + M*g*R*(1 - np.cos(theta))

PE1 = [potential(t,m1) for t in theta]
PE2 = [potential(t,m2) for t in theta]



grid()
xlabel('\u03B8')
ylabel('U(\u03B8)')
plot(theta,PE1)
plot(theta,PE2)
savefig('./potential-energy-4-37.png')
show()