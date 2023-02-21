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
        
        vector<ll>m(n+1);

        for(ll i=n; i>0; i--){
            ll inc=i;
            while(true){
                if(inc>n){
                    break;
                }
                if(s[inc-1]=='0'){
                    m[inc]=i;
                } else {
                    break;
                }
                inc+=i;
            }
        }

        ll cost = 0;
        for(ll i=0; i<n; i++){
            if(s[i]=='0'){
                cost+=m[i+1];
            }
        }
        cout<<cost<<endl;
    }
}