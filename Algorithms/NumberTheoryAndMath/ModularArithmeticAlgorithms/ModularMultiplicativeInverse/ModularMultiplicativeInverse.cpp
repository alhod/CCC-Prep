// Time Complexity: O(log(m))
// Space Complexity: O(1)

// Modular Multiplicative Inverse is an integer x such that A*x=1 (mod M).
// Useful when dealing with division under modulus.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll ModularMultiplicativeInverse(ll a, ll m){
    
    ll m0=m;
    ll y=0, x=1;

    if(m==1){
        return 0;
    }

    while(a>1){
        ll q=a/m;
        ll t=m;

        m=a%m, a=t;
        t=y;

        y=x-q*y;
        x=t;
    }

    if(x<0){
        x+=m0;
    }

    return x;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, m;
    cin>>a>>m;
    cout<<ModularMultiplicativeInverse(a, m)<<endl;
}