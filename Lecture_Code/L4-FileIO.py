#!/usr/bin/env python3

#shebang - The shebang line in any script determines the 
# script's ability to be executed as a standalone executable

#However - In windows you must remap the python executable to a launcher (open)
#By doing file association

#File I/O - Built in and using OS

#Regular File IO in python3
#file object = open(file_name [, access_mode][, buffering])

# file_obj = open('pointsHW08.txt', "r")
# print(file_obj)
# file_obj.close()

# file_obj = open('pointsHW08.txt', "r")
#Read will read the entire file while passing a number will read x bytes(chars)
# print(file_obj.read())
# print(file_obj.read(100))
# obj = file_obj.read(10)
#The Tell() - tells you where you are in the file
# print(file_obj.tell())
#The seek will go back and forth through the file
# offset − This is the position of the read/write pointer within the file.
# whence − This is optional and defaults to 0 which means absolute file positioning, 
# other values are 1 which means seek relative to the current position and 
# 2 means seek relative to the file's end
# file_obj.seek(0,0)
# print(file_obj.read(20))
# file_obj.seek(10)
# print(file_obj.read(20))
# file_obj.close()


# file_obj = open('pointsHW08.txt', "r")
# #Read lines will read one line at a time (argument inside is the # of bytes)
# print(file_obj.readline())
# print(file_obj.readline())
# file_obj.close()

# file_obj = open('pointsHW08.txt', "r")
# for line in file_obj:
#     print(line)
# file_obj.close()

# file_obj = open('pointsHW08.txt', "r")
# for line_nr, line in enumerate(file_obj):
#     print(line_nr, line)
# file_obj.close()

# Writing to files
# file_obj = open('sample.txt', "a")
# file_obj.write("this is a sample file creation")
# file_obj.write("this is a sample file creation")
# file_obj.write("this is a sample file creation")
# file_obj.close()

# with is highly recommended with file object/ sql queries /etc
# python with has built in automatic destructor and clean ups

# with open("sample.txt", 'w', encoding = 'utf-8') as file_obj:
#     file_obj.write('sample line')
#     print(file_obj.readline()) # will this work?

# with open("sample.txt", 'w+', encoding = 'utf-8') as file_obj:
#     file_obj.write('sample line') # when you write you move to the next line
#     file_obj.seek(0,0)
#     print(file_obj.readline()) # will this work?

#notice no closure of file_obj

#OS way (python2) and more advanced
#commands include
# os.mkdir(dir)
# os.chdir(os.pardir)
# os.rmdir(dir)
# os.listdir(current_working_dir)
# os.remove(os.path.join(current_working_dir,filename))
# os.rename(oldname,newname)
# os.getcwd()...
# https://www.tutorialspoint.com/python/os_file_methods.htm
import os
# Open file
file_obj = os.open("sample2.txt", os.O_RDWR|os.O_CREAT)
# Writing text
msg = "This is a sample write. You must encode to bytes"
ret = os.write(file_obj, str.encode(msg))
print('number of bytes written = ', ret)
#lseek instead of seek
os.lseek(file_obj,0,0)
print(os.read(file_obj,10))
#you must decode to get the string ...
print(os.read(file_obj,10).decode())
os.close(file_obj)

# File Modes
# r - Opens a file for reading only. The file pointer is placed at the beginning of the file. This is the default mode.
# rb - Opens a file for reading only in binary format. The file pointer is placed at the beginning of the file. This is the default mode.
# r+ - Opens a file for both reading and writing. The file pointer placed at the beginning of the file.
# rb+ - Opens a file for both reading and writing in binary format. The file pointer placed at the beginning of the file.
# w - Opens a file for writing only. Overwrites the file if the file exists. If the file does not exist, creates a new file for writing.
# wb - Opens a file for writing only in binary format. Overwrites the file if the file exists. If the file does not exist, creates a new file for writing.
# w+ - Opens a file for both writing and reading. Overwrites the existing file if the file exists. If the file does not exist, creates a new file for reading and writing.
# wb+ - Opens a file for both writing and reading in binary format. Overwrites the existing file if the file exists. If the file does not exist, creates a new file for reading and writing.
# a - Opens a file for appending. The file pointer is at the end of the file if the file exists. That is, the file is in the append mode. If the file does not exist, it creates a new file for writing.
# ab - Opens a file for appending in binary format. The file pointer is at the end of the file if the file exists. That is, the file is in the append mode. If the file does not exist, it creates a new file for writing.
# a+ - Opens a file for both appending and reading. The file pointer is at the end of the file if the file exists. The file opens in the append mode. If the file does not exist, it creates a new file for reading and writing.
# ab+ - Opens a file for both appending and reading in binary format. The file pointer is at the end of the file if the file exists. The file opens in the append mode. If the file does not exist, it creates a new file for reading and writing.
# x - create file

