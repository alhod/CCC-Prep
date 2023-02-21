t = int(input(''))

problems = []

for i in range(t):
    n = int(input(''))
    arr1 = [int(i) for i in input('').split(' ')]
    arr2 = [int(i) for i in input('').split(' ')]
    problems.append((n, arr1, arr2))

for n, arr1, arr2 in problems:
    zip_arr = []
    for i in range(n):
        zip_arr.append([arr1[i], arr2[i], i])
    zip_sorted_arr = zip_arr.sort()

    impossible = False

    for i in range(n):
        if i == 0:
            continue
        if zip_sorted_arr[i][0] >= zip_sorted_arr[i-1][0] and zip_sorted_arr[i][1] >= zip_sorted_arr[i-1][1]:
            continue
        else:
            print(-1)
            impossible = True
            break
    
    if impossible == True:
        continue

    swap_arr = []
    zip_swap_arr = []
    for i in zip_arr:
        swap_arr.append(i[2])
    for i in zip_sorted_arr:
        zip_swap_arr.append(i[2])
    
    swaps = 0
    swap_steps = []

    for i in range(0, n):
        if swap_arr[i] == zip_swap_arr[i]:
            continue

        swap_arr[i], swap_arr[zip_swap_arr[i]] = swap_arr[zip_swap_arr[i]], swap_arr[i]
        swaps += 1
        swap_steps.append((i, zip_swap_arr[i]))

    print(swaps)
    for i, j in swap_steps:
        print(i+1, j+1)
