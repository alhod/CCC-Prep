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
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        ll tot=0;
        ll lessTwice=(2*v[0])-1;
        for(ll i=1; i<n; i++){
            if(v[i]>lessTwice){
                if(v[i]%lessTwice==0){
                    tot+=(v[i]-lessTwice)/lessTwice;
                } else {
                    tot+=(v[i]-lessTwice)/lessTwice+1;
                }
            }
        }
        cout<<tot<<endl;
    }
}