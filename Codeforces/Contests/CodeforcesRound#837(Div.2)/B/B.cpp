#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m;
    cin>>n>>m;
    vector<ll>v(n);
    map<ll, vector<ll>>memo;
    
    for(ll i=0; i<n; i++){
        v[i]=i+1;
    }

    for(ll i=0; i<m; i++){
        ll x, y;
        cin>>x>>y;
        memo[x].push_back(y);
        memo[y].push_back(x);
    }

    ll p1=1;
    ll p2=2;
    ll ans=1;
    while(p2<=n){
        ans++;
        for(auto notFriend:memo[p2]){
            while(p1<=notFriend&&notFriend<p2){
                p1++;
            }
        }
        ans+=p2-p1;
        p2++;
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