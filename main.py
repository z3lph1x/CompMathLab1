import numpy as np
import matplotlib.pyplot as plt

with open("E:\CompMathLab1Python\LA06.txt", 'r') as file:
    lst = file.readlines()
lst = [[float(n) for n in x.split()] for x in lst]
print(lst)
jopa = [i for i in range(41)]
for i in range(37):
    s = '0_6__' + str(i) + '.png'
    for j in range(41):
        jopa[j] = lst[i][j]
    t = np.arange(0, 20.5, 0.5)
    plt.axis([0, 20, -1, 1])
    plt.title('Co = 1, LeftAngle')
    plt.plot(t, jopa, 'ro')
    plt.savefig(s)
    plt.clf()
