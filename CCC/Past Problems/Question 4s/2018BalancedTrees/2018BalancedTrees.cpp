#include<bits/stdc++.h>
#define ll long long
using namespace std;


map<ll, ll>dp;

ll recurse(ll n){
    if(n<=2){
        return 1;
    }

    if(dp[n]){
        return dp[n];
    }

    ll k=n;
    ll ret=0;
    while(k>1){
        ll x=n/k;  // valid weight value for k
        ll nn=n/(x+1);  // first k-value that has a different weight
        ret+=(k-nn)*recurse(x);  // (k-nn) is the number of times the weight x appears
        // recurse(x) is the number of different balanced subtrees for tree of weight x
        
        k=nn;  // set k to the first k-value that has a different weight
    }

    return dp[n]=ret;
}


void solution(){
    ll n;
    cin>>n;

    cout<<recurse(n)<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}