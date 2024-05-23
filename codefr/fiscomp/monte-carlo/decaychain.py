from random import random
from numpy import arange
from pylab import plot,xlabel,ylabel,show,legend

# Constants
NBi213 = 10000
NBi209 = 0
NTl = 0
NPb = 0

tauPb = 3.3*60
tauTl = 2.2*60
tauBi = 46*60

dt = 1.0

pPb = 1 - 2**(-dt/tauPb)
pTl = 1 - 2**(-dt/tauTl)
pBi213 = 1 - 2**(-dt/tauBi)

pBiPb = 0.9791

tmax = 20000

# Lists of plot points
tpoints = arange(0.0,tmax,dt)

Tlpoints = []
Pbpoints = []
Bi213points = []
Bi209points = []

# Main loop
for t in tpoints:

    Tlpoints.append(NTl)
    Pbpoints.append(NPb)
    Bi209points.append(NBi209)
    Bi213points.append(NBi213)

    # Lead
    decayPb = 0
    for i in range(NPb):
        if random() < pPb:
            decayPb += 1
    NPb -= decayPb
    NBi209 += decayPb

    # Tallium
    decayTl = 0
    for i in range(NTl):
        if random() < pTl:
            decayTl += 1
    NTl -= decayTl
    NPb += decayTl

    # Bismute 213
    decayBiPb = 0
    decayBiTl = 0
    for i in range(NBi213):
        if random() < pBi213:
            if random() < pBiPb:
                decayBiPb += 1
            else:
                decayBiTl += 1
    NBi213 -= decayBiPb + decayBiTl
    NTl += decayBiTl
    NPb += decayBiPb
    
# Make the graph
plot(tpoints, Tlpoints, label='Tallium')
plot(tpoints, Pbpoints, label='Lead')
plot(tpoints, Bi213points, label='Bi213')
plot(tpoints, Bi209points, label='Bi209')
legend(loc='best')
xlabel("Time")
ylabel("Number of atoms")
show()

plot(tpoints, Tlpoints, label='Tallium')
show()