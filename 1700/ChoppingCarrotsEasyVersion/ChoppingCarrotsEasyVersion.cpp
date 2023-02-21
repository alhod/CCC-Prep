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

    ll best=1e18;
    for(ll i=0; i<=v[0]; i++){
        vector<ll>p(n);
        for(ll j=0; j<n; j++){
            if(i==0){
                p[j]=k;
            } else {
                p[j]=min(v[j]/i, k);
            }
        }
        ll mx=0, mn=1e18;
        for(ll j=0; j<n; j++){
            mx=max(mx, v[j]/p[j]);
            mn=min(mn, v[j]/p[j]);
        }
        // printf("i: %d\n", i);
        // for(ll j=0; j<n; j++){
        //     printf("%d ", p[j]);
        // }
        // printf("mx: %d, mn: %d\n", mx, mn);
        best=min(best, mx-mn);
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