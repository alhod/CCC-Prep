#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll curr=1;
    ll bad=0;
    for(ll i=0; i<n; i++){
        if(v[i]==curr){
            curr++;
        } else {
            bad++;
        }
    }

    ll ans=bad/k;
    if(bad%k>=1){
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