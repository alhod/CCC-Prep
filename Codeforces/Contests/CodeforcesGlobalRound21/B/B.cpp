#include <bits/stdc++.h>
#include <algorithm>
#define ll long long

using namespace std;

int main(){

    ll t; scanf("%d", &t);
    while(t--){
        ll n; scanf("%d", &n);
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        int total=0;
        for(ll i=0; i<n; i++){
            if(v[i]!=0 and i==0){
                total++;
                continue;
            }
            if(v[i]!=0 and v[i-1]==0){
                total++;
                continue;
            }
        }
        printf("%d\n", min({total, 2}));

    }

}