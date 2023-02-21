#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>ans(n);
    ll i=0;
    ll f=0;
    for(; i<n-3; i++){
        ans[i]=i;
        f^=i;
    }
    if((f^i)==0){
        ans[i]=i+1;
    } else {
        ans[i]=i;
    }
    f^=ans[i];
    ans[i+1]=1<<30;
    ans[i+2]=ans[i+1]^f;
    for(auto &i:ans){cout<<i<<" ";}cout<<endl;

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