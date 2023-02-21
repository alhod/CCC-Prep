cases = int(input(''))

problems = []

for i in range(0, cases):
    n = int(input(''))
    
    arr = [int(i) for i in input('').split(' ')]

    repeated = False
    num_0s = 0
    repeated_arr = []

    for i in arr:

        if repeated == False and i in repeated_arr:
            repeated = True
        else:
            repeated_arr.append(i)
        if i == 0:
            num_0s += 1
        
    problems.append((n, arr, repeated, num_0s))


for n, arr, repeated, num_0s in problems:
    if num_0s > 0:
        n = n - num_0s
        print(n)
        continue
    elif repeated == True:
        print(n)
        continue
    else:
        print(n+1)
        continue
