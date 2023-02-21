#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll greatest=0;
    ll smallest=1e18;

    for(ll i=0; i<n; i++){
        greatest=max(greatest, v[i]);
        smallest=min(smallest, v[i]);
    }

    ll maxAbs=abs(greatest-smallest);

    vector<ll>count(200010);
    for(ll i=0; i<n; i++){
        count[v[i]]++;
    }

    ll ans=0;
    for(ll i=0; i<n; i++){
        ll com1=v[i]-maxAbs;
        ll com2=v[i]+maxAbs;
        if(com1>=0){
            ans+=count[com1];
            if(com1==v[i]){
                ans--;
            }
        }
        if(com1!=com2){
            ans+=count[com2];
            if(com2==v[i]){
                ans--;
            }
        }
        
    }

    cout<<ans<<endl;
    
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