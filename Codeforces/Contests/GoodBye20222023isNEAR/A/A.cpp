#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    ll total=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        total+=x;
        pq.push(x);
    }

    vector<ll>ops(m);
    for(ll i=0; i<m; i++){
        cin>>ops[i];
    }

    for(ll i=0; i<m; i++){
        ll smallest=pq.top();
        pq.pop();
        total-=smallest;
        pq.push(ops[i]);
        total+=ops[i];
    }

    cout<<total<<endl;
    
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