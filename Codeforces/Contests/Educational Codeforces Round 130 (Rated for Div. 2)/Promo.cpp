#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll n, q;
    cin>>n>>q;
    vector<ll>v(n);
    for (ll i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    vector<ll>v1(n+1);
    for (ll i=0; i<n; i++){
        v1[i+1] = v1[i] + v[i];
    }

    ll x, y;
    for (ll i=0; i<q; i++){
        cin>>x>>y;
        cout<<v1[n-x+y]-v1[n-x]<<endl;
    }

}