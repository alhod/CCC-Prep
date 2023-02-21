#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        
        map<ll, vector<ll>>m;

        for(ll i=1; i<n+1; i++){
            ll inc=i;
            while(true){
                if(s[inc-1]=='0'){
                    m[inc].push_back(i);
                } else {
                    break;
                }
                inc+=i;
            }
        }

        ll cost = 0;
        for(ll i=1; i<n+1; i++){
            if(s[i-1]=='0'){
                cost+=m[i][0];
            }
        }
        cout<<cost<<endl;
    }
}