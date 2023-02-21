#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool check(ll mid, vector<ll>v){

    // cout<<"mid: "<<mid<<endl;

    ll n=v.size();

    vector<ll>extra(n, 0);

    for(ll i=n-1; i>=2; i--){
        if(extra[i]+v[i]<mid){
            // cout<<"false"<<endl;
            return false;
        }

        ll to_give;
        if(extra[i]>=mid){
            to_give=v[i];
        } else {
            to_give=extra[i]+v[i]-mid;
        }

        ll d=to_give/3;
        extra[i-2]+=d*2;
        extra[i-1]+=d;
    }

    
    // for(ll i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<extra[i]<<" ";
    // }
    // cout<<endl;

    if(v[0]+extra[0]<mid||v[1]+extra[1]<mid){
        // cout<<"false"<<endl;
        return false;
    }

    // cout<<"true"<<endl;
    return true;
}


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll l=0, r=v[n-1], mid;
    ll ans=1;
    while(l<=r){
        mid=l+(r-l)/2;

        if(!check(mid, v)){
            r=mid-1;
        } else {
            ans=mid;
            l=mid+1;
        }
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