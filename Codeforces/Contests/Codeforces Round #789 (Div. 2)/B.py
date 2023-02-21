from locale import currency


cases = int(input(''))

problems = []

for i in range(0, cases):
    l = int(input(''))
    arr = [int(i) for i in list(input(''))]

    new_arr = []

    curr_count = 1
    ind = 1
    curr_val = arr[0]

    while ind < l:
        if arr[ind] == curr_val:
            curr_count += 1
        else:
            new_arr.append(curr_count)
            curr_val = arr[ind]
            curr_count = 1
        ind += 1

    new_arr.append(curr_count)
    
    problems.append((l, new_arr))

for l, arr in problems:
    operations = 0
    for i in range(0, len(arr)):
        if arr[i]%2 != 0:
            arr[i] -= 1
            arr[i+1] += 1
            operations += 1

    print(operations)