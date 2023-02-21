#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, x;
    cin>>n>>x;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll init=0;
    for(ll i=0; i<n-1; i++){
        init+=abs(v[i]-v[i+1]);
    }

    ll best=1e18, min1=1e18;

    for(ll _=0; _<2; _++){
        min1=min(min1, abs(v[0]-1));
        for(ll i=0; i<n+1; i++){
            if(i==0){
                best=min(best, init+min1+abs(v[i]-x));
                best=min(best, init+abs(v[i]-x)+x-1);
                min1=min(min1, abs(v[i]-1));
            } else if(i==n){
                best=min(best, init+min1+abs(v[i-1]-x));
                best=min(best, init+abs(v[i-1]-1)+x-1);
                min1=min(min1, abs(v[i-1]-1));
            } else {
                best=min(best, init-abs(v[i-1]-v[i])+min1+abs(v[i-1]-x)+abs(v[i]-x));
                best=min(best, init-abs(v[i-1]-v[i])+abs(v[i-1]-1)+abs(v[i]-x)+x-1);
                min1=min(min1, -abs(v[i-1]-v[i])+abs(v[i-1]-1)+abs(v[i]-1));
            }
        }

        reverse(v.begin(), v.end());
    }

    cout<<best<<endl;

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }

    return 0;
}