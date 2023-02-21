#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, q;
    cin>>n>>q;

    vector<pair<ll, ll>>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    
    vector<vector<ll>>cnt(1005, vector<ll>(1005, 0));
    
    for(ll i=0; i<n; i++){
        cnt[v[i].first][v[i].second]+=v[i].first*v[i].second;
    }

    for(ll i=1; i<1001; i++){
        for(ll j=1; j<1001; j++){
            cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
        }
    }

    while(q--){
        ll h1, w1, h2, w2;
        cin>>h1>>w1>>h2>>w2;
        cout<<cnt[h2-1][w2-1]-cnt[h2-1][w1]-cnt[h1][w2-1]+cnt[h1][w1]<<endl;
    }


    
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