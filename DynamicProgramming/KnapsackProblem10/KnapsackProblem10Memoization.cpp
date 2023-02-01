//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int recurse(int W, int wt[], int val[], int n, int ind, map<pair<int, int>, int>&m){
        if(m[pair<int, int>(ind, W)]!=0){
            return m[pair<int, int>(ind, W)];
        }
        int best=0;
        if(ind==n){
            return best;
        }
        for(int i=ind; i<n; i++){
            if(W-wt[i]<0){
                continue;
            }
            int currBest=val[i]+recurse(W-wt[i], wt, val, n, i+1, m);
            best=max(best, currBest);
        }
        return m[pair<int, int>(ind, W)]=best;
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        map<pair<int, int>, int>m;
        return recurse(W, wt, val, n, 0, m);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends