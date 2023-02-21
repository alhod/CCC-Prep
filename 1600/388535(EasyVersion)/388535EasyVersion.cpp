#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll l, r;
    cin>>l>>r;
    ll n=r-l+1;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll x=0;

    for(ll i=0; i<17; i++){
        ll num1s=0;
        ll num0s=0;

        for(ll j=0; j<n; j++){
            if((v[j]&(1<<i))){
                num1s++;
            } else {
                num0s++;
            }
        }

        if(num0s<num1s){
            x+=(1<<i);
        }
    }

    cout<<x<<endl;


    
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