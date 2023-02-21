

def find_highest_value(arr):
    dict = {}
    for i in arr:
        if i not in dict:
            dict[i] = 1
        else:
            dict[i] += 1

    dict = [dict[i] for i in dict]
    return max(dict)

cases = int(input(''))

lengths = []
problems = []

for i in range(0, cases):
    length = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    lengths.append(length)
    problems.append(arr)

for i in range(0, cases):
    
    arr = problems[i]


    H = find_highest_value(arr)

    L = lengths[i] - H

    operations = 0

    if L == 0:
        print(0)
    else:
        while True:

            operations += 1  # create clone

            if H >= L:  # we finish this iteration
                operations += L
                print(operations)
                break
            
            elif H < L:  # we don't finish this iteration
                L = L - H
                operations += H
                H = H*2

        



    
