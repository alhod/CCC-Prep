# initialize memo table as global variable
memo = {};


# Memoized solution
def knapsackMemoization(i, j, wt, val):


    # check if already computed this state
    if((i, j) in memo):

        # if so, return stored solution
        return memo[(i,j)]


    # check for base cases
    if(i==-1 or j==0):
        return 0


    # if ith item exceeds capacity j
    if(wt[i]>j):

        # get previously most optimal way to fill knapsack of capacity j, and store in memo table
        memo[(i, j)]=knapsackMemoization(i-1, j, wt, val)

        # return solution
        return memo[(i, j)]


    # if ith item fits in capacity j
    else:

        # use state transition, and store solution in memo table
        memo[(i, j)]=max(val[i]+knapsackMemoization(i-1, j-wt[i], wt, val), knapsackMemoization(i-1, j, wt, val))
        
        # return solution
        return memo[(i, j)]
# Memoized solution    



# Tabulated solution
def knapsackTabulation(n, W, wt, val):


    # create tabulation table
    tab = []


    # fill tabulation table with 0s
    for i in range(0, n+1):
        tab.append([])
        for j in range(0, W+1):
            tab[i].append(0)


    # iterate through each item
    for i in range(1, n+1):


        # iterate through each capacity
        for j in range(1, W+1):


            # if ith item exceeds capacity j
            if(wt[i-1]>j):

                # get previously most optimal way to fill knapsack of capacity j
                # store in tabulation table
                tab[i][j]=tab[i-1][j]



            # if ith item fits in knapsack of capacity j
            else:

                # use state transition, and store in tabulation table
                tab[i][j]=max(tab[i-1][j], val[i-1]+tab[i-1][j-wt[i-1]])
    

    # return answer
    return tab[n][W]
# Tabulated solution



# Tabulated solution (2*W space complexity)
def knapsackTabulationOptimized(n, W, wt, val):


    # Only difference is the "%2" beside "i"s when indexing into tabulation table.
    # Notice how previous tabulated solution really only requires two rows at a time:
    # The current and previous rows. Therefore, we can manage with only two rows,
    # and bring the space complexity down from n*W to 2*W.


    tab = []


    for i in range(2):
        tab.append([])
        for j in range(0, W+1):
            tab[i].append(0)


    for i in range(1, n+1):


        for j in range(1, W+1):


            if(wt[i-1]>j):
                tab[i%2][j]=tab[(i-1)%2][j]


            else:
                tab[i%2][j]=max(tab[(i-1)%2][j], val[i-1]+tab[(i-1)%2][j-wt[i-1]])
    

    return tab[n%2][W]
# Tabulated solution (2*W space complexity)



# get inputs
n = int(input("Input total number of items: "))
W = int(input("Weight capacity of knapsack: "))


# create arrays
val=[]
wt=[]


# input values
for i in range(1, n+1):
    val.append(int(input(f"Input value of {i}th item: ")))


# input weights
for i in range(1, W+1):
    wt.append(int(input(f"Input weight of {i}th item: ")))


# print answers
print("Memoized solution:", knapsackMemoization(n-1, W, wt, val))
print("Tabulated solution:", knapsackTabulation(n, W, wt, val))
print("Tabulated solution (2*W space complexity):", knapsackTabulationOptimized(n, W, wt, val))