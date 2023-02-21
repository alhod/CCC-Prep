#include<bits/stdc++.h>
#define ll long long
using namespace std;


void dfs(ll curr, set<ll>&component, map<ll, vector<ll>>&adj, vector<ll>&seen){
    seen[curr]=1;
    component.insert(curr);
    for(auto neighbor:adj[curr]){
        if(!seen[neighbor]){
            dfs(neighbor, component, adj, seen);
        }
    }
}


void solution(){
    ll n, m;
    cin>>n>>m;
    map<ll, vector<ll>>adj;
    for(ll i=0; i<m; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<ll>seen(n+1);
    
    set<ll>component1;
    dfs(1, component1, adj, seen);
    if(*lower_bound(component1.begin(), component1.end(), n)==n){
        cout<<0<<endl;
        return;
    }
    set<ll>componentn;
    dfs(n, componentn, adj, seen);

    ll best=1e18;
    for(auto i:component1){
        auto iter=lower_bound(componentn.begin(), componentn.end(), i);
        if(iter!=componentn.end()){
            best=min(best, (ll)pow(*iter-i, 2));
        }
        if(iter!=componentn.begin()){
            iter--;
            best=min(best, (ll)pow(*iter-i, 2));
        }
    }

    vector<set<ll>>otherComponents;

    for(ll i=2; i<n; i++){
        if(!seen[i]){
            set<ll>currComponent;
            dfs(i, currComponent, adj, seen);
            otherComponents.push_back(currComponent);
        }
    }

    for(auto otherComponent: otherComponents){
        // component1
        ll bestCostComponent1=1e18;
        for(auto node:otherComponent){
            auto iter=lower_bound(component1.begin(), component1.end(), node);
            if(iter!=component1.end()){
                bestCostComponent1=min(bestCostComponent1, (ll)pow(*iter-node, 2));
            }
            if(iter!=component1.begin()){
                iter--;
                bestCostComponent1=min(bestCostComponent1, (ll)pow(*iter-node, 2));
            }
        }

        // componentn
        ll bestCostComponentn=1e18;
        for(auto node:otherComponent){
            auto iter=lower_bound(componentn.begin(), componentn.end(), node);
            if(iter!=componentn.end()){
                bestCostComponentn=min(bestCostComponentn, (ll)pow(*iter-node, 2));
            }
            if(iter!=componentn.begin()){
                iter--;
                bestCostComponentn=min(bestCostComponentn, (ll)pow(*iter-node, 2));
            }
        }

        best=min(best, bestCostComponent1+bestCostComponentn);
    }

    cout<<best<<endl;

    
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