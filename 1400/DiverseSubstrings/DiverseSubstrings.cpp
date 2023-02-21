#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll count=0;
    for(ll i=0; i<n; i++){
        vector<ll>seen(10);
        ll maxSeen=0;
        ll numDistinct=0;
        for(ll j=i; j<n&&j<i+100; j++){
            if(seen[s[j]-48]==0){
                numDistinct++;
            }
            seen[s[j]-48]++;
            maxSeen=max(maxSeen, seen[s[j]-48]);
            if(maxSeen<=numDistinct){
                count++;
            }
        }
    }

    cout<<count<<endl;
    
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