import numpy as np
import os
import matplotlib.pyplot as plt

xmin = -1.5
xmax = .5
ymin = -1.2
ymax = 1.2
domain = [xmin, xmax, ymin, ymax]

while True:
    np.savetxt('domain.txt', domain)
    os.system("mandlebrot.exe")
    n = np.log(np.log((np.loadtxt('nFile.txt'))+1))
    dR = domain[1] - domain[0]
    dI = domain[3] - domain[2]
    plt.figure(1)
    plt.clf()
    plt.imshow(n)
    plt.gca().set_aspect(dI/dR)
    plt.pause(.001)
    p = plt.ginput(2)
    p = np.array(p)
    domain = [min(p[:,0]*dR/(n.shape[1] - 1) + domain[0]),
              max(p[:,0]*dR/(n.shape[1] - 1) + domain[0]),
              min(p[:,1]*dI/(n.shape[0] - 1) + domain[2]),
              max(p[:,1]*dI/(n.shape[0] - 1) + domain[2])]