// Time complexity: O(klog(n))

// Fermat's Little Theorem states that if n is a prime number, then for every a, 1 < a < n-1
// a^(n-1)%n=1
// Thus, this algorithm chooses a random number a in the range and uses it to test the primality of n
// Note that we also use GCD cus why not I guess

// While the rule is true for all prime numbers, it is true for certain composite numbers (Carmichael numbers)
// That is why we increase the k-value to conduct the test many times for higher accuracy

// However, even with large values of k, the test may fail, thus this algorithm should be avoided.


#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll power(ll a, ll n, ll mod){
    a%=mod;
    ll ret=1;
    while(n){
        if(n%2!=0){
            ret=(ret*a)%mod;
            n--;
        } else {
            a=(a*a)%mod;
            n>>=1;
        }
    }
    return ret;
}


void solution(){
    ll n;
    cin>>n;

    if(n<=1||n==4){
        cout<<"NO"<<endl;
    } else if(n==2||n==3){
        cout<<"YES"<<endl;
    }

    ll k=3;  // higher the k-value more accurate
    while(k){

        ll a=2+rand()%(n-4);

        if(gcd(n, a)!=1){
            cout<<"NO"<<endl;
            return;
        }

        if(power(a, n-1, n)!=1){
            cout<<"NO"<<endl;
            return;
        }

        k--;
    }

    cout<<"YES"<<endl;
    return;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}