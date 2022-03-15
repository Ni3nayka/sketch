import math





def to_angle(a, b):

    cs = math.cos(b)

    sn = math.sin(b)

    x = a[0]

    y = a[1]

    a[0] = x * cs - y * sn

    a[1] = x * sn + y * cs

    return a





def dist(a, b):

    x = a[0] - b[0]

    y = a[1] - b[1]

    return pow(x * x + y * y, 0.5)





def vec(a, b):

    return a[0] * b[1] - a[1] * b[0]





def psev(a, b):

    return a[0] * b[0] + a[1] * b[1]





def norm(a):

    r = pow(a[0] * a[0] + a[1] * a[1], 0.5)

    a[0] /= r

    a[1] /= r

    return a





def raz(a, b):

    c2 = [0, 0]

    c2[0] = a[0] - b[0]

    c2[1] = a[1] - b[1]

    return c2





def angle(a, b):

    ma = pow(a[0] * a[0] + a[1] * a[1], 0.5)

    mb = pow(b[0] * b[0] + b[1] * b[1], 0.5)

    sc = psev(a, b)

    ve = vec(a, b)

    res = math.acos(sc / ma / mb)

    if ve < 0:

        res *= -1

    return res





pi = 3.14159265358979323846

mn = [0, 0]

mx = [0, 0]

l1 = [0, 0]

c = [0, 0]

mn[0], mx[0], mn[1], mx[1] = map(float, input().split())

l1[0], l1[1] = map(float, input().split())

c[0], c[1] = map(float, input().split())

eps1 = 0.0000002

ep = 0.00001

eps2 = 0.01

now = mn[0]

d = math.sqrt(c[0] * c[0] + c[1] * c[1])

while now <= mx[0]:

    v = [0, 0]

    v[0] = l1[0]

    v[1] = 0

    v = to_angle(v, now)

#    print(now, abs(dist(v, c) - l1[1]))

    if abs(dist(v, c) - l1[1]) > d / 80:

        now += ep

        continue

    if abs(dist(v, c) - l1[1]) <= eps2:

        c1 = raz(c, v)

        c1 = norm(c1)

        v = norm(v)

        v[0], v[1] = -v[0], -v[1]

        ans = angle(v, c1)

        if ans < 0:

            ans += 2 * pi

        if mn[1] < ans < mx[1]:

            print(now, end=' ')

            print(ans)

            exit()

    now += eps1

print(-1)


