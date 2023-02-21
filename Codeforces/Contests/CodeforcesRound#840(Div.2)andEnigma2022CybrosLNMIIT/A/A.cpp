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

    ll greatest=0;
    ll smallest=1e18;
    for(ll i=0; i<n; i++){
        smallest=min(smallest, v[i]);
    }

    for(ll i=0; i<n; i++){
        greatest=(greatest|v[i]);
        smallest=(smallest&v[i]);
    }
    cout<<greatest-smallest<<endl;
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