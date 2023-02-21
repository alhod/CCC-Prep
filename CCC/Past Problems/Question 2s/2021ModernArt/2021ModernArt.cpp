#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m, k;
    cin>>n>>m>>k;

    vector<ll>rows(n);
    vector<ll>cols(m);
    for(ll i=0; i<k; i++){
        char type;
        ll num;
        cin>>type;
        cin>>num;
        if(type=='R'){
            rows[num-1]++;
        } else {
            cols[num-1]++;
        }
    }


    // for(ll i=0; i<n; i++){
    //     cout<<rows[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=0; i<m; i++){
    //     cout<<cols[i]<<" ";
    // }
    // cout<<endl;


    ll ans=0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            ans+=((rows[i]+cols[j])%2==0?0:1);
        }
    }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}