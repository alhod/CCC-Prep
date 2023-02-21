// Time complexity: O(sqrt(n))  **Technically time complexity is lower than simple Sieve, they do same number of operations**
// Space complexity: O(1)  **Better than Simple Sieve**

// Only difference between Sieve of Eratosthenes and Segmented Sieve is that
// the ladder has better space complexity.

// Segmented Sieve, instead of storing an array a of size n at which a[i] is true if i is prime,
// stores an array containing all prime numbers up until n.

// Same time complexity but better space complexity for larger values of n.



#include<bits/stdc++.h>
#define ll long long
using namespace std;



void simpleSieve(ll limit, vector<ll>&primes){
    
    vector<bool>mark(limit+1, true);

    for(ll i=2; i*i<limit; i++){
        if(mark[i]==false){
            continue;
        }

        for(ll j=i*i; j<limit; j+=i){
            mark[j]=false;
        }
    }

    for(ll i=2; i<limit; i++){
        if(mark[i]==true){
            primes.push_back(i);
        }
    }
}

void solution(){
    
    ll n;
    cin>>n;

    ll limit=floor(sqrt(n))+1;
    vector<ll>primes;
    primes.reserve(limit);
    simpleSieve(limit, primes);

    ll low=limit;
    ll high=limit*2;


    for(auto i:primes){
        cout<<i<<" ";
    }


    while(low<n){

        if(high>=n){
            high=n;
        }

        bool mark[limit+1];
        memset(mark, true, sizeof(mark)); 
        for(ll aPrime:primes){
            ll lowLim=floor(low/aPrime)*aPrime;
            if(lowLim<low){
                lowLim+=aPrime;
            }

            for(ll i=lowLim; i<high; i+=aPrime){
                mark[i-low]=false;
            }
        }

        for(ll i=low; i<high; i++){
            if(mark[i-low]==true){
                cout<<i<<" ";
            }
        }

        low+=limit;
        high+=limit;
    }
    cout<<endl;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}