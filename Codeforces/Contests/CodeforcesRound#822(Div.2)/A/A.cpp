#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        ll best = 10e8;
        for(ll i=2; i<n; i++){
            ll currBest=(v[i-1]-v[i-2])+(v[i]-v[i-1]);
            if(currBest<best){
                best=currBest;
            }
        }
        cout<<best<<endl;
    }
}