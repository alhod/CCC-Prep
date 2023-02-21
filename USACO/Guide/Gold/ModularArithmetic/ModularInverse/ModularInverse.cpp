#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll exp(ll a, ll b, ll mod){
    ll res=1;
    
    a=a%mod;

    while(b>0){
        if(b%2==1){
            b--;
            res=(res*a)%mod;
        }

        b/=2;
        a=(a*a)%mod;
    }

    return res;
}


ll a_divide_b_mod_m(ll a, ll b, ll m){
    return a*exp(b, m-2, m);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, m=1e9+7;
    cin>>a>>b;
    printf("%lld\n", a_divide_b_mod_m(a, b, m));
}