villages = int(input(''))
arr = []
total = []
for i in range(0, villages):
    arr.append(int(input('')))
arr.sort()
for ind in range(0, villages):
    if ind == 0:
        total.append(10000000000000000000000000000000)
    elif ind == villages-1:
        total.append(10000000000000000000000000000000)
    else:
        total.append(((arr[ind]+arr[ind+1])/2)-((arr[ind]+arr[ind-1])/2))
print(str(min(total)).format('.1f'))