cases = int(input(''))

tests = []

for i in range(0, cases):
    l = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    tests.append((l, arr))

for l, arr1 in tests:
    arr = arr1.copy()
    arr1.sort()
    sorted_arr = arr1
    no_solution = False
    ind = 0
    if l%2 != 0:
        if arr[0] == min(arr):
            arr = arr[1:]
            sorted_arr = sorted_arr[1:]
        else:
            no_solution = True
            print('NO')
            continue
        while ind < l:
            if no_solution == True:
                break
            for i in arr[ind:ind+2]:
                if i in sorted_arr[ind:ind+2]:
                    pass
                else:
                    print('NO')
                    no_solution = True
                    break
            ind += 2
        if no_solution == True:
            continue
        else:
            print('YES')
    elif l%2 == 0:
        while ind < l:
            if no_solution == True:
                break
            for i in arr[ind:ind+2]:
                if i in sorted_arr[ind:ind+2]:
                    pass
                else:
                    print('NO')
                    no_solution = True
                    break
            ind += 2
        if no_solution == True:
            continue
        else:
            print('YES')
