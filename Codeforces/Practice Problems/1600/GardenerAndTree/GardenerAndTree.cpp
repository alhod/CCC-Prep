#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n, k;
map<ll, vector<ll>>adj;
queue<ll>q;
vector<ll>layer;
vector<ll>neighbors;


void solution(){
    cin>>n>>k;

    adj.clear();    
    layer.clear();
    layer.resize(n);
    neighbors.clear();
    neighbors.resize(n);

    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(ll i=0; i<n; i++){
        neighbors[i]=adj[i].size();

        if(neighbors[i]<=1){
            layer[i]=1;
            q.push(i);
        }
    }

    while(q.size()>0){
        ll curr=q.front();
        q.pop();
        
        for(auto neighbor:adj[curr]){
            if(neighbors[neighbor]==1){
                continue;   
            }

            neighbors[neighbor]--;
            layer[neighbor]=layer[curr]+1;
            if(neighbors[neighbor]==1){
                q.push(neighbor);
            }
        }
    }

    ll ans=0;
    for(ll i=0; i<n; i++){
        // printf("layer[%d]==%d ", i, layer[i]);
        if(layer[i]>k){
            ans++;
        }
    }

    cout<<ans<<endl;


}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}