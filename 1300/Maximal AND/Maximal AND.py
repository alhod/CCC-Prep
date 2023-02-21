cases = int(input(''))

tests = []

for i in range(0, cases):
    n, k = [int(i) for i in input('').split(' ')]
    arr = [int(i) for i in input('').split(' ')]
    tests.append((n, k, arr))

for n, k, arr in tests:

    # if we want we can first use a hashtable to map each index to the number of 0s

    # creating highest maximal AND

    ht = {}

    for i in range(0, 31):
        ht[i] = 0

    for exp in range(30, -1, -1):
        for byte in arr:
            if byte&(2**exp) != 2**exp:
                ht[exp] += 1
    
    for exp in range(30, -1, -1):
        if ht[exp] > 0 and k - ht[exp] >= 0:
            for ind_of_byte in range(0, n):
                arr[ind_of_byte] = arr[ind_of_byte]|(2**exp)
            k -= ht[exp]
        if k == 0:
            break

    # print(arr)

    final = arr[0]

    for ind_of_byte in range(1, n):
        final = final&arr[ind_of_byte]

    print(final)

