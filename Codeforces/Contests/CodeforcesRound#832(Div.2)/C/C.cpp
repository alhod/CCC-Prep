#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll smallest=1e18;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    for(ll i=0; i<n; i++){
        smallest=min(smallest, v[i]);
    }

    if(smallest==v[0]){ 
        if(smallest%2==0){
            cout<<"Bob"<<endl;
        } else {
            cout<<"Bob"<<endl;
        }
    } else {
        if(smallest%2==0){
            cout<<"Alice"<<endl;
        } else {
            cout<<"Alice"<<endl;
        }
    }
    
    return 0;
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