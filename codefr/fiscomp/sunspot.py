from numpy import linspace, exp, pi, where, isclose
import matplotlib.pyplot as plt
import re
from scipy import fft

# mais ou menos 130
with open('sunspot.txt') as f:
	lines = f.readlines()

year = []
nSpots = []
for line in lines:
	year.append(int(	[0]))
	nSpots.append(float(re.split(r'\t',line)[1]))

c = fft.dst	(nSpots)
c_abs = pow(abs(c), 2)
# print(len(c))
# print(len(year))
# print(len(nSpots))

plt.figure(1)
plt.title('Number of observed sunspots each month')
plt.ylabel('Number of sunspots')
plt.xlabel('Months since January 1749')
plt.plot(year, nSpots)

plt.figure(2)
plt.title('Fourier coeficients squared')
plt.ylabel('Amplitude')
#plt.xlabel('Months since January 1749')
plt.plot(c_abs)

plt.show()

cMax = max(c_abs)
cMax_index = where(c_abs == cMax)
print(cMax)
print(cMax_index)
print(c_abs[0])
