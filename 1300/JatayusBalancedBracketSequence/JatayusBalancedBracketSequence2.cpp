#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        n*=2;
        string s;
        cin>>s;
        ll depth=0;
        ll runningDepth=0;
        ll ans=n/2;
        for(ll i=0; i<n; i++){
            if(s[i]=='('){
                depth++;
                if(depth<=runningDepth){
                    ans--;
                }
                runningDepth=depth;
            } else {
                depth--;
            }
        }
        cout<<ans<<endl;
    }
}