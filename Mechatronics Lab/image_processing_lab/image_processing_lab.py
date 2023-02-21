import cv2
import matplotlib.pyplot as plt
import numpy as np
BGR = cv2.imread('folders00.JPG')
RGB = cv2.cvtColor(BGR, cv2.COLOR_BGR2RGB)
# print(RGB.shape)
x = np.arange(0, RGB.shape[1])
y = np.arange(0, RGB.shape[0])
xx, yy = np.meshgrid(x, y)
R = RGB[:,:,0]
G = RGB[:,:,1]
B = RGB[:,:,2]
plt.figure(1)
plt.clf()
plt.imshow(RGB)
plt.pause(1)
p = plt.ginput(4)
p = np.array(p)
# print(p)

m1 = (p[1][1] - p[0][1]) / (p[1][0] - p[0][0]) # ! less than = 0
b1 = p[1][1] - m1*p[1][0]
m2 = (p[2][1] - p[1][1]) / (p[2][0] - p[1][0]) # ! larger than = 0
b2 = p[2][1] - m2*p[2][0]
m3 = (p[3][1] - p[2][1]) / (p[3][0] - p[2][0]) # ! larger than = 0
b3 = p[3][1] - m3*p[3][0]
m4 = (p[0][1] - p[3][1]) / (p[0][0] - p[3][0]) # ! less than = 0
b4 = p[0][1] - m4*p[0][0]
xp = p[:,0]
yp = p[:,1]
xc = np.mean(xp)
yc = np.mean(yp)

if (yc > m1*xc + b1):
    R[yy < m1*xx + b1] = 0 # ! x2 - x1
    G[yy < m1*xx + b1] = 0
    B[yy < m1*xx + b1] = 0
else:
    R[yy > m1*xx + b1] = 0 # ! x2 - x1
    G[yy > m1*xx + b1] = 0
    B[yy > m1*xx + b1] = 0

if (yc > m2*xc + b2):
    R[yy < m2*xx + b2] = 0 # ! x3 - x2
    G[yy < m2*xx + b2] = 0
    B[yy < m2*xx + b2] = 0
else:
    R[yy > m2*xx + b2] = 0 # ! x3 - x2
    G[yy > m2*xx + b2] = 0
    B[yy > m2*xx + b2] = 0

if (yc > m3*xc + b3):
    R[yy < m3*xx + b3] = 0 # ! x4 - x3
    G[yy < m3*xx + b3] = 0
    B[yy < m3*xx + b3] = 0
else:
    R[yy > m3*xx + b3] = 0 # ! x4 - x3
    G[yy > m3*xx + b3] = 0
    B[yy > m3*xx + b3] = 0

if (yc > m4*xc + b4):
    R[yy < m4*xx + b4] = 0 # ! x1 - x4
    G[yy < m4*xx + b4] = 0
    B[yy < m4*xx + b4] = 0
else: 
    R[yy > m4*xx + b4] = 0 # ! x1 - x4
    G[yy > m4*xx + b4] = 0
    B[yy > m4*xx + b4] = 0

RGB[:,:,0] = R
RGB[:,:,1] = G
RGB[:,:,2] = B
plt.figure(2)
plt.clf()
plt.imshow(RGB)
plt.show()
plt.pause(1)

Rn = R[R>0]
Gn = G[G>0]
Bn = B[B>0]
Rmean = np.mean(Rn)
Gmean = np.mean(Gn)
Bmean = np.mean(Bn)

plt.figure(3)
plt.clf()
plt.subplot(3,1,1) # ! red
plt.hist(Rn, np.arange(0,256), color = 'r')
plt.axis([0,255,0,plt.axis()[3]])
plt.subplot(3,1,2) # ! green
plt.hist(Gn, np.arange(0,256), color = 'g')
plt.axis([0,255,0,plt.axis()[3]])
plt.subplot(3,1,3) # ! blue
plt.hist(Bn, np.arange(0,256), color = 'b')
plt.axis([0,255,0,plt.axis()[3]])
plt.show()

# print(Rmean, Gmean, Bmean)
# ! green
if (Rmean > 100 and Rmean < 105 and Gmean > 170 and Gmean < 180 and Bmean > 115 and Bmean < 125):
    print("folder color is green")
# ! yellow
if (Rmean > 240 and Rmean < 255 and Gmean > 240 and Gmean < 255 and Bmean > 115 and Bmean < 125):
    print("folder color is yellow")
# ! purple
if (Rmean > 120 and Rmean < 130 and Gmean > 95 and Gmean < 105 and Bmean > 160 and Bmean < 170):
    print("folder color is purple")
# ! orange
if (Rmean > 245 and Rmean < 255 and Gmean > 135 and Gmean < 145 and Bmean > 85 and Bmean < 95):
    print("folder color is orange")
# ! blue
if (Rmean > 60 and Rmean < 70 and Gmean > 95 and Gmean < 105 and Bmean > 120 and Bmean < 130):
    print("folder color is blue")