#include<bits/stdc++.h>
#define ll long long

using namespace std; 


ll fib(ll n){
    vector<ll>tabTable(n+1);

    tabTable[1]=tabTable[2]=1;

    for(ll i=3; i<n+1; i++){
        tabTable[i]=(tabTable[i-2]+tabTable[i-1])%(ll)1e8;
    }
    return tabTable[n];
}

int main(){
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}