from numpy import zeros
from cmath import exp, pi

def dft(y):
	N = len(y)
	c = zeros(N//2+1, complex)
	for k in range(N//2+1):
		for n in range(N):
			c[k] += y[n]*exp(-2j*pi*k*n/N)
	return c

