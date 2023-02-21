tests = int(input(''))

problems = []

for i in range(0, tests):
    l = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    problems.append((l, arr))

for l, arr in problems:

    impossible = False

    # first check
    check_arr = []
    num_positives = 0
    num_negatives = 0
    for i in arr:
        if i < 0:
            check_arr.append(i*-1)
            num_negatives += 1
        else:
            check_arr.append(i)
            num_positives += 1


    begin_same = 0

    for i in range(0, l):

        if i == l-1 or check_arr[i] <= check_arr[i+1]:
            begin_same = i
            break


    begin_inc = 0

    for i in range(begin_same, l):

        if i == l-1 or check_arr[i] != check_arr[i+1]:
            begin_inc = i
            break


    for i in range(begin_inc, l):

        if i == l-1:
            break
        
        if check_arr[i] >= check_arr[i+1]:
            print('NO')
            impossible = True
            break

    if impossible != False:
        continue


    # check 2
    decreasing = begin_same
    same = begin_inc - begin_same+1
    increasing = l-begin_inc-1
    #num_of_same = begin_inc-begin_same
    # print('num_negatives:', num_negatives)
    # print('begin_same:', begin_same)
    # print('begin_inc:', begin_inc)
    # print('decreasing:', decreasing)
    # print('increasing:', increasing)

    if num_negatives in range(decreasing, decreasing+same+1):
        print('YES')
    else:
        print('NO')
    