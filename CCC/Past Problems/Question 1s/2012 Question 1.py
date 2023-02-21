# 4 --> 1
# 5 --> 5432, 5431, 5421, 5321, 4321
# 6 --> 6543, 6542, 6541, 6532, 6531, 6521, 6432, 6431, 6421, 6321, 5432, 5431, 5421, 5321, 4321
# 7 --> 7654, 7653, 7652, 7651, 7643, 7642, 7641, 7632, 7631, 7621, 7543, 7542, 7541, 7532, 7531, 7521, 7432, 7431, 

num = int(input(''))
arr = []

for i in range(0, 4):
    arr.append(num-i)

if arr[0] < 1:
    print(0)
else:
    count = 0
    while True:
        #print(arr)
        count += 1
        arr[3] = arr[3] - 1
        if arr[3] < 1:
            arr[2] = arr[2]-1
            arr[3] = arr[2]-1
            if arr[2] < 2:
                arr[1] = arr[1]-1
                arr[2] = arr[1]-1
                arr[3] = arr[2]-1
                if arr[1] < 3:
                    arr[0] = arr[0]-1
                    arr[1] = arr[0]-1
                    arr[2] = arr[1]-1
                    arr[3] = arr[2]-1
                    if arr[0] < 4:
                        break
print(count)



# count = 0
# for i in reversed(range(0, num)):
#     if i == 3:
#         break
#     for j in reversed(range(0, num-1)):
#         if j == 2:
#             break
#         for x in reversed(range(0, num-2)):
#             if x == 1:
#                 break
#             for y in reversed(range(0, num-3)):
#                 if y == 0:
#                     break
#                 count += 1
# print(count)