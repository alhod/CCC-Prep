#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n%2!=0){cout<<-1<<endl;continue;}
        cout<<n/2<<" "<<n/2<<" "<<0<<endl;
    }
}