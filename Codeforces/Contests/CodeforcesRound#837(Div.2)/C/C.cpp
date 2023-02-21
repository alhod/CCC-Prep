#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAX 1000000001

int arr[MAX];

void sieve()
{
    arr[1]=1;
    for (int i=2; i<MAX; i++){
        arr[i]=i;
    }
    for (int i=4; i<MAX; i+=2){
        arr[i]=2;
    }
 
    for (int i=3; i*i<MAX; i++){
        if (arr[i]==i){
            for (int j=i*i; j<MAX; j+=i){
                if (arr[j]==j){
                    arr[j]=i;
                }
            }
        }
    }
}


set<ll> primeFactor(ll x) {
    set<ll> ret;
    while (x != 1) {
        ret.insert(arr[x]);
        x = x / arr[x];
    }
    return ret;
}

// map<ll, vector<ll>>memo;
// map<ll, bool>solved;

// void computePrimeFactors(ll n, set<ll>&primeFactors) {

//     if(solved[n]==true){
//         for(auto j:memo[n]){
//             primeFactors.insert(j);
//         }
//         return;
//     }

//     solved[n]=true;

//     for(ll i=2; i<sqrt(n); i++){
//         if(n%i==0){
//             primeFactors.insert(i);
//             if(solved[n/i]==true){
//                 for(auto j:memo[n/i]){
//                     primeFactors.insert(j);
//                 }
//                 return;
//             } else {
//                 computePrimeFactors(n/i, primeFactors);
//             }
            
//         }
//     }
// }


int solution(){
    ll n;
    cin>>n;
    sieve();
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>seenFactors(100000);
    for(ll i=0; i<n; i++){
        set<ll>primes=primeFactor(v[i]);

        for(auto aPrime:primes){
            if(seenFactors[aPrime]==1){
                cout<<"YES"<<endl;
                return 0;
            }
            seenFactors[aPrime]=1;
        }
    }
    cout<<"NO"<<endl;
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}