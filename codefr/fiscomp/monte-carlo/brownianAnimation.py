import numpy as np
from random import choice
import matplotlib.pylab as plt
import matplotlib.animation as animation

# Constants
L = 101
x0 = L//2
y0 = L//2

rightBorder = L-1
toppomBorder = L-1
leftBorder = 0
bottomBorder = 0

N = 10000

GRID = np.zeros((L,L,N), bool)

i = x0
j = y0
GRID[i,j,0] = 1

for t in range(1,N):

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
	if walk == 'U':
		j += 1
	elif walk == 'D':
		j -= 1
	elif walk == 'R':
		i += 1
	else:
		i -= 1

	GRID[i,j,t] = 1
	
# setting plot
fig = plt.figure()
im = plt.imshow(GRID[:,:,0], origin='lower')

def update(t):
	im.set_array(GRID[:,:,t])
	plt.title(f'{t}')

ani = animation.FuncAnimation(fig,
							func=update,
							frames=N,
							repeat=False,
							interval=.1)

plt.show()