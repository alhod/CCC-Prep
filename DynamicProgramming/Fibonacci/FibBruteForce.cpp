#include<bits/stdc++.h>
#define ll long long

using namespace std; 

ll fib(ll n){
    if(n<=1){  // base case
        return 1;
    }

    return fib(n-2)+fib(n-1);  
    // return the sum of the n-2 and n-1th numbers
}

int main(){
    ll n;
    cin>>n;
    cout<<fib(n)<<endl;
}


