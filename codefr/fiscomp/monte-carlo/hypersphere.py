from math import sin,sqrt
from random import random
import numpy as np

N = 10000
a = -1
b = 1
V = (b - a)**10

def f(r):
	return np.sum(ri**2 for ri in r)

I = 0
for i in range(N):
	r = [2*random() for i in range(10)]
	I += f(r)

I *= V/N

print(f'Integral value: {I}')