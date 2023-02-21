#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>d(n);
        for(ll i=0; i<n; i++){
            cin>>d[i];
        }
        bool mult=false;
        vector<ll>a(n);
        for(ll i=0; i<n; i++){
            if(i==0){
                a[i]=d[i];
            } else if(-1*(d[i]-a[i-1])!=d[i]+a[i-1]&&-1*(d[i]-a[i-1])>=0){
                mult=true;
                break;
            } else {
                a[i]=d[i]+a[i-1];
            }
        }
        if(mult==true){
            cout<<-1<<endl;
            continue;
        }
        for(auto i:a){
            cout<<i<<" ";
        }
        cout<<endl;

    }
}