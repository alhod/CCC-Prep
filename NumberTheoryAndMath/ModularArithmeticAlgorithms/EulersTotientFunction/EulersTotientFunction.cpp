// Time Complexity: O(sqrt(n)log(n))
// Space Complexity: O(1)

// Euler's Totient Function Φ(n) (phi) counts the number of numbers 
// 1...n-1 that are co-prime/relatively prime from n. (i.e. counts all 
// 1<=x<=n-1 such that gcd(n, x)==1.)


#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll phi(ll n){

    double result=n;

    for(ll p=2; p*p<=n; p++){
        if(n%p==0){
            while(n%p==0){
                n/=p;
            }
            result*=(1.0-(1.0/(float)p));
        }
    }

    if(n>1){
        result=n-1;
    }

    return (ll)result;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    cout<<phi(n)<<endl;
}