import sys
from matplotlib import pyplot as plt

height, width = 0, 0  # int(sys.stdin[0]), int(sys.stdin[1])
list_x = []
list_y = []

inp = ""

for s in sys.stdin:
    inp += s


i = 0
inp = inp.split()
for s in inp:
    if i == 0:
        height = int(s)
    elif i == 1:
        width = int(s)
    elif int(s):
        list_y.append((i - 2) // width)
        list_x.append((i - 2) % width)
    i += 1

plt.scatter(list_x, list_y)
plt.show()
