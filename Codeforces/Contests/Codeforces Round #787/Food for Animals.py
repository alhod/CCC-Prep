cases = int(input(''))

problems = []

for i in range(0, cases):
    a, b, c, x, y = [int(i) for i in input('').split(' ')]
    problems.append((a,b,c,x,y))


for a, b, c, x, y in problems:
    remaining_dog = x - a
    if remaining_dog < 0:
        remaining_dog = 0
    remaining_cat = y - b
    if remaining_cat < 0:
        remaining_cat = 0
    total_remaining = c - remaining_dog - remaining_cat
    if total_remaining >= 0:
        print('YES')
    else:
        print('NO')