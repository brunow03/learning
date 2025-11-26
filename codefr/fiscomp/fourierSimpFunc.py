from numpy import linspace, empty
from math import e, pi, sin, cos
import matplotlib.pyplot as plt
from dft import dft
from scipy import signal

N = 1000

# Square-wave
t_sqrd = linspace(0, 2*pi, N)
f_sqrd = signal.square(t_sqrd, 0.5)
c_sqrd = dft(f_sqrd)

# Sawtooth
t_st = linspace(0, 2*pi, N)
f_st = signal.sawtooth(t_st, 0.5)
c_st = dft(f_st)

# Modulated
t_m = linspace(0, N, N)
f_m = [sin(pi*t/N)*sin(20*pi*t/N) for t in t_m]
c_m = dft(f_m)

# Plots
#plt.xlim(0,1000)
# Square
plt.figure(1)
plt.title('Square-wave')
plt.plot(c_sqrd)
# Sawtooth
plt.figure(2)
plt.title('Sawtooth')
plt.plot(c_st)
# Modulated
plt.figure(3)
plt.title('Modulated')
plt.plot(c_m)

plt.show()








"""
plot(f_sqrd)
show()
"""