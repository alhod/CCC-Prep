#include<bits/stdc++.h>
#define ll long long

using namespace std; 


ll fib(ll n){
    vector<ll>tabTable(n+1);

    tabTable[0]=tabTable[1]=1;

    for(ll i=2; i<n+1; i++){
        tabTable[i]=tabTable[i-2]+tabTable[i-1];
    }
    return tabTable[n];
}

int main(){
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}




