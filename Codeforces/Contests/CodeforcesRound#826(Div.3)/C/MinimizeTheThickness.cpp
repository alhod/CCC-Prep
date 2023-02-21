#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll recurse(ll n, ll ind, ll toSum, vector<ll>&v){
    if(ind+1==n){
        return 0;
    }
    ll best=1e10;
    ll sum=0;
    for(ll i=ind+1; i<n; i++){
        sum+=v[i];
        if(sum==toSum){
            ll ans=recurse(n, i, toSum, v);
            best=min(best, max(ans, i-ind));
        }
    }
    return best;
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>pre(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            pre[i]=v[i];
        } else {
            pre[i]=pre[i-1]+v[i];
        }
    }
    ll best=1e10;
    for(ll i=n-1; i>=0; i--){
        // cout<<"sum to send: "<<pre[i]<<endl;
        ll ans=recurse(n, i, pre[i], v);
        best=min(best, max(ans, i+1));
        // cout<<"next"<<endl;
    }
    cout<<best<<endl;
    return 0;
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