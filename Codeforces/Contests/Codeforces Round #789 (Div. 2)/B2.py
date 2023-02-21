from locale import currency


cases = int(input(''))

problems = []

for i in range(0, cases):
    l = int(input(''))
    arr = [int(i) for i in list(input(''))]

    new_arr = []

    curr_count = 1
    ind = 1
    curr_val = arr[0]

    while ind < l:
        if arr[ind] == curr_val:
            curr_count += 1
        else:
            new_arr.append(curr_count)
            curr_val = arr[ind]
            curr_count = 1
        ind += 1

    new_arr.append(curr_count)
    
    problems.append((l, new_arr))

for l, arr in problems:
    operations = 0
    ind = 0
    while ind < len(arr):
        # print('arr -->', arr)
        # print('ind -->', ind)
        if arr[ind]%2!=0:
            if arr[ind] >= arr[ind+1]:
                arr[ind] += 1
                arr[ind+1] -= 1
                operations += 1
                if arr[ind+1] == 0:
                    if ind+1 == len(arr)-1:
                        
                        # print('op 1')
                        # print('after op -->', arr)
                        tmp = arr[ind]
                        arr = arr[:-2]
                        arr[ind-1] = arr[ind-1]+tmp

                        continue
                    else:
                        tmp = arr[ind+2]
                        arr = arr[:ind+1] + arr[ind+3:]
                        arr[ind] = arr[ind] + tmp
                        # print('op 2')
                        # print('after op -->', arr)
                        continue
            elif arr[ind] < arr[ind+1]:
                arr[ind+1] += 1
                arr[ind] -= 1
                operations += 1
                if arr[ind] == 0:
                    if ind == 0:
                        arr = arr[1:]
                        # print('op 3')
                        # print('after op -->', arr)
                        continue
                    else:
                        tmp = arr[ind-1]
                        arr = arr[:ind-1] + arr[ind+1:]
                        arr[ind-1] = arr[ind] + tmp
                        ind = ind-1
                        # print('op 4')
                        # print('after op -->', arr)
                        continue
            # elif arr[ind] == arr[ind]+1:
            #     if ind == 0:
            #         arr[ind] += 1
            #         arr[ind+1] -= 1
            #         operations += 1
            #         if arr[ind+1] == 0:
            #             if ind+1 == len(arr)-1:
            #                 arr = arr[:-1]
            #                 print('op 1')
            #                 print('after op -->', arr)
            #                 continue
            #         else:
            #             tmp = arr[ind+2]
            #             arr = arr[:ind+1] + arr[ind+3:]
            #             arr[ind] = arr[ind] + tmp
            #             print('op 2')
            #             print('after op -->', arr)
            #             continue
            #     elif ind == len(arr)-2:
            #         arr[ind+1] += 1
            #         arr[ind] -= 1
            #         operations += 1
            #         if arr[ind] == 0:
            #             if ind == 0:
            #                 arr = arr[1:]
            #                 print('op 3')
            #                 print('after op -->', arr)
            #                 continue
            #             else:
            #                 tmp = arr[ind-1]
            #                 arr = arr[:ind-1] + arr[ind+1:]
            #                 arr[ind-1] = arr[ind] + tmp
            #                 ind = ind-1
            #                 print('op 4')
            #                 print('after op -->', arr)
            #                 continue
            #     else:
            #         sum_left = arr[ind-1] + ind[+1]
            #         sum_right = arr[ind]+arr[ind+2]
            #         if sum_left >= sum_right:
            #             arr[ind+1] += 1
            #             arr[ind] -= 1
            #             operations += 1
            #             if arr[ind] == 0:
            #                 if ind == 0:
            #                     arr = arr[1:]
            #                     print('op 3')
            #                     print('after op -->', arr)
            #                     continue
            #                 else:
            #                     tmp = arr[ind-1]
            #                     arr = arr[:ind-1] + arr[ind+1:]
            #                     arr[ind-1] = arr[ind] + tmp
            #                     ind = ind-1
            #                     print('op 4')
            #                     print('after op -->', arr)
            #                     continue
            #         elif sum_left < sum_right:
            #             arr[ind] += 1
            #             arr[ind+1] -= 1
            #             operations += 1
            #             if arr[ind+1] == 0:
            #                 if ind+1 == len(arr)-1:
            #                     arr = arr[:-1]
            #                     print('op 1')
            #                     print('after op -->', arr)
            #                     continue
            #             else:
            #                 tmp = arr[ind+2]
            #                 arr = arr[:ind+1] + arr[ind+3:]
            #                 arr[ind] = arr[ind] + tmp
            #                 print('op 2')
            #                 print('after op -->', arr)
            #                 continue
                    
        ind += 1
    # print(arr)
    print(operations, len(arr))