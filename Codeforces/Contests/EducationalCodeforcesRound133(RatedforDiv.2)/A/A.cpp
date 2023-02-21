#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n==1){
            cout<<2<<endl;
            continue;
        }
        ll total = 0;
        while(n%3!=0){
            n-=2;
            total++;
            if(n==0){
                break;
            }
        }
        cout<<(n/3)+total<<endl;
    }
}