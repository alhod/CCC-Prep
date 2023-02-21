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

    for(ll i=1; i<n; i++){
        v[i]+=v[i-1];
    }

    ll best=0;

    for(ll i=0; i<n-1; i++){
        ll a=v[i];
        ll b=v[n-1]-v[i];
        best=max(best, gcd(a, b));
    }

    cout<<best<<endl;
    
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