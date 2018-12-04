import matplotlib as mpl
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.gca(projection='3d')

x = open('n+m.txt').read().splitlines()
x = [int(t) for t in x]
y = open('slide_time.txt').read().splitlines()
y = [int(t) for t in y]
z = open('tarjan_time.txt').read().splitlines()
z = [int(t) for t in z]

ax.plot(x, y, z, label='parametric curve')
ax.set_xlabel('n+m')
ax.set_ylabel('slide_time')
ax.set_zlabel('tarjan_time')
ax.legend()

plt.show()
