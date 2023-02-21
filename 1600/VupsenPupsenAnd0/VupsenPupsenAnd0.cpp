#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>ans(n);

    if(n%2==0){
        for(ll i=0; i<n/2; i++){
            ans[i]=v[n-i-1]*-1;
        }
        for(ll i=n/2; i<n; i++){
            ans[i]=v[n-i-1];
        }
    } else {
        for(ll i=1; i<n/2+1; i++){
            ans[i]=v[n-i-1+1]*-1;
        }
        for(ll i=n/2+1; i<n; i++){
            ans[i]=v[n-i-1+1];
        }
        
        if((ans[1]>0&&v[0]>0)||(ans[1]<0&&v[0]<0)){
            ans[1]+=v[0];
            ans[0]=v[1]*-1;
        } else {
            ans[1]-=v[0];
            ans[0]=v[1];
        }
        // ans[1]+=v[0];
        // ans[0]=v[1]*-1;
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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