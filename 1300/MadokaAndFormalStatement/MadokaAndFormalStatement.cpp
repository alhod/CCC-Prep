#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        vector<ll>b(n);
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }
        for(ll i=0; i<n; i++){
            cin>>b[i];
        }

        bool bad = false;
        for(ll i=0; i<n; i++){
            if(a[i]>b[i]){
                bad=true;
                break;
            }
            if(a[i]==b[i]){
                continue;
            }
            if(a[i]<b[i]){
                if(i==n-1){
                    if(b[i]>b[0]+1){
                        bad=true;
                        break;
                    }
                } else {
                    if(b[i]>b[i+1]+1){
                        bad=true;
                        break;
                    }
                }
            }
        }

        if(bad==true){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }
    }
}