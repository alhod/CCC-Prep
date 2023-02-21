#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    ll alice=0;
    ll bob=0;

    for(ll i=0; n>0; i++){
        if(i%2==0){
            alice+=min(1+i*4, n);
            n-=min(1+i*4, n);
        } else {
            bob+=min(1+i*4, n);
            n-=min(1+i*4, n);
        }
    }
    
    cout<<alice<<" "<<bob<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}