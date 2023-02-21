#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    map<ll, vector<ll>>adj;
    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ll ans=0;
    stack<ll>s;
    s.push(1);
    vector<ll>seen(n+1);
    while(s.size()>0){
        ll curr=s.top();
        s.pop();
        seen[curr]=1;

        ll days=0;
        // cout<<"curr: "<<curr<<endl;
        // cout<<"adj[curr].size(): "<<adj[curr].size()<<endl;
        while(pow(2, days)<(curr==1?adj[curr].size()+1:adj[curr].size())){
            days++;
        }
        ans+=days;
        
        for(auto neighbor:adj[curr]){
            if(seen[neighbor]==0){
                ans++;
                s.push(neighbor);
            }
        }
    }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}