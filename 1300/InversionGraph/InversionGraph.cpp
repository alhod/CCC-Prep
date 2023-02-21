#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n+1);
        vector<ll>ind(n+1);
        ll ans=n;
        for(ll i=1; i<n+1; i++){
            ll num;
            cin>>num;
            v[i]=num;
            ind[num]=i;
        }
        
        vector<ll>seen(n+1);
        ans-=n-ind[n];
        for(ll i=ind[n]; i<n+1; i++){
            seen[v[i]]=1;
        }

        ll prev=n;
        for(ll i=n-1; i>=1; i--){
            if(seen[i]==1){
                continue;
            }

            ans-=min(i-ind[i], ind[prev]-ind[i]);
            for(ll j=ind[i]; j<ind[prev]; j++){
                seen[v[j]]=1;
            }
            prev=i;
        }

        cout<<ans<<endl;

    }
}