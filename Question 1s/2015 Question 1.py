num = int(input(''))
com = []
for i in range(0, num):
    val = int(input(''))
    if val == 0:
        com = com[:-1]
    else:
        com.append(val)

print(sum(com))
