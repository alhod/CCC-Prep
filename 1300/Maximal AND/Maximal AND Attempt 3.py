cases = int(input(''))

tests = []

for i in range(0, cases):
    n, k = [int(i) for i in input('').split(' ')]
    arr = [int(i) for i in input('').split(' ')]
    tests.append((n, k, arr))

for n, k, arr in tests:

    # if we want we can first use a hashtable to map each index to the number of 0s

    # creating highest maximal AND

    counter = 30

    while True:
        num_of_0s = 0
        for byte in arr:
            if byte&(2**counter) < (2**counter):
                num_of_0s += 1
        if k >= num_of_0s and num_of_0s != 0:
            for ind_of_byte in range(0, n):
                if arr[ind_of_byte]&(2**counter) < (2**counter):
                    arr[ind_of_byte] = arr[ind_of_byte]|(2**counter)
            k -= num_of_0s
        if k == 0 or counter == 0:
            break
        counter -= 1

    #print(arr)

    final = arr[0]

    for ind_of_byte in range(1, n):
        final = final&arr[ind_of_byte]

    print(final)

