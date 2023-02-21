t = int(input(''))
for _ in range(t):

    n = int(input(''))
    aList = [int(i) for i in input('').split(' ')]
    aList = list(set(aList))
    numZeros = aList.count(0)

    if aList[0] == 0:
        numZeros-=1
    if aList[-1] == 0:
        numZeros-=1
    numZeros+=1
    print(numZeros)