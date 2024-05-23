'''
Hit-or-miss method
'''
from math import sin,sqrt
from random import random


N = 1000000
a = 0
b = 2
h = 1
A = h*(b - a)

def f(x):
	return pow(sin(1/(2*(2 - x))), 2)

count = 0
for i in range(N):
	x = 2*random()
	y = random()
	if y < f(x):
		count += 1

I = (count * A) / N

print('Hit-or-miss method:')
print(f'With a sample o {N} points: {I}')

# Expected error
sigma = (sqrt(I * (A - I))) / (sqrt(N))

print(f'Expected error: {sigma}')


'''
Mean value method
'''

Imv = 0
fSqrBrcht = 0
fBrchtSqr = 0
for i in range(N):
	xi = 2*random()
	Imv += f(xi)
	fSqrBrcht += (f(xi))**2
	fBrchtSqr += f(xi)

# Calculated value
Imv *= (b - a)/N

# Error estimarion
fBrchtSqr *= 1/N
fBrchtSqr = fBrchtSqr ** 2
fSqrBrcht *= 1/N

varF = fSqrBrcht - fBrchtSqr

sigmaMV = (b - a) * sqrt(varF / N)

print('\n\nBy mean-value mathod:')
print(f'Integral value: {I}')
print(f'Estimated error: {sigmaMV}')











