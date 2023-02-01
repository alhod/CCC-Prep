// Time Complexity: O(N*log(n))
// Space Complexity: O(1)

// Question:
//      Given an array of numbers (num) and remainders (rem) of size k, such that every pair is coprime
//      (gcd for every pair is 1), find the minimum positive number x such that x % num[i]=rem[i] for all
//      0<=i<=k-1.

// Chinese Remainder Theorem:
//      Chinese Remainder Theorem (CRT) states that there always exists an x that satisfies the given
//      congruences. Furthermore, all solutions x of this system are congruent modulo the product, 
//      prod=num[0]*num[1]*...*num[k-1]. (i.e. all solutions x, modulo the product of all numbers, 
//      are congruent. Also means all solutions x are in the form: x + m*prod for m>=0.)

// Formula:
//      x=(summation(rem[i]*pp[i]*inv[i]))%prod, for all 0<=i<=n-1
//      Where:
//          rem[i] is given array of remainders
//          prod is the product of all numbers (prod=num[0]*num[1]*...*num[n-1])
//          pp[i] is product of all divided by num[i] (pp[i]=prod/num[i])
//          inv[i] is the Modular Multiplicative Inverse of pp[i] with respect to num[i] (pp[i] modulo num[i])


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


ll ChineseRemainderTheorem(vector<ll>&num, vector<ll>&rem){
    ll n=num.size();
    ll ret=0;
    ll prod=1;
    for(ll i=0; i<n; i++){
        prod*=num[i];
    }

    for(ll i=0; i<n; i++){
        ll pp=prod/num[i];
        ret+=rem[i]*pp*ModularMultiplicativeInverse(pp, num[i]);
    }
    
    ret%=prod;

    return ret;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll>num(n);
    vector<ll>rem(n);
    for(ll i=0; i<n; i++){
        cin>>num[i];
    }
    for(ll i=0; i<n; i++){
        cin>>rem[i];
    }
    cout<<ChineseRemainderTheorem(num, rem)<<endl;
}