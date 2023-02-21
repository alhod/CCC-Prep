cases = int(input(''))

problems = []

for test in range(0, cases):
    n, k = input('').split(' ')
    n = int(n)
    k = int(k)
    nums = list(input(''))
    problems.append((n, k, nums))

for n, k, nums in problems:
    flipped = []

    for i in range(0, n):
        flipped.append(0)

    if k % 2 != 0:  # k is odd
        for i in range(0, n):
            if k == 0:
                break
            if nums[i] == '1':
                k -= 1
                nums[i] = '0'
                flipped[i] += 1
        for i in range(0, n):
            if nums[i] == '0':
                nums[i] = '1'
            elif nums[i] == '1':
                nums[i] = '0'

    elif k % 2 == 0:  # k is even
        for i in range(0, n):
            if k == 0:
                break
            if nums[i] == '0':
                nums[i] = '1'
                k -= 1
                flipped[i] += 1

    if k > 0:
        if k % 2 != 0:
            if nums[-1] == '0':
                nums[-1] = '1'
            else:
                nums[-1] = '0'
        flipped[-1] += k
    print(''.join(nums))
    print(' '.join([str(i) for i in flipped]))


    