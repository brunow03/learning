import numpy as np
import matplotlib.pylab as plt

N = 1000
tau = 3.053*60
mu = np.log(2)/tau
tmax = 1000
dt = 1

randUni = [np.random.random() for i in range(N)]
randExp = [(-1/mu)*np.log(1 - z) for z in randUni] 

randExp = np.sort(randExp)




tpoints = np.arange(0,tmax,dt)
plt.plot(randExp)
plt.plot(randUni)
plt.show()

