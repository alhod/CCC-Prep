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



    ll odd=0;
    ll even=0;
    ll ans=0;
    for(ll i=0; i<n; i++){
        if(odd>0){
            if(v[i]%2==1){
                odd++;
            } else {
                ans+=odd-1;
                odd=0;   
                even++;
            }
        } else if(even>0){
            if(v[i]%2==0){
                even++;
            } else {
                ans+=even-1;
                even=0;
                odd++;
            }
        } else {
            if(v[i]%2==1){
                odd++;
            } else {
                even++;
            }
        }
    }

    if(odd>0){
        ans+=odd-1;
    } else {
        ans+=even-1;
    }

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