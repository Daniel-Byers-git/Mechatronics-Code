import numpy as np
import matplotlib.pyplot as pl

x = np.linspace(0, np.pi, 250)
y = 3*np.cos(3*x) - (np.sin(2*x))**2

pl.figure()
pl.plot(x,y, color = 'blue', label = 'exam eq')
pl.xlabel('X-Axis')
pl.ylabel('Y-Axis')
pl.title('Plotting 3*cos(3x) - sin(2x)^2')
pl.legend()
pl.show()