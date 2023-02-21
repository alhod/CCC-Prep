cases = int(input(''))
to_solve = []
for case in range(0, cases):
    ori, new = input('').split(' ')
    to_solve.append((ori, new))

for ori, new in to_solve:
    ori_copy = list(ori)
    new_copy = list(new)

    for letter in new_copy:
        try:
            ori_copy.remove(letter)
        except:
            pass
    list_to_remove = list(ori_copy)
    #print(list_to_remove)
    
    new_ori = list(ori)
    #print(new_ori)

    for letter in list_to_remove:
        try:
            new_ori.remove(letter)
        except:
            pass
    #print('new_ori', new_ori)
    if ''.join(new_ori) == new:
        print('YES')
    else:
        print('NO')
