#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll ans=n*(n+1)/2;
    for(ll i=0; i<n-1; i++){
        ans+=(v[i]!=v[i+1])*(i+1)*(n-i-1);
    }

    while(m--){
        ll i, x;
        cin>>i>>x;
        i--;
        if(i&&v[i]!=v[i-1]){
            ans-=i*(n-i);
        }
        if(i<n-1&&v[i]!=v[i+1]){
            ans-=(i+1)*(n-i-1);
        }
        if(i&&x!=v[i-1]){
            ans+=i*(n-i);
        }
        if(i<n-1&&x!=v[i+1]){
            ans+=(i+1)*(n-i-1);
        }
        cout<<ans<<endl;
        v[i]=x;
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}