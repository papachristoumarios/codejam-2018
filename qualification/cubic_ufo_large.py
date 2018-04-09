import math as m
# from matplotlib import pyplot as plt
# import numpy as np


def rotate(p, theta, phi):
    x, y, z = p
    x_ = m.cos(phi) * m.cos(theta) * x - m.sin(theta) * y + m.cos(theta) * m.sin(phi) * z
    y_ = m.cos(phi) * m.sin(theta) * x + m.cos(theta) * y + m.sin(theta) * m.sin(phi) * z
    z_ = -m.sin(phi) * x + m.cos(phi) * z
    return x_, y_, z_

def surface(theta, phi):
    Vrot = {}
    for i in range(1, 9):
        Vrot[i] = rotate(V[i], theta, phi)
    result = 0
    result += parallelogram(Vrot[1], Vrot[2], Vrot[3])
    result += parallelogram(Vrot[1], Vrot[5], Vrot[2])
    result += parallelogram(Vrot[1], Vrot[5], Vrot[3])
    return result

def parallelogram(a, b, c):
    x1, y1, z1 = a
    x2, y2, z2 = b
    x3, y3, z3 = c
    px = x2 - x1
    pz = z2 - z1
    qx = x3 - x1
    qz = z3 - z1
    return abs (px * qz - pz * qx)


V = {} # vertices
i = 1
for y in [-0.5, 0.5]:
    for z in [-0.5, 0.5]:
        for x in [-0.5, 0.5]:
            V[i] = (x,y,z)
            i += 1

# plt.figure();
# x = np.arange(0, m.pi /4, m.pi / 100)
# y = [surface(m.pi / 4, t) for t in x]
# plt.plot(x, y)
#
# print surface(m.pi / 4, 0)

T = int(raw_input())
for t in range(1, T + 1):
    print "Case #{}:".format(t)
    A = float(raw_input())
    F = [(0.5, 0, 0), (0, 0.5, 0), (0, 0, 0.5)]

    # print surface(m.pi / 4, m.pi / 2)

    if 1.000000 <= A <= 1.414213:
        theta = round( m.asin ( A  / m.sqrt(2) ) - m.pi / 4, 7)
        phi = 0
    else:
        theta = m.pi / 4
        lo, hi = 0, m.pi / 4
        while (lo <= hi):
            mid = 0.5 * (lo + hi)
            S = surface(theta, mid)
            DS = S - A
            if abs(DS) <= 1e-9 or abs (hi - lo) / 2 < 1e-9: break
            elif DS > 0: hi = mid
            else: lo = mid
        phi = mid


    for x, y, z in F:
        xx, yy, zz = rotate((x,y,z), theta, phi)
        print xx, yy, zz

# plt.show();
