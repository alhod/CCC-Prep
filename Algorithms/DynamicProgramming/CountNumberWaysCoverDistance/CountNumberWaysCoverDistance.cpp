// Count number ways cover distance: 
//      Given a distance ‘dist’, count total number of ways to cover the 
//      distance with 1, 2 and 3 steps.

// Naive: O(N^3)
//      Subtract all combinations of 1s, 2s, and 3s until you reach 0, 
//      (in which case return 1, since one combination is found).

// DP:
//      We can memoize the number of possible combinations to reach 0 by
//      subtracting 1s, 2s, and 3s for any number n.

// Base Case:
//      If n==0, then we have reached one possible combination, thus
//      return 1.

// Optimal Substructure:
//      Let f(n) be the number of combinations of subtracting 1s, 2s, and
//      3s to reach 0 from n. Then f(n)=f(n-1)+f(n-2)+f(n-3).



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define mod 1000000007

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // dp table
        vector<int>dp(n+1);
        
        set<int>s;

        // base case
        dp[0]=1;

        // iterate through all distances up to n
        for(int i=1; i<=n; i++){

            // optimal substructure
            if(i-1>=0){
                dp[i]+=(dp[i-1])%mod;
                dp[i]%=mod;
            }
            if(i-2>=0){
                dp[i]+=(dp[i-2])%mod;
                dp[i]%=mod;
            }
            if(i-3>=0){
                dp[i]+=(dp[i-3])%mod;
                dp[i]%=mod;
            }
        }
        
        return dp[n];
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends