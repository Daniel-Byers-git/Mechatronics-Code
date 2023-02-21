from turtle import distance
from cv2 import sqrt
import numpy as np
import matplotlib.pyplot as plt
import os

# ! question 1
data = np.loadtxt('HW07data.txt')
dist = data[0:16]
forces = data[16:33]
y_bar = np.average(forces)
for i in range(16,1,-1):
    m_num = (dist[1:i] * forces[1:i]) #because x[0] = 0
    m_den = (dist[1:i] * dist[1:i]) 
    m_num_val = np.sum(m_num)
    m_den_val = np.sum(m_den)
    m = m_num_val / m_den_val
    r_in = ((forces[:] - m*dist[:])**2) / ((forces[:] - y_bar)**2)
    r_in_val = sum(r_in)
    if(r_in_val <= 1):
        break
# r = np.sqrt( 1 - r_in_val ) don't really care. just wanted 'm'
fit = m*dist
plt.figure(1)
plt.scatter(dist, forces, marker = "*", color = 'blue', label = "Original Data")
plt.plot(dist, fit, color = 'green', label = "Best Fit")
plt.legend()
plt.xlabel('Distance (in.)')
plt.ylabel('Force (lbf)')
plt.show()

# ! question 2
f = 1.0
fn = 0
i = 1
while True:
    f = ((1 / (2*np.log10(2.51*.486 / 884.1*.05*50*np.sqrt(.01*i)))))**2
    if(abs(f-fn)<1e-6):
        break
    fn = f
    i += 1
v = np.arange(50,100,1)
p_drop = ( f * 1 * 884.1 / .05 * 2 ) * ((v[:])**2)
plt.figure(2)
plt.plot(v, p_drop, color = 'blue')
plt.xlabel('Flow Speed (m/s')
plt.ylabel('Pressure drop over 1 m of pipe (MPa)')
plt.show()

# ! question 3
x = np.arange(-5,5.1,.01)
y = np.arange(0,3.1,.01)
xx, yy = np.meshgrid(x, y, sparse=True)
z = np.sin(xx)*np.cos(yy)
hole = np.logical_and(yy<2, abs(xx)<sqrt(4-yy**2))
z[hole] = np.nan
plt.figure(3, figsize = (10,3))
plt.clf()
ax = plt.axes(projection = '3d')
ax.plot_surface(xx,yy,z)
plt.show()