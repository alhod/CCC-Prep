// Time complexity O(nlog(log(n)))
// Best used for n around 10^7

// Generates all prime numbers up to n

// Maintains array, in which arr[i]=true if i is prime
// Iterates from 2 to sqrt(n)
//      If arr[i]==false (i.e. i is composite)
//          continue;
//      Iterates (j) from i*i, increment i, up until n (i.e. all multiples of i starting from i^2)
//          ** Note that all composites < i^2 and are multiples of i have been marked up until this point **
//          sets primes[j]=true


#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;

    ll primes[n+1];
    memset(primes, 0ll, sizeof(primes));  // note that static array is not initialized with 0s automatically

    for(ll i=2; i*i<n+1; i++){
        if(primes[i]==1){
            continue;
        }

        for(ll j=i*i; j<n+1; j+=i){
            primes[j]=1;
        }
    }

    for(ll i=2; i<n+1; i++){
        if(primes[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}