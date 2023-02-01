// Time Complexity: O(log(y))  (y is the exponent)
// Space Complexity: O(1)

// Modular Exponentiation is x to the exponent y under modulus p.



#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll ModularExponentiation(ll x, ll y, ll p){
    x%=p;
    if(x==0){
        return 0;
    }

    ll res=1;

    while(y>0){
        if(y & 1){
            y--;
            res=(res*x)%p;
        }

        y>>=1;
        x=(x*x)%p;
    }

    return res;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll x, y, p;
    cin>>x>>y>>p;
    cout<<ModularExponentiation(x, y, p)<<endl;
}