// Time Complexity: O(V^3)
// Space Complexity: O(V^2)

// Floyd Warshall is an APSP algorithm (All Pairs Shortest Path) that uses
// dynamic programming.
// Optimal substructure: Shortest path from node u to node v, where k is 
// an intermediate node is min(dp[u][v], dp[u][k]+dp[k]v).

// This implementation provides negative cycle detection and shortest path
// reconstruction.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


#define INF 1e18


// Pass starting node, ending node, dp table, next table, and empty array to contain path
// Returns:
//      path.size()==0 --> no path exists
//      path.size()==1&&path[0]==-1 --> affected by negative cycle
void ReconstructPath(ll start, ll end, vector<vector<ll>>&dp, vector<vector<ll>>&next, vector<ll>&path){
    
    // Check if there exists path
    if(dp[start][end]==INF){
        return;
    }

    // Check if path affected by negative cycle
    if(dp[start][end]==-1*INF){
        path={-1};
        return;
    }

    // Backtracks using next table, until end node is reached
    ll curr=start;
    for(; curr!=end; curr=next[curr][end]){

        // note if curr==-1 then it is a part of a negative cycle
        if(curr==-1){
            path={-1};
            return;
        }
        path.push_back(curr);
    }

    // note at this point curr==end, 
    // check if ther exists negative cycle to itself
    if(next[curr][end]==-1){
        path={-1};
        return;
    }
    path.push_back(curr);
    
    return;

}


// Checks for negative cycles by running algorithm again
// If new shortest path is reached then there must exist negative cycle,
//      then dp[i][j]=-1*INF
void PropagateNegativeCycles(vector<vector<ll>>&v, vector<vector<ll>>&dp, vector<vector<ll>>&next){
    ll n=v.size();

    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=-1*INF;
                    next[i][j]=-1;
                }
            }
        }
    }
}


// FloydWarshall APSP (All Pairs Shortest Path) algorithm
// Pass matrix, empty 2D dp table, empty 2D next table
void FloydWarshall(vector<vector<ll>>&v, vector<vector<ll>>&dp, vector<vector<ll>>&next){
    ll n=v.size();


    // Resize tables
    dp.resize(n);
    next.resize(n);

    for(ll i=0; i<n; i++){
        dp[i].resize(n);
        next[i].resize(n);
    }


    // Set up dp and next tables
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            dp[i][j]=v[i][j];
            if(v[i][j]!=INF){
                next[i][j]=j;
            } else {
                next[i][j]=INF;
            }
        }
    }


    // Main dynamic programming algorithm
    for(ll k=0; k<n; k++){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                    next[i][j]=next[i][k];
                }
            }
        }
    }


    // Checks for negative cycles
    // Not necessary if there are none
    PropagateNegativeCycles(v, dp, next);

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<vector<ll>>v(n, vector<ll>(n));

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>v[i][j];
        }
    }
    vector<vector<ll>>dp;
    vector<vector<ll>>next;
    FloydWarshall(v, dp, next);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<next[i][j]<<" ";
        }
        cout<<endl;
    }
}