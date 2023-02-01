#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int longestSubsequence(int n, int a[])
    {
        int lis[n];
        for(int i=0; i<n; i++){
            lis[i]=1;
        }
        int best=1;
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(a[j]>a[i]){
                    lis[i]=max(lis[i], 1+lis[j]);
                }
            }
            best=max(best, lis[i]);
        }

        return best;
        
    }
};


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

