import cv2
import numpy as np
import matplotlib.pyplot as pl
from sklearn.cluster import KMeans

vid = cv2.VideoCapture('wiffleBalls.mov') # import video
fps = 30 # delcare frame per sec
re, im = vid.read() # 're' is the return value: checks if import was successful, 'im' is the image
numFrames = 0
PixMoved = np.array(0)
RGB_threshold = 150 # RGB red value threshold to identify balls, green to idenify ruler
# if re == True:
#     print('bruh')
while re: # while an image is returned = true
    RGB = cv2.cvtColor(im, cv2.COLOR_BGR2RGB)
    bi = 255*np.uint8(np.logical_and(RGB[:,:,0] > RGB_threshold, RGB[:,:,1] < RGB_threshold)) # returns (0 or 1) * 255
    bi = cv2.medianBlur(bi, 25) # puts blur on image to reduce promenence of holes in wiffleballs
    [x,y] = np.meshgrid(np.arange(im.shape[1]), np.arange(im.shape[0])) # makes x and y
    data = np.column_stack((x[bi > 100], y[bi > 100])) # ? why this?
    k = KMeans(n_clusters=4).fit(data) # performs KMeans on blurred image for clusters
    centers = k.cluster_centers_ # built in KMeans function
    pl.figure()
    pl.clf()
    pl.imshow(RGB)
    pl.plot(data[:,0], data[:,1], '.')
    pl.plot(centers[:,0], centers[:,1], '*m')
    pl.pause(.01)
    if numFrames == 0: # only first loop
        lastCenter = centers # no previous value
        click1, click2 = np.array(pl.ginput(2)) # user click image
        pixPerFt = np.sqrt( (click1[0] - click2[0])**2 + (click1[1] - click2[1])**2 ) # calc pix per ft by clicking on the ruler: just pythagorean 
    pl.figure(3)
    pl.clf()
    pl.imshow(bi)
    pl.pause(0.01)
    disMat = np.zeros((4,4)) # Matrix to hold distances, from center to last center
    for i in range(4):
        for j in range(4):
            disMat[i,j] = np.sqrt( (centers[j,0] - lastCenter[i,0])**2 + (centers[j,1] - lastCenter[i,1])**2)
    PixMoved = np.hstack((PixMoved, np.max(np.amin(disMat,0)))) # calc distance from last center to new (in pixels)
    lastCenter = centers # updates last centers to current
    re, im = vid.read()
    numFrames += 1
ftMoved = PixMoved / pixPerFt # convert pixels moved to ft moved
t = np.arange(numFrames + 1) / fps # vector of times
h_t = 1/fps # time step
v_t = ftMoved / h_t # calc speed
pl.figure(2)
pl.clf()
pl.plot(t, v_t, '-*')
pl.xlabel('time (s)')
pl.ylabel('Velocity (ft/s)')
pl.show()
vid.release()