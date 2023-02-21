#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    v[0]=1;
    for(ll i=1; i<n; i++){
        v[i]=n-i+1;
    }
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
    
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