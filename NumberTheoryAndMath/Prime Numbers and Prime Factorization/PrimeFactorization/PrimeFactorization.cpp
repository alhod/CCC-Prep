// Time complexity: O(sqrt(n))
// Space complexity: idk O(sqrt(n))? the number of prime factors

// Combination of two approaches from GeeksforGeeks

// Prime factorization of n only needs to consider factors up until sqrt(n)
// If n is prime (or composed of large prime) then "if(n>1)" will catch it and include it


#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> PrimeFactorization(ll n){
    ll fact=2;

    vector<ll>ret;

    if(n<=1){
        return ret;
    } else if(n<=3){
        return {n};
    }

    while(true){
        if(fact>sqrt(n)){
            break;
        } else if(n%fact==0){
            while(n%fact==0){
                n/=fact;
                ret.push_back(fact);
            }
        }
        fact++;
    }

    if(n>1){
        ret.push_back(n);
    }

    return ret;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin>>n;
    vector<ll>ans=PrimeFactorization(n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}