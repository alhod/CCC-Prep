#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll>v(n);
        v[0]=n;
        for(ll i=1; i<n; i++){
            v[i]=i;
        }
        for(ll i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}