import numpy as np
from math import e, pi
import matplotlib.pyplot as plt
import re

pianoData = []
trumpetData = []

# Reading data from piano
with open('piano.txt') as file:
	for line in file.readlines():
		pianoData.append(re.split(r'\n',line)[0])

# Reading data from trumpet
with open('trumpet.txt') as file:
	for line in file.readlines():
		trumpetData.append(re.split(r'\n',line)[0])


for i in range(len(trumpetData)):
	trumpetData[i] = int(trumpetData[i])
	pianoData[i] = int(pianoData[i])

# Note rfft. It plot only the first necessary half of the whole data
cPiano = abs(np.fft.rfft(pianoData))
cTrumpet = abs(np.fft.rfft(trumpetData))

# Plotting piano
plt.figure(1)
plt.title('Piano')
plt.plot(cPiano)

# Plotting trumpet
plt.figure(2)
plt.title('Trumpet')
plt.plot(cTrumpet)

plt.show()

# Note they were playing. Data: piano
