import matplotlib as mpl
import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

g = nx.Graph()

lines = open('in.txt').read().splitlines()
for line in lines:
    g.add_edge(line.split()[0], line.split()[1])

colors = open('color.txt').read().splitlines()

nx.draw(g, nodelist=g.nodes(), node_color=colors, with_labels=True)

plt.show()
