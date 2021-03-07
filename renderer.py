import sys
from matplotlib import pyplot as plt

height, width = 0, 0  # int(sys.stdin[0]), int(sys.stdin[1])
list_x = []
list_y = []

inp = ""

for s in sys.stdin:
    x, y = s.split()
    list_x.append(int(x))
    list_y.append(int(y))

plt.scatter(list_x, list_y)
plt.show()
