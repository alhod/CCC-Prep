tests = int(input(''))

problems = []

for i in range(0, tests):
    l = int(input(''))
    arr = [int(i) for i in input('').split(' ')]
    problems.append((l, arr))

for l, arr in problems:
    counter = l-1
    operations = 0
    no_solution = False
    while counter >= 0:
        if counter == l-1 or arr[counter] < arr[counter+1]:
            counter -= 1
            continue
        if arr[counter] == 0:
            print('-1')
            no_solution = True
            break
        if arr[counter] >= arr[counter+1]:
            arr[counter] = int(arr[counter]/2)
            operations += 1
    if no_solution == False:
        print(operations)
