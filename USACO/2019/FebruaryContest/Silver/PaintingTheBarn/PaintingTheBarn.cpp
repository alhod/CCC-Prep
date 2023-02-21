#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    vector<vector<ll>>farm(1002, vector<ll>(1002));
    for(ll i=0; i<n; i++){
        ll x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        farm[x1][y1]++;
        farm[x2][y2]++;
        farm[x1][y2]--;
        farm[x2][y1]--;
    }

    for(ll i=0; i<1002; i++){
        for(ll j=0; j<1002; j++){
            if(i){
                farm[i][j]+=farm[i-1][j];
            }
            if(j){
                farm[i][j]+=farm[i][j-1];
            }
            if(i&&j){
                farm[i][j]-=farm[i-1][j-1];
            }
        }
    }

    ll ans=0;

    for(ll i=0; i<1002; i++){
        for(ll j=0; j<1002; j++){
            if(farm[i][j]==k){
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    if (fopen("paintbarn.in", "r")) {
        freopen("paintbarn.in", "r", stdin);
        freopen("paintbarn.out", "w", stdout);
    }

    solution();
}