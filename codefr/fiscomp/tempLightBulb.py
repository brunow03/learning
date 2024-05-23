from numpy import linspace, empty
from math import e, pi, sqrt
import scipy.constants as constants
import scipy.integrate as integrate
import matplotlib.pylab as plt


kb = constants.k
c = constants.c * 1000
h = constants.Planck
lambda1 = 390
lambda2 = 750

def eta(T):
	return (15/(pi**4))*(list(integrate.quad(lambda x: -(1/(x**5))*( ((h*c/(kb*T))**2)/(pow(e, h*c/(kb*T*x)) - 1) ), lambda2, lambda1)))[0]

N = 100
T = linspace(300, 10000, 100)
ETA = empty(N, float)
for i in range(N):
	ETA[i] = eta(T[i])

plt.plot(T, ETA)
plt.show()

"""
# Maximum
accuracy = 1
z = (1 + sqrt(5))/2

# Initial points
x1 = 
x4 = 
x2 = x4 - (x4 - x1)/z
x3 = x1 + (x4 - x1)/z

# Initial value of the function at the 4 points
f1 = eta(x1)
f2 = eta(x2)
f3 = eta(x3)
f4 = eta(x4)

# Main loop of the search process
while x4-x1 > accuracy:
	if f2 < f3:
		x4,f4 = x3,f3
		x3,f3 = x2,f2
		x2 = x4 - (x4 - x1)/z
		f2 = eta(x2)
	else:
		x1,f1 = x2,f2
		x2,f2 = x3,f3
		x3 = x1 + (x4 - x1)/z
		f3 = eta(x3)


# Point of maximum of eta
print("The maximum falls at", 0.5*(x1 + x4))
"""