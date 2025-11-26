'''
Functions for Model Creation and Manipulation:
• tf() - Create a transfer function system
• ss() - Create a state space system
• c2d() - Return a discrete-time system
• tf2ss() - Transform a transfer function to a state space system
• ss2tf() - Transform a state space system to a transfer function.
• series() - Return the series of 2 or more subsystems
• parallel() - Return the parallel of 2 or more subsystems
• feedback() - Return the feedback of system
• pade() - Creates a Pade Aproxomation, which is a Transfer function rep-
resentation of a Time Delay

Functions for Model Simulations:
• step response() - Step response of a linear system
• lsim() - Simulate the output of a linear system

Functions for Stability Analysis:
• step response() - Step response of a linear system
• lsim() - Simulate the output of a linear system
• pole() - Compute system poles
• zero() - Compute system zeros
• pzmap() - Plot a pole/zero map for a linear system
• margin() - Calculate gain and phase margins and associated crossover
frequencies
• stability margins() - Calculate stability margins and associated crossover
frequencies

Functions for Frequency Response:
• bode plot() - Create a Bode plot for a system
• mag2db() - Convert a magnitude to decibels (dB)
• db2mag() - Convert a gain in decibels (dB) to a magnitude
'''

import matplotlib.pyplot as plt
from control.matlab import *

# Parameters defining the systems
m = 250.0 	# system mass
k = 40.0 	# spring constant
b = 60.0 	# damping constant

# System matrices
A = [[0,1.], [−k/m, −b/m]]
B = [[0], [1/m]]
C = [[1., 0]]
sys = ss(A, B, C, 0)

# Step response for the system
plt.figure(1)
yout, T = step(sys)
plt.plot(T.T, yout.T)

# Bode plot for the system
plt.figure(2)
mag, phase, om = bode(sys)

'''
Basic transfer function in pytohn
'''

import numpy as np
import control

num = np.array([3])
den = np.array([4, 1])

H = control.tf(num, den)

print('H(s) =', H)

'''
Space state models

ẋ = Ax + Bu(29.3)
y = Cx + Du
'''

# System matrices
A = [[0 ,1 ], [−1, −3]]
B = [[0 ,0], [2 , 4]]
C = [[5 ,6]]
D = [[7 ,0]]
ssmodel = control.ss(A, B, C, D)

