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
        vector<ll>a(n);
        for(ll i=0; i<n; i++){
            if(i==0){
                a[i]=1;
                continue;
            }
            ll maxTake=v[i]-1;
            a[i]=1+min(a[i-1], maxTake);
        }
        ll tot=0;
        for(ll i=0; i<n; i++){
            tot+=a[i];
        }
        cout<<tot<<endl;
    }
}