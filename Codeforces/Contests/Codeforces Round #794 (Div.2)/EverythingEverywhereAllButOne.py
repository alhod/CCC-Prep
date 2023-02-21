t = int(input(''))
for _ in range(t):
    n = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    solved = False
    for i in range(n):
        component = (n-1)*arr[i]
        if component == sum(arr[:i]) + sum(arr[i+1:]):
            print('YES')
            solved = True
            break
    if solved == False:
        print('NO')