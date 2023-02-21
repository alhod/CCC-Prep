#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>>v(16, vector<ll>(16));
        ll best=15;
        for(ll i=0; i<16; i++){
            for(ll j=0; j<16; j++){
                if(((n+j)<<i)%32768==0){
                    best=min(best, i+j);
                }
            }
        }
        cout<<best<<endl;
    }
}