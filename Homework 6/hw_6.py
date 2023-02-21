from enum import auto
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d

# ! problem 1
x = np.linspace(0, 2.0*np.pi, 512)
y = 2 * np.sin(x) - 3 * np.cos(2*x)
plt.plot(x, y, color = 'black', linewidth = '4', marker= '^',markersize = 15, markevery = 32) 
plt.xlim(0,2*np.pi)
plt.ylim(min(y),max(y))
plt.show()
peaks = []
for i in range(1,511):
    if y[i] > y[i-1] and y[i] > y[i+1]:
            peaks.append(x[i])
print(peaks)

# ! problem 2
angle = (np.pi / 180) * (45)
M = 120 # N*m
Mz = -M*np.sin(angle) # N*m
My = -M*np.cos(angle) # N*m
Iy = 1584e-8 #m^4
Iz = 736e-8 #m^4
z,y = np.meshgrid( np.arange(-.05, .05, .0005), np.arange(-.08, .08, .0005) )
hole = np.logical_and( abs(y) < .07, abs(z) < .04)
print(hole)
z[hole] = np.nan
y[hole] = np.nan
o = -(Mz*y / Iz) + (My*z / Iy)

fig = plt.figure(3, figsize=(10,16))
plt.clf()
ax = plt.axes(projection='3d')
ax.plot_surface(z*100,y*100,o/1e6)
ax.set_xlabel('Horizontal position (cm)')
ax.set_ylabel('Vertical Position (cm)')
ax.set_zlabel('Stress (Mpa)')
plt.show()