#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)cin>>v[i];
        if(n%2!=0){
            cout<<"NO"<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        bool imp=false;
        for(ll i=1;i<n/2;i++){
            if(v[i]==v[i+n/2-1]){
                cout<<"NO"<<endl;
                imp = true;
                break;
            }
        }
        if(imp==true)continue;
        cout<<"YES"<<endl;
        for(ll i=0;i<n/2;i++){
            cout<<v[i]<<" "<<v[i+n/2]<<" ";
        }
        cout<<endl;
    }
}