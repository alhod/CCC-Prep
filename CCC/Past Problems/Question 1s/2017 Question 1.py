


N = int(input(''))
swift = [int(i) for i in list(input('').split(' '))]
sema = [int(i) for i in list(input('').split(' '))]
got = False
swi = sum(swift)
sem = sum(sema)
for i in range(0, N):
    if swi == sem:
        print(N-i)
        got = True
        break
    swi = swi - swift[N-1-i]
    sem = sem - sema[N-1-i]
    

if got == False:
    print(0)
