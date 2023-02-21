#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define mod 998244353
map<ll, ll>dp;


ll recurse(ll n){
    if(n<=1){
        return n    ;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    return dp[n]=(n*recurse(n-1))%mod;
}


void solution(){
    dp.clear();
    ll n;
    cin>>n;

    ll alex=0, boris=0;
    
    for(ll i=n; i>=2; i-=4){
        alex+=recurse(i-1);
        alex%=mod;
    }

    for(ll i=n-1; i>=1; i-=4){
        boris+=recurse(i-1);
        boris%=mod;
    }

    printf("%d %d 1\n", alex, boris);
    
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