num_tests = int(input(''))

tests = []

for i in range(0, num_tests):
    word = input('')
    tests.append((word[0], word[1]))

for first, second in tests:
    alpha1 = 'abcdefghijklmnopqrstuvwxyz'.split(first)
    alpha1 = first+''.join(alpha1)
    to_add = 'abcdefghijklmnopqrstuvwxyz'.index(first)*25
    to_add2 = alpha1.index(second)
    #print(to_add)
    #print(to_add2)
    print(to_add+to_add2)
    #print('----------------------------')
    