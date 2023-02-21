tests = int(input(''))

problems = []

for i in range(0, tests):
    l = int(input(''))
    logs = [int(i)-1 for i in input('').split(' ')]
    problems.append((l, logs))

for l, logs in problems:
    if sum(logs) % 2 == 0:
        print('maomao90')
    else:
        print('errorgorn')