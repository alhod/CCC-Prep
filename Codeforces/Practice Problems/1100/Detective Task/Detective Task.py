cases = int(input(''))

problems = []

for i in range(0, cases):
    arr = list(input(''))
    problems.append(arr)


for arr in problems:
    if '1' in arr and '0' in arr:
        # case 1
        ind_0 = arr.index('0')
        arr.reverse()
        ind_1 = len(arr)-1-arr.index('1')
        print(ind_0-ind_1+1)
    elif '1' in arr:
        # case 2
        arr.reverse()
        ind_1 = arr.index('1')
        print(len(arr[:ind_1+1]))
    elif '0' in arr:
        # case 3
        ind_0 = arr.index('0')
        print(len(arr[:ind_0+1]))
    else:
        # case 4
        print(len(arr))