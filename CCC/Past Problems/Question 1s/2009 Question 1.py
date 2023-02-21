range_start = int(input(''))
range_end = int(input('')) + 1
num = 0
for i in range(range_start, range_end):
    print(i)
    if i ** (1/2) == int(i ** (1/2)):
        print(f'{i} is a square')
        if i ** (1/3) == int(i ** (1/3)):
            print(f'{i} is also a cube')
            num += 1

print(num)