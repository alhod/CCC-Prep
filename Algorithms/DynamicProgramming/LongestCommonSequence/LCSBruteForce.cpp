#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    
    int step2(int n, int start, int* a[]){
        if(start==n-1){
            return 1;
        }
        
        int curr=(*a)[start];
        int best = 1;
        for(int i=start+1; i<n; i++){
            if((*a)[i]>curr){
                int currBest = 1+step2(n, i, a);
                if(currBest>best){
                    best=currBest;
                }
            }
            
        }
        return best;
    }
    
    int step1(int n, int start, int *a[]){

        int best = 1;
        for(int i=0; i<n; i++){
            int currBest=step2(n, i, a);
            if(currBest>best){
                best=currBest;
            }
        }
        return best;
    }
    
    int longestSubsequence(int n, int a[])
    {
        return step1(n, 0, &a);
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