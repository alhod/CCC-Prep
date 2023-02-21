#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        vector<ll>v1(n);
        vector<ll>v2(n);
        map<ll, ll>m;
        map<ll, ll>m1;
        map<ll, bool>seen;
        map<ll, bool>seen1;
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        for(ll i=0; i<n; i++){
            if(i==0){
                v1[i]=v[i];
                m[v1[i]]=i;
                seen[v1[i]]=true;
            } else {
                v1[i]=v1[i-1]+v[i];
                m[v1[i]]=i;
                seen[v1[i]]=true;
            }
        }
        for(ll i=n-1; i>=0; i--){
            if(i==n-1){
                v2[i]=v[i];
                m1[v2[i]]=i;
                seen1[v2[i]]=true;
            } else {
                v2[i]=v2[i+1]+v[i];
                m1[v2[i]]=i;
                seen1[v2[i]]=true;
            }
        }

        ll best=0;
        for(ll i=0; i<n; i++){
            if(seen1[v1[i]]&&m[v1[i]]<m1[v1[i]]){
                best=max(best, m[v1[i]]+1+(n-m1[v1[i]]));
            }
        }

        cout<<best<<endl;

        

    }
}