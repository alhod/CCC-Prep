t = int(input(''))
for _ in range(t):
    n = int(input(''))
    v = []
    for i in range(n):
        tmp = input('')
        v.append(tmp)

    ans = []
    for i in range(n):
        ans.append(0)

    for i in range(n):
        found = False;
        for j in range(n):
            if found == True:
                break
            if v[i].startswith(v[j]):
                tmp = v[i][len(v[j]):]
                for x in range(n):
                    if(v[x]==tmp):
                        ans[i]=1
                        found = True
                        break
    for i in range(n):
        print(ans[i], end='')
    print()