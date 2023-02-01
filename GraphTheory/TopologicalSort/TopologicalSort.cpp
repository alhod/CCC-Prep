// Time Complexity: O(V+E)
// Space Complexity: O(V)

// Topological sort is an ordering of nodes such that for every edge
// from node u to node v, u appears before v in the ordering.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void TopologicalSort(ll n, ll e, vector<ll>&v, map<ll, vector<ll>>&adj){
    vector<bool>visited(n, false);
    stack<ll>s;
    for(ll i=0; i<n; i++){
        if(!visited[i]){
            stack<ll>tmp;
            queue<ll>q;
            q.push(i);
            while(q.size()>0){
                ll curr=q.front();
                q.pop();
                tmp.push(curr);
                if(visited[curr]){
                    continue;
                }
                visited[curr]=true;
                for(auto neighbor:adj[curr]){
                    q.push(neighbor);
                }
            }
            while(tmp.size()>0){
                s.push(tmp.top());
                tmp.pop();
            }
        }
    }
    while(s.size()){
        v.push_back(s.top());
        s.pop();
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, e;
    cin>>n>>e;
    map<ll, vector<ll>>adj;
    for(ll i=0; i<e; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    vector<ll>v;
    TopologicalSort(n, e, v, adj);
    for(ll i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}