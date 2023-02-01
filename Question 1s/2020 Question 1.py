com = list(input(''))
arr = [['1', '2'],['3', '4']]
for command in com:
    if command == 'H':
        arr[1], arr[0] = arr[0], arr[1]
    else:
        arr[0][0], arr[0][1], arr[1][0], arr[1][1] = arr[0][1], arr[0][0], arr[1][1], arr[1][0]


print(' '.join(arr[0]))
print(' '.join(arr[1]))