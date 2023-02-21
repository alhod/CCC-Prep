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
        ll sum=0;
        ll greatest=-1;
        for(ll i=0; i<n; i++){
            greatest=max(greatest, v[i]);
            sum+=v[i];
        }
        if(greatest==0){
            cout<<"0"<<endl;
        } else if(greatest<=(sum-greatest)){
            cout<<1<<endl;
        } else {
            cout<<greatest-(sum-greatest)<<endl;
        }
    }
}