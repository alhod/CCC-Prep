test_cases = int(input(''))

cases = []

for i in range(0, test_cases):
    num = int(input(''))
    candies = [int(i) for i in input('').split(' ')]
    cases.append((num, candies))

for num, candies in cases:
    p1 = 1
    p2 = num-1
    highest_num_candies = 0
    while True:
        if p2-p1 < 0:
            print(highest_num_candies)
            break
        elif sum(candies[:p1]) == sum(candies[p2:]):
            highest_num_candies = len(candies[:p1])+len(candies[p2:])
            p1 += 1
        elif sum(candies[:p1]) > sum(candies[p2:]):
            p2 -= 1
        elif sum(candies[:p1]) < sum(candies[p2:]):
            p1 += 1