#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define mod 1000000007
ll factorials[100001];



void solution(){
    ll n;
    cin>>n;

    ll a=n*(n-1);
    a%=mod;

    cout<<((factorials[n]*a)%mod)<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    factorials[0]=1;
    for(ll i=1; i<100001; i++){
        factorials[i]=(factorials[i-1]*i)%mod;
    }


    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}