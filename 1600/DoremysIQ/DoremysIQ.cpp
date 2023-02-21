#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool check(ll x, ll iq, vector<ll>&ans, vector<ll>&v){
    for(ll i=0; i<x; i++){
        if(v[i]<=iq){
            ans[i]=1;
        } else {
            ans[i]=0;
        }
    }

    for(ll i=x; i<v.size(); i++){
        if(iq==0){
            return false;
        }
        
        if(v[i]>iq){
            iq--;
        }
        ans[i]=1;
    }

    return true;
}


void solution(){
    ll n, iq;
    cin>>n>>iq;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll l=0, r=n-1, mid;
    vector<ll>ans;
    while(l<=r){
        mid=l+(r-l)/2;
        vector<ll>tmp(n);
        if(check(mid, iq, tmp, v)){
            r=mid-1;
            ans=tmp;
        } else {
            l=mid+1;
        }
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i];
    }
    cout<<endl;
    
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