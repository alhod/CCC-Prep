#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==3){
            cout<<-1<<endl;
            continue;
        }

        if(n%2==0){
            for(ll i=n; i>=1; i--){
                cout<<i<<" ";
            }
            cout<<endl;
        } else {
            for(ll i=n; i>n/2+1; i--){
                cout<<i<<" ";
            }
            for(ll i=1; i<=n/2+1; i++){
                cout<<i<<" ";
            }
            cout<<endl;

        }
    }
}