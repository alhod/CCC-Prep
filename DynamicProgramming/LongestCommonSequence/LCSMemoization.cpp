#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int recurse(int n, int start, int* a[], map<int, int>*m){
        if((*m)[start]!=0){
            return (*m)[start];
        }
        if(start==n-1){
            return (*m)[start]=1;
        }
        
        int curr=(*a)[start];
        int best = 1;
        for(int i=start+1; i<n; i++){
            if((*a)[i]>curr){
                int currBest = 1+recurse(n, i, a, m);
                if(currBest>best){
                    best=currBest;
                }
            }
            
        }
        return (*m)[start]=best;
    }
    
    int recurse1(int n, int start, int *a[]){
        map<int, int>m;
        int best = 1;
        for(int i=0; i<n; i++){
            int currBest=recurse(n, i, a, &m);
            if(currBest>best){
                best=currBest;
            }
        }
        return best;
    }
    
    int longestSubsequence(int n, int a[])
    {
        return recurse1(n, 0, &a);
    }
};





//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends