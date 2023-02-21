#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, c;
    cin>>n>>c;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        v[i]+=i+1;
    }

    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(ll i=0; i<n; i++){
        pq.push(v[i]);
    }

    ll ans=0;
    while(c>0&&pq.size()>0){
        ll curr=pq.top();
        pq.pop();
        
        if(curr>c){
            break;
        } else {
            c-=curr;
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