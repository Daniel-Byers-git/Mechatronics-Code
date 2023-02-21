#Numpy is the python numeric library 
#Provides number manipulation capabilities 
#and mathematical functions
# import = include in c++ | as replaces the long name to shorter keyword
import numpy as np 

#common methods include the following:
#to create a range (array of numbers) 
#np.arange(start,stop,step,datatype(dtype)...)
#np.arange(stop)
numpy_array = np.arange(2, 10, 2 , dtype=np.int32)
# print(numpy_array)

#Can also create array by calling:
#np.array([]) - single dimension
#np.array([[],[]]) - two dimension
numpy_array = np.array([0,1,2,3,4,5])
# print(numpy_array)
numpy_array = np.array([[1,2,3],[4,5,6],[7,8,9]])
# print(numpy_array)

#To get the number of dimensions use ndmin
# print(numpy_array.ndim)

#To get the size of the array (total elements) use size
#Cannot use len() because it return to size in one dimension
# print(numpy_array.size)

#To get the total number of rows/cols use shape
#shape returns a tuple
# print(numpy_array.shape)
#You can unpack shape into individual variable
row, col = numpy_array.shape

#To select elements or splice array use [] indexing
#numpy_array[index] - single dim
#numpy_array[row,col] - single dim
# print(numpy_array[1,2])

#can use the : operator for splicing in both dimension
# start:stop:step 
# recall stop is non inclusive
#to get row 1 only.
# print(numpy_array[1,:])
#to get Col 1 only.
# print(numpy_array[:,1])
#to get index 0 and 1 in row 1
# print(numpy_array[1,0:2])

# You can apply mathematical functions on numpy arrays
# To double the array just multiply by 2
# print(numpy_array * 2)
# To divide the array by 2 us /2
# print(numpy_array / 2)

# if you want to multiply by specific list 
# or two arrays together you must maintain correct index 
# and mathematical opperation
# numpy_arr1 = np.array([1,2,3])
# numpy_arr2 = np.array([4,5,6])
# print(numpy_arr1 * numpy_arr2)

#For matrix operation maintain correct num of rows/col
# numpy_arr1 = np.array([[1,2,3],[4,5,6],[7,8,9]])
# print(numpy_arr1)
# numpy_arr2 = np.array([[3],[3],[3]])
# print(numpy_arr2)
# print(numpy_arr1 * numpy_arr2)

#Can pass conditional inside of numpy array and boolean array
#to get all elements greater than or equal to 3
# print(numpy_array[numpy_array>=3])
#to get bolean array 
# print(numpy_array >= 3)

#To reshape an array you can use reshape or transpose
#To Transpose use .T
# print(numpy_array.T)

# Reshape(tuple())
#reshape into 6 rows 1 col
numpy_array = np.array([[1,2,3],[4,5,6]])
# print(numpy_array.reshape(6,1))

#reshape into 6 col 1 row
# print(numpy_array.reshape(1,6))

#reshape to 3 row 2 col
# print(numpy_array.reshape((3,2)))

#single row
# print(numpy_array.reshape(numpy_array.size))

#-----------------------------------------------#

#to get index of max and min values in an array use 
# np.argmax / np.argmin
# numpy_arr = [3,4,5,3,1,4]
# print(np.argmin(numpy_arr))
# print(np.argmax(numpy_arr))

#to get max and min values in an array use 
# np.amax / np.amin
# numpy_arr = [3,4,5,3,1,4]
# print(np.amin(numpy_arr))
# print(np.amax(numpy_arr))

#you can append to array using .append()
# numpy_arr = [3,4,5,3,1,4]
# numpy_arr.append(7)
# print(numpy_arr)

#you can remove by poping an element or deleting an element
# numpy_arr = [3,4,5,3,1,4]
# print(numpy_arr.pop())

#delete uses np.delete(array,index,axis)
# numpy_arr = [3,4,5,3,1,4]
# numpy_arr = np.delete(numpy_arr, [2,4])
# print(numpy_arr)

#------------------------------------#
#other ways to declare array include
#one - array filled with ones
#ones(shape,dtype)
# print(np.ones((2,3)))

#zeros - array filled with ones
#zeros(shape,dtype)
# print(np.zeros((2,3)))

#full_like - array filled with specific val
#precreate array.
numpy_arr = np.arange(6)
# np.full_like(array, value)
numpy_arr = np.full_like(numpy_arr, 8)
# print(numpy_arr)

#-----------------------------------------
#Numpy has a random sublibrary as well
#Instead of typing the entire call you can create a var
random_var = np.random
#to create a random val
#np.random.randin(low,high,shape) - gives a random integer
# print(random_var.randint(3,10))

#np.random.rand() - gives a random val between 0 and 1
# print(random_var.rand())


#------------------------------------------------
#you can do math functions using sin/cos/asin/acos...
# print(np.sin(np.pi/2))

#meshgrid allows creating cartision grids
nx, ny = (3, 2)
x = np.linspace(0, 1, nx)
y = np.linspace(0, 1, ny)
xv, yv = np.meshgrid(x, y)
print(xv)
print(yv)

import matplotlib.pyplot as plt
x = np.arange(-5, 5, 0.1)
print(x)
y = np.arange(-5, 5, 0.1)
print(y)
xx, yy = np.meshgrid(x, y, sparse=True)
print(xx)
print(yy)
z = np.sin(xx**2 + yy**2) / (xx**2 + yy**2)
print(z)
h = plt.contourf(x, y, z)
plt.axis('scaled')
plt.show()


#Methods 
# all()
# any()
# take()
# put()
# apply_along_axis()
# apply_over_axes()
# argmin()
# argmax()
# nanargmin()
# nanargmax()
# amax()
# amin()
# insert()
# delete()
# append()
# around()
# flip()
# fliplr()
# flipud()
# triu()
# tril()
# tri()
# empty()
# empty_like()
# zeros()
# zeros_like()
# ones()
# ones_like()
# full_like()
# diag()
# diagflat()
# diag_indices()
# asmatrix()
# bmat()
# eye()
# roll()
# identity()
# arange()
# place()
# extract()
# compress()
# rot90()
# tile()
# reshape()
# ravel()
# isinf()
# isrealobj()
# isscalar()
# isneginf()
# isposinf()
# iscomplex()
# isnan()
# iscomplexobj()
# isreal()
# isfinite()
# isfortran()
# exp()
# exp2()
# fix()
# hypot()
# absolute()
# ceil()
# floor()
# degrees()
# radians()
# npv()
# fv()
# pv()
# power()
# float_power()
# log()
# log1()
# log2()
# log10()
# dot()
# vdot()
# trunc()
# divide()
# floor_divide()
# true_divide()
# random.rand()
# random.randn()
# ndarray.flat()
# expm1()
# bincount()
# rint()
# equal()
# not_equal()
# less()
# less_equal()
# greater()
# greater_equal()
# prod()
# square()
# cbrt()
# logical_or()
# logical_and()
# logical_not()
# logical_xor()
# array_equal()
# array_equiv()
# sin()
# cos()
# tan()
# sinh()
# cosh()
# tanh()
# arcsin()
# arccos()
# arctan()
# arctan2()