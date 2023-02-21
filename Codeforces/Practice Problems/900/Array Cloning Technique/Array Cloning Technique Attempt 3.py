import math
from collections import Counter

def find_highest_value(arr):
    temp = Counter(arr)
    return temp[temp.most_common(1)[0][0]], temp.most_common(1)[0][0]

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


    H, H_val = find_highest_value(arr)

    new_arr = []
    for j in range(0, H):
        new_arr.append(H_val)

    L = lengths[i]
    
    operations = 0

    while True:
        #print('---- BEGIN ITERATION ----')
        #print('operations -->', operations)
        #print('new_arr -->', new_arr)
        #print('H -->', H)
        if len(new_arr) == L:
            print(operations)
            break
        else:
            operations += 1
            #print(f'Made copy, operations --> {operations}')
            if H*2 < L:
                #print(f'H*2 ({H*2}) < L ---- sequence 1')
                for i in range(0, H):
                    new_arr.append(H_val)
                    #print(f'Appending {H_val} to new_arr ({new_arr})')
                    operations += 1
                H = H * 2
                #print(f'H is now {H}')
                #print('Total operatioons -->', operations)
            elif H*2 >= L:
                #print(f'H*2 ({H*2}) >= L ---- sequence 2')
                while True:
                    if len(new_arr) != L:
                        #print(f'Appending {H_val} to new_arr ({new_arr})')
                        new_arr.append(H_val)
                        operations += 1
                    else:
                        print(operations)
                        break
                break
            

            
