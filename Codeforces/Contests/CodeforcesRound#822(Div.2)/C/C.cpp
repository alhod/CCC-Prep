#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, bool>m;

ll checkMultiples(ll n){
    ll currBest=n;
    for(ll i=1; i<n; i++){
        if(n%i==0){
            if(m[i]==1){
                return i;
            }
        }
    }
    return currBest;
}

ll turnOffMultiples(ll n){
    for(ll i=n-1; i>0; i--){
        if(n%i==0){
            m[i]=0;
        }
    }
    return 0;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        
        ll op=0;
        for(ll i=0; i<n; i++){
            if(s[i]=='1'){
                turnOffMultiples(i+1);
            } else {
                op+=checkMultiples(i+1);
                m[i+1]=1;
            }
        }
        cout<<op<<endl;
        m.clear();
    }
}