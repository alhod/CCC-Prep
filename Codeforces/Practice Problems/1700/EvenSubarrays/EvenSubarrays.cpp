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

    vector<ll>count(2*n+1);
    count[0]++;
    ll ans=0;
    ll curr=0;

    for(ll i=0; i<n; i++){
        curr^=v[i];
        for(ll j=0; j*j<2*n; j++){
            if(((j*j)^curr)>=2*n+1){
                continue;
            }
            ans+=count[(j*j)^curr];
        }
        count[curr]++;
    }

    cout<<n*(n+1)/2-ans<<endl;
    
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