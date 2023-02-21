def solve(a, b, c, d):
    for bet_geese in range(1, 101):
        for bet_kang in range(1, 101):
            if bet_geese * (b/a) > bet_geese + bet_kang and bet_kang * (d/c) > bet_geese + bet_kang:
                return True
    else:
        return False


test_cases = int(input(''))
tests = []
for test in range(0, test_cases):
    case = [int(i) for i in input('').split(' ')]
    tests.append(case)

for test in tests:
    if solve(test[0], test[1], test[2], test[3]) == True:
        print('YES')
    else:
        print('NO')
    