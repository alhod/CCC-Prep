#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

#define MOD 1000000007



void solution(){
    ll n;
    cin>>n;
    ll ans=(((((n*(n+1))%MOD)*(4*n-1))%MOD)*337)%MOD;
    cout<<ans<<endl;
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