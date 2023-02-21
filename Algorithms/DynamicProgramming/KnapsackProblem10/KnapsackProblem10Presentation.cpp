// imports
#include<bits/stdc++.h>
using namespace std;



// Memoized solution
int knapsackMemoization(int i, int j, int wt[], int val[], map<pair<int, int>, int>&memo){


    // check if subproblem has already been computed
    if(memo[pair<int, int>(i, j)]!=0){

        // if so, return the stored value
        return memo[pair<int, int>(i, j)];
    }


    // check for base cases
    if(i==-1||j==0){
        return 0;
    }


    // if item weight exceeds current capacity
    if(wt[i]>j){
        // return previous optimal way to fill capacity of j, and store in memo table
        return memo[pair<int, int>(i, j)]=knapsackMemoization(i-1, j, wt, val, memo);
    } 
    

    // if current item fits in curent knapsack
    else {
        // use state transition to find solution, and store in memo table
        return memo[pair<int, int>(i, j)]=max(val[i]+knapsackMemoization(i-1, j-wt[i], wt, val, memo), knapsackMemoization(i-1, j, wt, val, memo));
    }


}
// Memoized solution



// Tabulated solution
int knapsackTabulation(int n, int w, int wt[], int val[]){


    // create tabulation table
    vector<vector<int>>tab(n+1, vector<int>(w+1));


    // iterate through item indices
    for(int i=1; i<=n; i++){


        // iterate through knapsack capacities
        for(int j=1; j<=w; j++){


            // if item weight exceeds current capacity
            if(wt[i-1]>j){
                // get previous most optimal way to fill knapsack of capacity j and store in tabulation table
                tab[i][j]=tab[i-1][j];
            } 
            

            // if item fits in current knapsack
            else {
                // use state transition to find solution, and store in tabulation table
                tab[i][j]=max(tab[i-1][j], val[i-1]+tab[i-1][j-wt[i-1]]);
            }


        }


    }


    return tab[n][w];
}
// Tabulated solution



// Tabulated solution (2*W space complexity)
int knapsackTabulationOptimized(int n, int w, int wt[], int val[]){


    // Only difference is the "%2" beside "i"s when indexing into tabulation table.
    // Notice how previous tabulated solution really only requires two rows at a time:
    // The current and previous rows. Therefore, we can manage with only two rows,
    // and bring the space complexity down from n*W to 2*W.


    vector<vector<int>>tab(2, vector<int>(w+1));


    for(int i=1; i<=n; i++){


        for(int j=1; j<=w; j++){


            if(wt[i-1]>j){
                tab[i%2][j]=tab[(i-1)%2][j];
            } 
            
            
            else {
                tab[i%2][j]=max(tab[(i-1)%2][j], val[i-1]+tab[(i-1)%2][j-wt[i-1]]);
            }


        }


    }


    return tab[n%2][w];
}
// Tabulated solution (2*W space complexity)




// main function
int main()
{
    //reading number of elements and weight
    int n, w;
    cin>>n>>w;
    

    // arrays
    int val[n];
    int wt[n];


    //inserting the values
    for(int i=0;i<n;i++){
        cin>>val[i];
    }


    //inserting the weights
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    
    // create memoization table
    map<pair<int, int>, int>memo;


    // printing answer
    cout<<"Memoized solution: "<<knapsackMemoization(n-1, w, wt, val, memo)<<endl;
    cout<<"Tabulated solution: "<<knapsackTabulation(n, w, wt, val)<<endl;
    cout<<"Tabulated solution (2*W space complexity): "<<knapsackTabulationOptimized(n, w, wt, val)<<endl;

	return 0;
}