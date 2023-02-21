def main():
    num = int(input(''))
    coms = []
    temp = []
    if num == 0:
        return
    for i in range(0, num):
        tmp = list(input('').split(' '))
        temp.append(tmp)

    #print('temp:', temp)

    for tmp in temp:
        value = (2 * int(tmp[1])) + (3 * int(tmp[2])) + int(tmp[3])
        #print(f'{tmp[0]} has value {value}')
        coms.append((value, str(tmp[0])))


    coms.sort(reverse=True)


    if len(coms) > 1 and coms[0][0] == coms[1][0]:
        coms = [coms[0], coms[1]]
        coms.sort()


    if len(coms) > 1:
        print(coms[0][1])
        print(coms[1][1])
    else:
        print(coms[0][1])

main()