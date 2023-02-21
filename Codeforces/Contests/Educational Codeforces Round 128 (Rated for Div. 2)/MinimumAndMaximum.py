t = int(input(''))
for i in range(t):
    l1, l2, r1, r2 = [int(i) for i in input('').split(' ')]
    if any(range(l1, l2)) in any(range(r1, r2)):
        print('hi')