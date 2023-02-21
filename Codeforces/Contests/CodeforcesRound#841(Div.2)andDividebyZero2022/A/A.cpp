#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll ans=0;

    for(ll i=0; i<n-1; i++){
        v[i+1]=v[i]*v[i+1];
        v[i]=1;
    }

    for(ll i=0; i<n; i++){
        ans+=v[i];
    }

    cout<<ans*2022<<endl;
    
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