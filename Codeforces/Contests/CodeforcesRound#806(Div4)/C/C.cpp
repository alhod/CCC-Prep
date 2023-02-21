#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>wheels(n);
        for(ll i=0; i<n; i++){
            cin>>wheels[i];
        }
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            string moves; cin>>moves;
            for(ll j=0;j<x;j++){
                if(moves[j]=='D'){
                    wheels[i]+=1;
                    if(wheels[i]==10){
                        wheels[i]=0;
                    }
                } else {
                    wheels[i]-=1;
                    if(wheels[i]==-1){
                        wheels[i]=9;
                    }
                }
            }
        }
        for(auto i:wheels){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}