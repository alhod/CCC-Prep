#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    if(n==3){
        cout<<"NO"<<endl;
        return;
    }


    vector<ll>ans(n);
    if(n%2==0){
        for(ll i=0; i<n; i++){
            if(i%2==0){
                ans[i]=-1;
            } else {
                ans[i]=1;
            }
        }
    } else {
        for(ll i=0; i<n; i++){
            if(i%2==0){
                ans[i]=-1*(n/2-1);
            } else {
                ans[i]=n/2;
            }
        }
    }

    cout<<"YES"<<endl;
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