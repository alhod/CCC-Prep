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

    ll greatest=v[0];
    vector<ll>ans(n+1, 1);
    ll ind=1;
    
    for(ll i=1; i<n; i++){

        if(v[i]>greatest){
            greatest=v[i];
        } else {
            ll copy=v[i];
            while(copy<greatest){
                if(ind>n){
                    break;
                }

                ans[ind]=i+1;
                copy+=ind;
                ind++;
            }
            greatest=v[i];
        }
    }

    // while(ind<=n){
    //     ans[ind]=1;
    //     ind++;
    // }

    for(ll i=1; i<=n; i++){
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