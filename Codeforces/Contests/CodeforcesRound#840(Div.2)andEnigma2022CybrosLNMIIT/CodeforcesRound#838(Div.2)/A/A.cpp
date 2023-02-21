#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    ll countOdd=0;
    ll countEven=0;
    ll minTurnEven=1e18;
    ll minTurnOdd=1e18;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        ll curr=v[i];
        ll count=0;
        if(v[i]%2==0){
            countEven++;
            while(curr%2==0){
                curr/=2;
                count++;
            }
            minTurnOdd=min(minTurnOdd, count);
        } else {
            countOdd++;
            while(curr%2!=0){
                curr/=2;
                count++;
            }
            minTurnEven=min(minTurnEven, count);
        }
    }

    if(countOdd%2==0){
        cout<<0<<endl;
        return;
    }

    cout<<min(minTurnEven, minTurnOdd)<<endl;
    
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