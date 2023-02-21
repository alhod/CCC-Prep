tests = int(input(''))

problems = []

for i in range(0, tests):
    l = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    problems.append((l, arr))

for l, arr in problems:
    
    impossible = False

    negative_count = 0

    new_arr = []

    for i in arr:
        if i < 0:
            negative_count += 1
            new_arr.append(i*-1)
        else:
            new_arr.append(i)

    counter = 0

    while negative_count > 0:
        new_arr[counter] = new_arr[counter]*-1
        counter += 1
        negative_count -= 1

    ind = 0

    while ind < l-1:
        if new_arr[ind] <= new_arr[ind+1]:
            ind += 1
        else:
            impossible = True
            print('NO')
            break

    if impossible == False:
        print('YES')
