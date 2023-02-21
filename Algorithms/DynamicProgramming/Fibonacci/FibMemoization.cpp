// IMPORTANT NOTE:
// the "long long" type, or "__int64", can store up to 2^64,
// or roughly 19 digits. The program won't function for
// values of n too great.

#include<bits/stdc++.h>
#define ll long long

using namespace std; 


ll fib(ll n, map<ll, ll>*memoTable){
    if(n<=1){  // base case
        return 1;
    }
    if((*memoTable)[n]!=0){
        // check if nth fibonacci number already on memoTable
        return (*memoTable)[n];
    }
    return (*memoTable)[n]=fib(n-2, memoTable)+fib(n-1, memoTable);  
    // record value on memoTable and return
}

int main(){
    ll n;
    cin>>n;
    map<ll, ll>memoTable;
    for(ll i=1; i<n+1; i++){
        cout<<fib(i, &memoTable)<<endl;
    }
}



