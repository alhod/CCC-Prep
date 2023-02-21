#include<bits/stdc++.h>
#define ll long long
using namespace std;


void dfs(ll original, ll curr, map<ll, vector<ll>>&adj, vector<vector<ll>>&reachable){
    reachable[original][curr]=1;

    for(auto i:adj[curr]){
        if(reachable[original][i]==1){
            continue;
        } else {
            dfs(original, i, adj, reachable);
        }
    }
}

void findReachable(ll n, map<ll, vector<ll>>&adj, vector<vector<ll>>&reachable){
    for(ll i=0; i<n; i++){
        dfs(i, i, adj, reachable);
    }
}

int solution(){
    ll n;
    cin>>n;
    vector<vector<ll>>v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>v[i][j];
            v[i][j]--;
        }
    }

    map<ll, vector<ll>>adj;
    for(ll i=0; i<n; i++){
        bool foundOri=false;
        for(ll j=n-1; j>=0; j--){
            if(v[i][j]==i){
                foundOri=true;
            } else if(foundOri){
                adj[i].push_back(v[i][j]);
            }
        }
    }

    vector<ll>ans(n);

    
    vector<vector<ll>>reachable(n, vector<ll>(n));
    findReachable(n, adj, reachable);


    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(reachable[v[i][j]][i]==1){
                ans[i]=v[i][j];
                break;
            }
        }
    }

    for(auto i:ans){
        cout<<i+1<<endl;
    }
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}