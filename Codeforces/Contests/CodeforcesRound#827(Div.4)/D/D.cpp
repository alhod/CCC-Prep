#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1; i<n+1; i++){
        cin>>v[i];
    }
    ll best=-1;
    for(ll i=n; i>0; i--){
        for(ll j=i; j>0; j--){
            if(gcd(v[i], v[j])==1){
                best=max(best, i+j);
            }
        }
    }
    cout<<best<<endl;
    return 0;
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