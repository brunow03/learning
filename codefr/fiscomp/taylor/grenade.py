import numpy as np
from pylab import plot,show,xlabel,ylabel

# initial conditions
v0 = np.array([4,4], float)
g = 1
time = np.linspace(0,4,401)

X = np.array([4 * t for t in time], float)
Y = np.array([4 * t - (g * t ** 2)/2 for t in time], float)
marks_x = np.array([v0[0] * t for t in range(5)], float)
marks_y = np.array([v0[1] * t - (g * t ** 2)/2 for t in range(5)], float)

plot(marks_x, marks_y,'x')
plot(X,Y)
xlabel('horizontal')
ylabel('vertical')
show()