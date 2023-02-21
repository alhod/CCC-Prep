n, q = [int(i) for i in input('').split(' ')]
v = []
v = [int(i) for i in input('').split(' ')]
v.sort()
for _ in range(q):
    x, y = [int(i) for i in input('').split(' ')]
    print(sum(v[n-x:n-x+y]))