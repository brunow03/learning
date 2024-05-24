from numpy import linspace, empty
from math import e, pi
import scipy.constants as constants
import scipy.integrate as integrate
from pylab import plot, show, xlabel, ylabel

kb = constants.k
c = constants.c
h = constants.Planck
lambda1 = 390e-9
lambda2 = 750e-9

def eta(T):
	return (15/(pi**4))*(list(integrate.quadrature(lambda x: -(1/(x**5))*( ((h*c/(kb*T))**2)/(pow(e, h*c/(kb*T*x)) - 1) ), lambda2, lambda1)))[0]

N = 100
T = linspace(300, 10000, 100)
ETA = empty(N, float)
for i in range(N):
	ETA[i] = eta(T[i])

# Plotting graph
plot(T,ETA)
show()