import numpy as np
from random import randrange, seed

D = 7
N = 2e6

n = randrange(1,D)
m = randrange(1,D)

print('Fist exercise:')
print('First number: {}'.format(n))
print('Second number: {}'.format(m))

print('\nSecond exercise:')

count = 0
for i in range(int(N)):
	n = randrange(1,D)
	m = randrange(1,D)
	if n == m == 6:
		count += 1

fraction = count/(int(2e6))
print('Count: {}'.format(count))
print('Fraction obtained: {}'.format(fraction))
print('Expected value (1/36): {}'.format(1/36))
