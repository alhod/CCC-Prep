// Time complexity: O(n)
// Space complexity: O(1)

// Wilson's Theorem states that a natural number n>1 is prime (n-1)! % n = (n-1) or (n-1)! % n = -1

#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll Factorial(ll n, ll mod){
    ll ret=1;
    for(ll i=n; i>1; i--){
        ret=(ret*i)%mod;
    }

    return ret;
}


bool WilsonsTheorem(ll n){
    if(n<=1){
        return false;
    }

    if(Factorial(n-1, n)==n-1){
        return true;
    } else {
        return false;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    cout<<WilsonsTheorem(n)<<endl;;
}