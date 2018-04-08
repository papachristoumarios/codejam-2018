import math as m

def rotate(x, y, z, theta):
    x_ = m.cos(theta) * x - m.sin(theta) * y
    y_ = m.sin(theta) * x + m.cos(theta) * y
    z_ = z
    print x_, y_, z_
    return x_, y_, z_

T = int(raw_input())
for t in range(1, T + 1):
    print "Case #{}:".format(t)
    A = float(raw_input())
    theta = round( m.asin ( A  / m.sqrt(2) ) - m.pi / 4, 7)
    F = [(0.5, 0, 0), (0, 0.5, 0), (0, 0, 0.5)]
    for x, y, z in F:
        rotate(x, y, z, theta)
