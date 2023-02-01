#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int recurse(int* coins[], int N, int sum, int ind, map<pair<int, int>, int>*m, vector<vector<int>>*v){
        // cout<<"curr "<<sum<<endl;
        if((*v)[sum][ind]==1){
            return (*m)[pair<int, int>(sum, ind)];
        }
        (*v)[sum][ind]=1;
        if(sum==0){
            return (*m)[pair<int, int>(sum, ind)]=1;
        }
        int count = 0;
        for(int i = ind; i<N; i++){
            if(sum-(*coins)[i]>=0){
                // cout<<"call recurse on "<<sum<<endl;
                count+=recurse(coins, N, sum-(*coins)[i], i, m, v);
                // cout<<"call back to "<<sum<<endl;
            }
        }
        // cout<<sum<<" "<<count<<endl;
        return (*m)[pair<int, int>(sum, ind)]=count;
    }
    
    long long int count(int coins[], int N, int sum) {
        // map<pair<int, int>, int>m;
        // vector<vector<int>>v(sum+1, vector<int>(N+1));
        // return recurse(&coins, N, sum, 0, &m, &v);
        
        
        vector<vector<long long>>v(N+1, vector<long long>(sum+1));
        for(long long i=0; i<N; i++){
            v[i][0]=1;
        }
        for(long long i=0; i<N; i++){
            long long currCoin=coins[i];
            for(long long j=1; j<=sum; j++){
                if(currCoin<=j){
                    v[i][j]=v[i][j-currCoin];
                }
                if(i>0){
                    v[i][j]+=v[i-1][j];
                }
            }
        }
        return v[N-1][sum];
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}