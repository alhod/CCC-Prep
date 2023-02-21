cases = int(input(''))

tests = []

for i in range(0, cases):
    l = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    tests.append((l, arr))

for l, arr in tests:

    first_pair = None
    second_pair = None

    i = 0
    j = 1

    #print('while loop 1')
    while True:
        #print('i:', i)
        #print('j:', j)
        if j == l:
            break
        elif arr[i] != arr[j]:
            i += 1
            j += 1
        else:
            first_pair = (i, j)
            break

    i = l-2
    j = l-1

    #print('while loop 2')
    while True:
        #print('i:', i)
        #print('j:', j)
        if i < 0:
            break
        elif arr[i] != arr[j]:
            i -= 1
            j -= 1
        else:
            second_pair = (i, j)
            break
    # print('first_pair:', first_pair)
    # print('second_pair:', second_pair)
    if first_pair == second_pair or first_pair == None or second_pair == None:
        print(0)
        continue

    else:
        if second_pair[0] - first_pair[0] == 1:
            print(1)
            continue
        print(second_pair[0]-first_pair[1])