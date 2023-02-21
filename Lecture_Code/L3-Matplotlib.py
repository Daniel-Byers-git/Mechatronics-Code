# import numpy as np
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import axes3d

# #linspace provide a range with equal spacing
# #linspace(start,stop,number_of_entries)
# x = np.linspace(0, 2.000*np.pi, 500)
# print(x)
# y = 2*np.sin(x) - 3*np.cos(2*x)
# print(y)

# #Matplot is a plotting library for python
# #figure initializes a figure with id (not necessary for rapid testing)
# fig = plt.figure()

# plt.plot(x,y)
# plt.show()
# #blue circles
# plt.plot(x, y, 'bo')
# plt.show()
# #red plus
# plt.plot(x,y, 'r+') 
# plt.show()

# #other options
# plt.plot(x, y, color='green', marker=',', linestyle='dashed',linewidth=2, markersize=12)
# plt.show()

# #Read Docs
# # https://matplotlib.org/stable/api/_as_gen/matplotlib.pyplot.plot.html

# #For 3d Graphs
# #Start with figure for id add subplot or axes(projection='3d')
# ax = plt.figure().add_subplot(projection='3d')

# fig = plt.figure()
# ax = plt.axes(projection='3d')

# # Prepare arrays x, y, z
# theta = np.linspace(-4 * np.pi, 4 * np.pi, 100)
# z = np.linspace(-2, 2, 100)
# r = z**2 + 1
# x = r * np.sin(theta)
# y = r * np.cos(theta)

# ax.plot(x, y, z, label='parametric curve')
# ax.legend()
# ax.set_xlabel('Custom X Lbl')
# ax.set_ylabel('Custom Y Lbl')
# ax.set_zlabel('Custom Z Lbl')

# plt.show()

# z,y = np.meshgrid(np.arange(0.05,-0.05,-0.0005),
#                   np.arange(0.08,-0.08,-0.0005))
# print(z)
# print(y)
# plt.plot(z,y)
# plt.show()


import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d

x = np.linspace(0,2.0*np.pi,50)
y = np.sin(x)
y2 = np.cos(x)

# y[y>.75] = np.nan
# index_where = np.where(y>.75)
# print(index_where)
# y[index_where] = .75

plt.figure(1)
plt.plot(x, y, label = "cos")
plt.plot(x, y2, label = "sin")
plt.legend()
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title("Plot title")
plt.xlim(0,1)
plt.show()


plt.figure(2)
plt.subplot(1,2,1)
plt.plot(x,y)
plt.subplot(1,2,2)
plt.plot(x,y2)
plt.show()




M    = 120          # (Nm)  Applied bending moment
Mz   = -M*np.sqrt(2)/2 # (Nm)  z-component of moment
My   = -M*np.sqrt(2)/2 # (Nm)  y-component of moment
Iz   =  736e-8      # (m^4) Moment of inertia about z axis
Iy   = 1584e-8      # (m^4) Moment of inertia about y axis
z,y = np.meshgrid(np.arange(0.05,-0.05,-0.0005),
                  np.arange(0.08,-0.08,-0.0005)) # Set up grid
badInd = np.logical_and(abs(y)<0.07 , abs(z)<0.04) # Identify indices not on cross-section
z[badInd] = np.nan                         # Remove bad indices from z grid
y[badInd] = np.nan                         # Remove bad indices from y grid
sigma = -Mz*y/Iz + My*z/Iy              # (Pa) Calculate normal stress



def factorial(num):
    if num == 1:
        return 1
    else:
        return num * factorial(num - 1)

print(factorial(3))
































plt.figure(3,figsize=(10,16))
plt.clf()                          # Prepare figure
ax = plt.axes(projection='3d')
ax.plot_surface(z*100,y*100,sigma/1e6) # Plot surface (in cm and MPa)
ax.set_xlabel('Horizontal position (cm)')
ax.set_ylabel('Vertical position (cm)')
ax.set_zlabel('Stress (MPa)')
plt.show()










# # -*- coding: utf-8 -*-
# """
# Created on Tue Jan 14 13:51:35 2020

# @author: kmcfall
# """

