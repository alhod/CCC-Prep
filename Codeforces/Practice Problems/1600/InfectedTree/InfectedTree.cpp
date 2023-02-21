#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
map<ll, vector<ll>>adj;
vector<ll>order;
vector<ll>visited;

void dfs(ll curr){
    visited[curr]=1;

    for(ll i:adj[curr]){
        if(!visited[i]){
            dfs(i);
        }
    }

    order.push_back(curr);
}


void solution(){
    cin>>n;
    adj.clear();
    order.clear();
    visited.clear();
    visited.resize(n+1);
    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    visited.clear();
    visited.resize(n+1);

    map<ll, pair<ll, ll>>cut_or_infect;

    for(ll i=0; i<n; i++){
        // printf("order[%d]: %d\n", i, order[i]);

        visited[order[i]]=1;
        ll cut=0;
        ll infect=0;

        ll child1=0;
        ll child2=0;

        for(ll j:adj[order[i]]){
            if(visited[j]){
                // printf("child node: %d\n", j);
                cut+=cut_or_infect[j].first+1;
                if(child1==0){
                    child1=j;
                } else {
                    child2=j;
                }
            }
        }

        ll cut_child1_infect_child2=cut_or_infect[child1].first+cut_or_infect[child2].second;
        ll cut_child2_infect_child1=cut_or_infect[child2].first+cut_or_infect[child1].second;

        infect=max(cut_child1_infect_child2, cut_child2_infect_child1);

        cut_or_infect[order[i]].first=cut;
        cut_or_infect[order[i]].second=infect;
        // printf("cut: %d, infect: %d\n", cut, infect);
    }

    cout<<cut_or_infect[1].second<<endl;
    
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