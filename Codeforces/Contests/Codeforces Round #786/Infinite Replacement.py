num_tests = int(input(''))

problems = []

for i in range(0, num_tests):
    s = input('')
    t = input('')

    problems.append((s, t))

for s, t in problems:
    if 'a' in t and len(t) > 1:
        print(-1)
        continue
    elif t == 'a':
        print('1')
        continue
    else:
        print(2**len(s))

# 0 1
# 00 01 10 11
# 000 001 010 011 100 101 110 111
# 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111