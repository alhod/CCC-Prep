#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll k;cin>>k;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)cin>>v[i];
        if(k==1){
            cout<<(n%2==0?n/2-1:n/2)<<endl;
            continue;
        }
        ll ans=0;

        for(ll i=1;i<n-1;i++){
            if(v[i]>v[i-1]+v[i+1]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}