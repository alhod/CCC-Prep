#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        if(n<=2&&m<=2){
            cout<<1<<" "<<1<<endl;
        } else if(n<=1||m<=1){
            cout<<1<<" "<<1<<endl;
        } else if(n==2&&m==3){
            cout<<1<<" "<<2<<endl;
        } else if(n==3&&m==2){
            cout<<2<<" "<<1<<endl;
        } else if(n==3&&m==3){
            cout<<2<<" "<<2<<endl;
        } else {
            cout<<1<<" "<<1<<endl;
        }
    }
}