def round(num):
    remainer = num-int(num)
    if remainer == 0:
        return int(num)
    if remainer >= 0.5:
        return int(num)+1
    else:
        return int(num)


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
    for i in range(0, R):
        arr.append('R')
    
    inc = round(R/(B+1))
    print('inc:', inc)
    
    to_insert = []

    counter = 0

    num_b = B

    i = 0

    while True:
        if num_b == 0:
            break
        if counter == inc:
            to_insert.append(i)
            num_b -= 1
            counter = 0
            counter += 1
        else:
            counter += 1
        i += 1
    to_insert.sort(reverse=True)
    for i in to_insert:
        arr.insert(i, 'B')

    print(''.join(arr))