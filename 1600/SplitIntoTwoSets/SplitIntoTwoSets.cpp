#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
map<ll, vector<ll>>adj;
vector<bool>visited;

ll dfs(ll curr){

    visited[curr]=true;

    ll ans=0;
    for(auto i:adj[curr]){
        if(!visited[i]){
            ans+=dfs(i);
        }
    }
    return ans+1;
}


void solution(){
    cin>>n;
    vector<pair<ll, ll>>v(n);
    vector<ll>count(n+1);
    adj.clear();
    visited.clear();
    visited.resize(n+1);
    for(ll i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
        count[v[i].first]++;
        count[v[i].second]++;
        adj[v[i].first].push_back(v[i].second);
        adj[v[i].second].push_back(v[i].first);
    }

    for(ll i=0; i<n; i++){
        if(v[i].first==v[i].second){
            cout<<"NO"<<endl;
            return;
        }
        if(count[v[i].first]>=3||count[v[i].second]>=3){
            cout<<"NO"<<endl;
            return;
        }
    }


    
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            if(dfs(i)%2==1){
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

    





    
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