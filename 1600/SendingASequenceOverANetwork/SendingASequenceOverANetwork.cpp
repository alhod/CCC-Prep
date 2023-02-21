#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++){
        cin>>v[i];
    }

    if(n==1){
        cout<<"NO"<<endl;
        return;
    }

    vector<bool>dp(n+1, false);
    dp[0]=true;

    for(ll i=1; i<=n; i++){
        if(i-v[i]-1>=0&&dp[i-v[i]-1]){
            dp[i]=true;
        }
        if(i+v[i]<=n&&dp[i-1]){
            dp[i+v[i]]=true;
        }
    }

    cout<<(dp[n]?"YES":"NO")<<endl;

    

    
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