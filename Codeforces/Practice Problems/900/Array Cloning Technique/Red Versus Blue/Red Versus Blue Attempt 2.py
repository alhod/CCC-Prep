import math
def round(num):
    return math.ceil(num)
    # remainer = num-int(num)
    # if remainer == 0:
    #     return int(num)
    # if remainer >= 0.5:
    #     return int(num)+1
    # else:
    #     return int(num)


cases = int(input(''))

test = []

for i in range(0, cases):
    games, R, B = input('').split(' ')
    games = int(games)
    R = int(R)
    B = int(B)
    test.append((games, R, B))

for games, R, B in test:

    arr = []
    count = 0

    for i in range(0, B+1):
        arr.append([])
    
    R_count = R
    counter = 0

    while True:
        if R_count > 0:
            arr[counter].append('R')
            R_count -= 1
            counter += 1
            if counter > B:
                counter = 0
        else:
            break
    arr = [''.join(i) for i in arr]
    print('B'.join(arr))