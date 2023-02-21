t = int(input(''))
for _ in range(t):
    n = int(input(''))
    num = int(input(''))
    total = 0

    if 10**n-num<=10**(n-1):
        s = ""
        for i in range(n):
            s = s+"1"
        s = int(s)
        print(10**n-num+s)
    else:
        s = ""
        for i in range(n):
            s = s+"9"
        s = int(s)
        print(s-num)