from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

# ! question one
data = np.loadtxt('pointsHW08.txt')
# print(data)
kmeans = KMeans(n_clusters = 6)
# print(kmeans)

kmeans = KMeans(n_clusters=6, init='k-means++', random_state=42) # ? appropriate random state?
Y = kmeans.fit_predict(data)

data1 = data[Y==0, :]
data2 = data[Y==1, :]
data3 = data[Y==2, :]
data4 = data[Y==3, :]
data5 = data[Y==4, :]
data6 = data[Y==5, :]

kplot = plt.axes(projection='3d')
kplot.set_xlim(-17.5,3)
kplot.set_ylim(-4, 11)
kplot.set_zlim(-1, 14)
# xline = np.arange(0, 18, .01)
# yline = np.arange(0, 18, .01)
# zline = np.arange(0, 18, .01)
# kplot.plot3D(xline, yline, zline, 'black')

msize = 2
kplot.scatter3D(data1[:,0], data1[:,1], data1[:,2], c = 'red',     s = msize)
kplot.scatter3D(data2[:,0], data2[:,1], data2[:,2], c = 'green',   s = msize)
kplot.scatter3D(data3[:,0], data3[:,1], data3[:,2], c = 'cyan',    s = msize)
kplot.scatter3D(data4[:,0], data4[:,1], data4[:,2], c = 'magenta', s = msize)
kplot.scatter3D(data5[:,0], data5[:,1], data5[:,2], c = 'black',   s = msize)
kplot.scatter3D(data6[:,0], data6[:,1], data6[:,2], c = 'blue',    s = msize)
kplot.scatter3D(0,0,15, c = 'pink')

# print(data.max)
plt.show() 
# print('Not sure what the random black line in the graph is.')

# ! question two
class myMat:
    def __init__(self, row = 0, col = 0): # default constructor: can pass values or if you don't they equal zero in this case
        self.mat = np.zeros((row, col)) # initializes object
    def addValue(self, row, col, val): # make method 'addValue' for myMat class
        if row >= self.mat.shape[0] or col >= self.mat.shape[1]: # checks if the indices of the value being added are within the current matrix
            y = np.zeros((row+1, col+1)) # ! I don't understand the extra steps professors solution does here.
                # ! In his solution he has:
                # ! y = np.zeros(( max(row+1, self.mat.shape[0]), max(col + 1, self.mat.shape[1]) ))
                # ? this would always return y = np.zeros(( row + 1, col + 1)) if the condition in the 'if' statement is true
            y[0:self.mat.shape[0], 0:self.mat.shape[1]] = self.mat # puts back original values of matrix into new sized matrix
            self.mat = y # sets object matrix equal to the temporary y matrix: which is the new sized matrix
        self.mat[row,col] = val # places value wanted to be added to the matrix
    def __mul__(self, rhs):
        return np.dot(self.mat, rhs.mat) # multiplies the matrices
    def __str__(self):
        return str(self.mat)


# code provided for question
x = myMat()       # Creates 0x0 array filled with zeros
print(x, '\n')    # !
x.addValue(1,1,6) # Expands size of x as needed
print(x, '\n')
x.addValue(2,2,5)
x.addValue(1,0,4)
x.addValue(0,1,3)
x.addValue(2,0,20)
x.addValue(2,0,2) # Overwrite previous value of 20 in this place
print(x,'\n')     # !
y = myMat(3,3)    # Creates 3x3 array filled with zeros
print(y, '\n')    # !
y.addValue(0,0,2)
y.addValue(0,1,3)
y.addValue(0,2,4)
y.addValue(1,0,5)
y.addValue(1,2,6)
y.addValue(2,1,7)
y.addValue(2,2,8)
print(y, '\n')    # ! 
print(x*y)        # !