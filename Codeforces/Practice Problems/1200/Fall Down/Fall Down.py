cases = int(input(''))

tests = []

for i in range(0, cases):
    n, m = input('').split(' ')
    n = int(n)
    m = int(m)

    arr = []

    for j in range(0, n):
        arr.append(list(input('')))

    tests.append((n, m, arr))

for n, m, arr in tests:
    
    for col in range(0, m):  # iterate through columns
        next_obs = n-1
        for row in range(0, n):
            row = n-1-row
            if arr[row][col] == 'o':
                next_obs = row-1
            elif arr[row][col] == '*':
                arr[row][col] = '.'
                arr[next_obs][col] = '*'
                next_obs -= 1
            else:
                pass
    
    for a_row in range(0, n):
        arr[a_row] = ''.join(arr[a_row])
    #print(arr)

    print('\n'.join(arr))
    