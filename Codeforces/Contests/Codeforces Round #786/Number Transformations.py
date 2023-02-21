tests = int(input(''))

test = []

for i in range(0, tests):
    x, y = [int(i) for i in input('').split(' ')]
    test.append((x, y))

for x, y in test:
    if y / x == int(y/x):
        print('1',int(y/x))
    else:
        print('0 0')