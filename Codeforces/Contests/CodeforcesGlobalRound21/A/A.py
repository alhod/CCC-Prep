t = int(input(''))
for _ in range(t):
    n, z = [int(i) for i in input('').split(' ')]
    aList = [int(i) for i in input('').split(' ')]

    print(max(aList)|z)