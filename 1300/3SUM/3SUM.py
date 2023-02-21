t = int(input(''))
for _ in range(t):
    n = int(input(''))
    numbers = [int(i[-1]) for i in input('').split(' ')]
    number3 = [3, 13, 23]
    arr1 = []
    arr2 = []
    countNums = {}
    foundSolution = False


    for num in numbers:
        if num in countNums and countNums[num] == 3:
            continue
        elif num not in countNums:
            countNums[num] = 1
        else:
            countNums[num]+=1

        if num in arr2:
            foundSolution = True
            break
        
        for i in arr1:
            if i-num>=0 and i-num not in arr2:
                arr2.append(i-num)

        for a3num in number3:
            if a3num-num>=0 and a3num-num not in arr1:
                arr1.append(a3num-num)

    if foundSolution == True:
        print('YES')
    else:
        print('NO')

