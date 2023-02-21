from operator import truediv


t = int(input(''))
for _ in range(t):
    n, m = [int(i) for i in input('').split(' ')]
    arr = []
    for i in range(n):
        arr.append([int(i) for i in input('').split(' ')])

    
    sorted_arr = []
    for i in range(n):
        tmp = arr[i].copy()
        tmp.sort()
        sorted_arr.append(tmp)

    impossible = False

    i = 0
    j = 0
    wrong = 0
    marki = -1
    markj = -1
    hasSwapped = False
    to_continue = False
    # print(arr)
    # print(sorted_arr)
    while i < n:
        # print('i:', i)
        # print(arr)
        # print(sorted_arr)
        if impossible == True:
            break
        for j in range(0, m):
            if arr[i][j] != sorted_arr[i][j]:
                wrong+=1
                # print(wrong)
                if marki == -1:
                    marki = j
                elif markj == -1:
                    markj = j
            if wrong == 2 and hasSwapped == False:
                for x in range(0, n):
                    arr[x][marki], arr[x][markj] = arr[x][markj], arr[x][marki]
                hasSwapped = True
                # print('swapped')
                i = 0
                to_continue = True
                break
            if wrong == 3:
                print('-1')
                impossible = True
                break
        if to_continue == True:
            to_continue = False
            continue
        i+=1
    
    if impossible == True:
        continue
    
    if marki == markj == -1:
        print('1 1')
    else:
        print(marki+1, markj+1)