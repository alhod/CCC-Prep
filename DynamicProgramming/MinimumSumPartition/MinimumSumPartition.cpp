// Minimum Sum Partition:
//      Given an array arr of size n containing non-negative integers, the task 
//      is to divide it into two sets S1 and S2 such that the absolute 
//      difference between their sums is minimum and find the minimum difference

// Naive:
//      Since each item can be in either set, then there are 2^n possible 
//      sums of S1 and S2

// DP:
//      Since every item belongs to a set, we only need to calculate the possible
//      sums for S1, since sum(arr) - sum(S1) == sum(S2). We can calculate all 
//      possible sums for S1, iterate through them, find the corresponding sum for
//      S2, and do best=min(best, abs(S1-S2)). To find all possible sums for S1 we
//      can create a 2D array dp[n+1][total_sum+1], where dp[i][j]=true if it is 
//      possible to reach sum j using nodes 1...i.

// Base Case:
//      Since it is possible to reach total sum of 0 no matter the i-value, we will
//      set dp[i][0]=true for all 0<=i<=n.

// Optimal Substructure:
//      dp[i][j]=true if either 
//          dp[i-1][j]==true (we add item i to S2 instead of S1,
//          so we check if it is possible to reach sum j with items 1...i-1) 
//      or 
//          dp[i-1][j-arr[i-1]]==true (we subtract ith item arr[i-1] [i-1 since arr 
//          starts at 0] from sum j, and check if we can reach j-arr[i-1] using items
//          1...i-1).

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
  
	int minDifference(int arr[], int n)  { 
	    
        // Total sum
        int tot=0;
	    for(int i=0; i<n; i++){
	        tot+=arr[i];
	    }
	    
	    // dp[i][j]==true if sum j is reachable with the first i items
	    vector<vector<bool>>dp(n+1, vector<bool>(tot+1, false));
	    

        // Base cases
	    for(int i=0; i<=n; i++){
	        dp[i][0]=true;
	    }
	    
        // Iterate through items
	    for(int i=1; i<=n; i++){

            // Iterate through total sum
	        for(int j=1; j<=tot; j++){

                // Check optimal substructure
	            if(j-arr[i-1]>=0&&dp[i-1][j-arr[i-1]]){
	                dp[i][j]=true;
	            } else if(dp[i-1][j]){
	                dp[i][j]=true;
	            }
	        }
	    }
	    

        // Iterates through all possible sums, and finds the one that 
        // results in the smallest abs(S1-S2) value
	    int best=1e9;
	    for(int i=0; i<=tot; i++){

            // Check if sum is possible
	        if(!dp[n][i])continue;

	        best=min(best, abs(i-abs(tot-i)));
	    }
	    
	    return best;
	    
	    
	    
	}
	
};



int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}