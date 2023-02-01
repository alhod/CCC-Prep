#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, k;
vector<ll>v;
map<ll, ll>dp;


ll recurse(ll ind){

    if(ind==n){
        return 0;
    }

    if(dp[ind]!=0){
        return dp[ind];
    }

    ll best=0;
    ll prev_best=0;
    for(ll i=ind; i<ind+k&&i<n; i++){
        prev_best=max(prev_best, v[ind]);
        best=max(best, prev_best+recurse(ind+1));
    }

    printf("ind: %d, best: %d\n", ind, best);

    return dp[ind]=best;
}


void solution(){
    cin>>n>>k;

    v.resize(n);    

    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<recurse(0)<<endl;

    
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}