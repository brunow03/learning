import numpy as np
from random import choice
import matplotlib.pylab as plt

# Constants
L = 101
x0 = L//2
y0 = L//2
delay = .0000000001

rightBorder = L-1
toppomBorder = L-1
leftBorder = 0
bottomBorder = 0

N = 10000

GRID = np.zeros((L,L), bool)

i = x0
j = y0
GRID[i][j] = 1

for k in range(N):
	
	direction = ['U', 'D', 'L', 'R']

	if i == 0:
		direction.remove('L')
	if i == L-1:
		direction.remove('R')
	if j == L-1:
		direction.remove('U')
	if j == 0:
		direction.remove('D')

	walk = choice(direction)
	GRID[i][j] = 0

	if walk == 'U':
		j += 1
	elif walk == 'D':
		j -= 1
	elif walk == 'R':
		i += 1
	else:
		i -= 1

	GRID[i][j] = 1

	plt.imshow(GRID)
	plt.title(f'{k}')

plt.show()