#File Attributes
# file.closed - Returns true if file is closed, false otherwise.
# file.mode - Returns access mode with which file was opened.
# file.name - Returns name of the file.
# file.softspace - Returns false if space explicitly required with print, true otherwise.


# Python Plot and Classes 1.
# The contents of  pointsHW08.txt are 3D data points collected 
# from a LiDAR sensor for objects such asvehicles, 
# bicyclists, and pedestrians. Each row of the file contain the x, y, 
# and z positions of a point withunits of meters. 
# Load the data file and use sklearn.cluster.Kmeans to perform 
# clustering on the sixobjects in the data. 
# Display the points as a 3D scatter plot using 
# matplotlib.axes.Axes.scatterwhere each of the six 
# object clusters has a different color. 
# Tip: display a dummy point at (0,0,15) so that theaxes will be 
# reasonably equal in all directions and the objects will be less distorted.


import numpy as np
import matplotlib.pyplot as plot
from sklearn.cluster import KMeans
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import ticker

#numpy has its own file opening method for numbers.
data = np.loadtxt('pointsHW08.txt')
fig = plot.figure(1)
#subplot (nrrow nrcol index) = 111 default
# ax = fig.add_subplot(111, projection = '3d')
ax = plot.axes(projection='3d')
ax.scatter(data[:, 0], data[:, 1], data[:, 2], c = 'r')
# plot.show()

ax.set_xlim([-15,4])
ax.set_ylim([-4,11])
ax.set_zlim([0,16])
xticks = ticker.MaxNLocator(5)
ax.xaxis.set_major_locator(xticks)
plot.show()

fig2 = plot.figure(2)
ax = plot.axes(projection='3d')

k_n = KMeans(n_clusters=6).fit(data)
print(k_n)
print(k_n.labels_)
print(k_n.n_clusters)

color = 'rgbmck'      # Colors for each cluster color[0] = r
color = ['r','g','b','m','c','k']      # Colors for each cluster
for i in range(k_n.n_clusters):    # Loop through each cluster
    ind = (k_n.labels_== i) # Pull out indices for the ith cluster
    print(ind)
    ax.scatter(data[ind, 0], data[ind, 1], data[ind, 2], s=1, marker='.', color=color[i])
ax.set_xlim([-15,4])
ax.set_ylim([-4,11])
ax.set_zlim([0,16])
xticks = ticker.MaxNLocator(5)
ax.xaxis.set_major_locator(xticks)
plot.show()

#string conversion to int/hex/binary and back

string = 'a'
#ord - converts char into unicode int
int_val = ord(string[0])
print('integer value', int_val) # should be 97 based on the ascii table
print('hex', hex(int_val))
print('binary', bin(int_val))
# you can do base conversion for strings only if they contain the value in the base
#e.g. base 10 = 0-9
#base 16 = 0-9,a-f
#base 2 = 0 or 1
print(bin(int(string[0],16)))

#encode tranforms string to bytes you will see b for binary printer in front
encode_str = str.encode(string) 
print(encode_str)
#encoded values are binary but will convert to int
#if you print encoded_str[0] you will also get 97
print(encode_str[0])
#chr will go back to a string chr based on the encoding
print(chr(encode_str[0]))
#decode tranforms bytes to string
print(encode_str.decode())
