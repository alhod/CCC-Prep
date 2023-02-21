N = int(input(''))
height_list = [int(i) for i in input('').split(' ')]
width_list = [int(i) for i in input('').split(' ')]
total = 0
for i in range(0, N):
    height = (height_list[i] + height_list[i+1])/2
    width = width_list[i]
    total += height * width

print(total)