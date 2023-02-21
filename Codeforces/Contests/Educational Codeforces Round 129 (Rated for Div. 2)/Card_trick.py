t = int(input(''))
for _ in range(t):
    n = int(input(''))
    cards = [int(i) for i in input('').split(' ')]
    m = int(input(''))
    shuffles = sum([int(i) for i in input('').split(' ')])
    print(cards[shuffles%n])