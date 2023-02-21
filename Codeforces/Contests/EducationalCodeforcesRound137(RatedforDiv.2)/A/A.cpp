#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    n=10-n;

    if(n<=1){
        cout<<0<<endl;
        return 0;
    }

    ll sum=0;
    while(n>0){
        sum+=n-1;
        n--;
    }

    cout<<sum*6<<endl;

    
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