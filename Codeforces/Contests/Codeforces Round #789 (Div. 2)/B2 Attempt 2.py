cases = int(input(''))

problems = []

for i in range(0, cases):
    l = int(input(''))
    arr = [int(i) for i in list(input(''))]
    
    problems.append((l, arr))


def iterate_right(ind, array):
    ind += 1
    while True:
        if ind >= len(array):
            return None
        if array[ind] != None:
            return array[ind]
        else:
            ind += 1

def iterate_left(ind, array):
    ind -= 1
    while True:
        if ind < 0:
            return None
        if array[ind] != None:
            return array[ind]
        else:
            ind -= 1


for l, arr in problems:
    operations = 0
    ind = 0

    array = []

    while ind+1<l:
        if arr[ind] == arr[ind+1]:
            array.append(arr[ind])
        else:
            array.append(None)
        ind+=2
    
    for ind in range(0, len(array)):
        if array[ind] != None:
            continue

        left_val = iterate_left(ind, array)
        right_val = iterate_right(ind, array)
        
        if left_val == right_val == None:
            array[ind] = 1

        elif left_val == right_val:
            array[ind] = left_val

        elif left_val == None and right_val != None:
            array[ind] = right_val

        elif left_val != None and right_val == None:
            array[ind] = left_val

        elif left_val != right_val:
            array[ind] = 1
        
        operations += 1

    ind = 1
    curr_val = array[0]
    segments = 0
    #print(array)
    while ind < len(array):
        if array[ind] != curr_val:
            segments += 1
            curr_val = array[ind]
        ind += 1
    segments += 1

    print(operations, segments)