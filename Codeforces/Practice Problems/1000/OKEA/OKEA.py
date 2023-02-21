from ssl import ALERT_DESCRIPTION_DECODE_ERROR


cases = int(input(''))

tests = []

for i in range(0, cases):
    n, k = input('').split(' ')
    n = int(n)
    k = int(k)
    tests.append((n, k))

for n, k in tests:

    if k == 1:
        print('YES')
        for i in range(1, n+1):
            print(i)
        continue

    if n % 2 != 0:
        print('NO')
        continue

    arr = []
    arr_odd = []
    arr_even = []

    for i in range(1, n*k, 2):
        arr_odd.append(str(i))
    
    for j in range(2, n*k+1, 2):
        arr_even.append(str(j))
        
    full_arr = arr_odd + arr_even
    #print(full_arr)
    while bool(full_arr) == True:
        to_append = full_arr[:k]
        full_arr = full_arr[k:]
        arr.append(to_append)

    print('YES')
    for i in arr:
        print(' '.join(i))