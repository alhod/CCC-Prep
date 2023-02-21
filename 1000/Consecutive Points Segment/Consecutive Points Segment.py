test_cases = int(input(''))

cases = []

for i in range(0, test_cases):
    num = int(input(''))
    points = [int(i) for i in input('').split(' ')]
    cases.append((num, points))

for num, points in cases:
    holes = 0
    arr = [i for i in range(points[0], points[0]+num+1)]
    
    for i in range(0, num):
        if points[i] - arr[i] > holes:
            holes = points[i] - arr[i]
        if holes > 2:
            print('NO')
            break
    
    if holes <= 2:
        print('YES')