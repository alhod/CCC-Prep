t = int(input(''))

for _ in range(t):
    n = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    solved = []

    if n%2!=0:
        print('NO')

    curr = min(arr)
    arr.remove(curr)
    solved.append(curr)
    ind = 0
    impossible = False
    while ind < n:
        if ind % 2 ==0:
            max_val = max(arr)
            arr.remove(max_val)
            if max_val <= curr:
                impossible = True
                break
            curr = max_val
            ind += 1
        elif ind % 2 != 0:
            min_val = min(arr)
            arr.remove(min_val)
            if min_val >= curr:
                impossible = True
                break
            curr = min_val
            ind+=1