import math
from collections import Counter

def find_highest_value(arr):
    temp = Counter(arr)
    return (temp[temp.most_common(1)[0][0]])

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

    L = lengths[i]
    remaining_length = lengths[i]-H

    num_clones = math.ceil(math.log(L/H, 2))

    if remaining_length == 0:
        print(0)
    else:
        print(int(num_clones) + remaining_length)