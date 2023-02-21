#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
           cin>>v[i]; 
        }
        ll hasDecrease = false;
        ll imp = false;
        for(ll i=1; i<n; i++){
            if(v[i]<v[i-1]){
                hasDecrease=true;
            } else if (v[i]>v[i-1]){
                if(hasDecrease==true){
                    imp = true;
                    break;
                }
            }
        }
        if(imp==true){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
}