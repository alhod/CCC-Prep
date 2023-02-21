#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>ans(n);
    for(ll i=0; i<n; i+=2){
        ans[i]=n-(i/2);
    }
    for(ll i=1; i<n; i+=2){
        ans[i]=i-(i/2);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
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