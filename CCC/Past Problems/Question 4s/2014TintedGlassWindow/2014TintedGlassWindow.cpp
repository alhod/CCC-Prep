#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, desired_tint;
    cin>>n>>desired_tint;
    vector<vector<ll>>window(1001, vector<ll>(1001));
    for(ll i=0; i<n; i++){
        ll x1, y1, x2, y2, tint;
        cin>>x1>>y1>>x2>>y2>>tint;
        for(ll x=y1; x<y2; x++){
            for(ll y=x1; y<x2; y++){
                window[x][y]+=tint;
            }
        }
    }

    // for(ll i=0; i<20; i++){
    //     for(ll j=0; j<20; j++){
    //         cout<<window[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ans=0;
    for(ll i=0; i<1001; i++){
        for(ll j=0; j<1001; j++){
            if(window[i][j]>=desired_tint){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}