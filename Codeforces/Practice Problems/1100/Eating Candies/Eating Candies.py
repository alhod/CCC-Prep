


test_cases = int(input(''))

cases = []

for i in range(0, test_cases):
    num = int(input(''))
    candies = [int(i) for i in input('').split(' ')]
    cases.append((num, candies))

for num, candies in cases:
    starting_point = int(num/2)-1
    p1 = starting_point
    p2 = starting_point + 1
    prev_weights = []
    while True:
        w_p1 = sum(candies[:p1])
        w_p2 = sum(candies[p2:])
        # print('p1:', p1)
        # print('p2:', p2)
        # print('w_p1:', w_p1)
        # print('w_p2:', w_p2)
        # print('candies[:p1] -->', candies[:p1])
        # print('candies[p2:] -->', candies[p2:])
        if (w_p1, w_p2) in prev_weights:
            print(0)
            break
        else:
            prev_weights.append((w_p1, w_p2))
        if w_p1 == w_p2:
            # print(w_p1)
            # print(w_p2)
            print(len(candies[:p1])+len(candies[p2:]))
            break
        elif w_p1 > w_p2:
            if p1 - 1 > 0:
                p1 -= 1
                while sum(candies[p2-1:]) <= sum(candies[p1:]) and p2 > p1:
                    p2 -= 1
                    if sum(candies[p2:]) == sum(candies[p1:]):
                        #print(len(candies[:p1])+len(candies[p2:]))
                        break
            else:
                print(0)
                break
        elif w_p1 < w_p2:
            if p2 + 1 <= num-1:
                p2 += 1
                while sum(candies[:p1+1]) <= sum(candies[p2:]) and p2 > p1:
                    p1 += 1
                    if sum(candies[p1:]) == sum(candies[p2:]):
                        #print(len(candies[:p1])+len(candies[p2:]))
                        print('moving ')
                        break
            else:
                print(0)
                break
                


# two pointers. Start by moving the right one one left. If left < right, move left pointer one right. If right < left, move right pointer one left. If both ranges equal, write that down.