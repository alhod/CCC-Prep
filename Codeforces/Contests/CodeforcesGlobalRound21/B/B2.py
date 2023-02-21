t = int(input(''))
for _ in range(t):
    n = int(input(''))
    aList = [int(i) for i in input('').split(' ')]
    total = 0;
    onZeros = True
    for i in aList:
        if i==0:
            onZeros = True

        if i!=0:
            if onZeros == True:
                onZeros = False
                total+=1
    
    print(total)