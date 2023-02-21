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


void solution(){
    ll a, b;
    cin>>a>>b;

    cout<<exp(a, b, 1e9+7)<<endl;
    
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