# import numpy as np
# import matplotlib.pyplot as plot
# print("Problem 1")
# print("See Figure 1")
# x     = np.linspace(0, 2.000*np.pi, 500    )
# xMark = np.arange  (0, 2.001*np.pi, np.pi/8)
# y     = 2*np.sin(x    ) - 3*np.cos(2*x    )
# yMark = 2*np.sin(xMark) - 3*np.cos(2*xMark)
# plot.figure(1)
# plot.clf()
# plot.plot(x,y,'k-',linewidth=4)
# plot.plot(xMark,yMark,'k^',markersize=15)
# plot.axis((0,2*np.pi, min(y), max(y)))
# plot.show()
# print('Peaks at x values of:')
# # Solution with element-wise operations
# # y[1:] > y[:-1] compares if the next value is greater than the previous (values increasing)
# #    Note that the resulting array is one smaller than the original array
# # y[1:] < y[:-1] compares if the next value is smaller than the previous (values decreasing)
# # y[2:] < y[1:-1] is the same comparison but shifts the values to the left by one
# #    Note that the resulting array is two smaller than the original array
# # By shifting the values one to the left, we can compare where increasing matches up with decreasing in the next position
# #    i.e. we want to compare where both y[1:] > y[:-1] and y[2:] < y[1:-1] are true
# #    However, y[1:] > y[:-1] has one more element than y[2:] < y[1:-1] so
# #    we remove one element from y[1:] > y[:-1] by ignoring the last one with y[1:-1] > y[:-2]
# # np.logical_and returns an element-wise AND of the numpy array
# # np.where returns the indices where increasing and decreasing match up
# # Finally numerical indexing is used to locate the x position where y has peaks
# print(x[np.where(np.logical_and(y[2:] < y[1:-1] , y[1:-1] > y[:-2]))])
# # A more straightforward but less elegant approach is to loop through all the values
# for i in range(0,len(y)-2):
#     if y[i+1]>y[i] and y[i+2]<y[i+1]:
#         print(x[i])
        
# import numpy as np
# import matplotlib.pyplot as plot

# from mpl_toolkits.mplot3d import Axes3D

# print(" ")
# print("Problem 2")
# print("See Figure 2")
# M    = 120          # (Nm)  Applied bending moment
# Mz   = -M*np.sqrt(2)/2 # (Nm)  z-component of moment
# My   = -M*np.sqrt(2)/2 # (Nm)  y-component of moment
# Iz   =  736e-8      # (m^4) Moment of inertia about z axis
# Iy   = 1584e-8      # (m^4) Moment of inertia about y axis
# z,y = np.meshgrid(np.arange(0.05,-0.05,-0.0005),
#                   np.arange(0.08,-0.08,-0.0005)) # Set up grid
# badInd = np.logical_and(abs(y)<0.07 , abs(z)<0.04) # Identify indices not on cross-section
# z[badInd] = np.nan                         # Remove bad indices from z grid
# y[badInd] = np.nan                         # Remove bad indices from y grid
# sigma = -Mz*y/Iz + My*z/Iy              # (Pa) Calculate normal stress
# plot.figure(2,figsize=(10,16))
# plot.clf()                          # Prepare figure
# ax = plot.axes(projection='3d')
# ax.plot_surface(z*100,y*100,sigma/1e6) # Plot surface (in cm and MPa)
# ax.set_xlabel('Horizontal position (cm)')
# ax.set_ylabel('Vertical position (cm)')
# ax.set_zlabel('Stress (MPa)')
# plot.show()

# # import numpy as np
# # import matplotlib.pyplot as plot
# # from sklearn.cluster import KMeans
# # #from mpl_toolkits.mplot3d import Axes3D
# # print(" ")
# # print("Problem 3")
# # print("See Figure 3")
# # points = np.loadtxt('pointsHW06.txt')
# # plot.figure(3)
# # plot.clf()
# # ax = plot.gca(projection='3d')
# # k = KMeans(n_clusters=6).fit(points) # Perform clustering on points with 6 clusters
# # labels = k.labels_                   # Extract labels for each point in cluster
# # color = 'rgbmck'      # Colors for each cluster
# # for i in range(6):    # Loop through each cluster
# #     ind = (labels == i) # Pull out indices for the ith cluster
# #     ax.scatter(points[ind,0],points[ind,1],points[ind,2], s=1, marker='.',color=color[i])
# # ax.scatter(0,0,15)    # Plot this point just to make the scale more equal so objects look like themselves
    
