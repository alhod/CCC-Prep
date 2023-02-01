# 2 Sum:
# "Given an array of integers nums and an integer target , return indices of the two numbers such that they add up to target .""

# Solution:
# We use components:
#   We iterate through the array, and find 'what value added with this value == target?' That value is the component: component = target - arr[i]
# If the component is in the hashtable, then we know there's a value in the array that adds with the current value to equal the target.
# Otherwise, the component is not in the hashtable, and we add this current value into the hashtable: current val (x) --> index in array
#   This means that next time we iterate to a value (y) who's component is x, then we will be able to search through the hashtable and confirm x exists in the array
#   and get x's index in the array -- all in constant time.

# Time complexity: O(n)
#   This strategy is very efficient, because we only need to iterate through the entire array once. Hashtable inserts and lookups are bot constant time.


def hashtable_solution():
    arr = [int(i) for i in input('Input array of numbers: ').split(' ')]
    target = int(input('Input target: '))

    ht = {}  # corresponding values to their index in the arr

    for i in range(0, len(arr)):
        compliment = target - arr[i]  # calculates compliment (compliment + arr[i] = target)
        if compliment in ht:  # sees if compliment is in hashtable
            return ht[compliment], i # if it is, then return the compliment index and the index of this iteration
        else:
            ht[arr[i]] = i  # if compliment is not in the hashtable, then we add arr[i] into the hashtable and set its index
    
    return None




# This is the naive solution that iterates through the array twice, resulting in O(n^2)
def naive_solution():
    arr = [int(i) for i in input('Input array of numbers: ').split(' ')]
    target = int(input('Input target: '))

    for i in range(0, len(arr)):
        for j in range(0, len(arr)):
            if arr[i] + arr[j] == target and i != j:
                return i, j
    
    return None




# This method is also naive, though less naive than the last. It looks as though it only iterates through the array once, so O(n).
# However, the .index() method iterates a second time, which is O(n) as well. This results in O(2n), which isn't bad, but is twice as slow
# as the optimal solution.
def other_naive():
    arr = [int(i) for i in input('Input array of numbers: ').split(' ')]
    target = int(input('Input target: '))
    for i in range(0, len(arr)):
        compliment = target - arr[i]
        if compliment in arr:
            return arr.index(compliment), i

    return None



if __name__ == '__main__':
    print(other_naive())  # choose solution.