#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll best=-1e18;
    for(ll i=0; i<=n; i++){
        ll currAns=0;
        for(ll j=0; j<i; j++){
            currAns+=v[j]-k;
        }

        ll divide=0;
        for(ll j=i; j<=i+30&&j<n; j++){
            divide++;
            currAns+=v[j]/(1<<divide);
        }

        best=max(best, currAns);
    }

    cout<<best<<endl;
    
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