#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    
    bool hasZero=false;

    for(ll i=0; i<n; i++){
        cin>>v[i];
        if(v[i]==0){
            hasZero=true;
        }
    }

    priority_queue<ll, vector<ll>, greater<ll>>pq;
    ll ans=0;

    if(!hasZero){
        ans++;
    }

    for(ll i=0; i<n; i++){
        pq.push(v[i]);
    }

    ll people_going=0;
    bool flag=false;
    while(pq.size()>0){
        ll curr=pq.top();
        pq.pop();
        if(curr<=people_going){
            people_going++;
            flag=true;
        } else {
            if(flag){
                ans++;
                people_going++;
                flag=false;
            } else {
                people_going++;
            }
        }
    }

    if(flag){
        ans++;
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