import sys
from matplotlib import pyplot as plt

height, width = 0, 0  # int(sys.stdin[0]), int(sys.stdin[1])
list_x = []
list_y = []
init_x, init_y = 0, 0

for i, s in enumerate(sys.stdin):
    x, y = map(int, s.split())
    if i == 0:
        init_x, init_y = x, y
        continue
    list_x.append(x)
    list_y.append(y)

plt.scatter(list_x, list_y, color="blue", marker=".")
plt.scatter(init_x, init_y, color="red")
plt.show()
