import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.gca(projection='3d')

x = open('n.txt').read().splitlines()
x = [int(t) for t in x]
y = open('m.txt').read().splitlines()
y = [int(t) for t in y]
z = open('time.txt').read().splitlines()
z = [int(t) for t in z]

ax.plot(x, y, z, label='parametric curve')
ax.set_xlabel('vertices')
ax.set_ylabel('edges')
ax.set_zlabel('time')
ax.legend()

plt.show()
