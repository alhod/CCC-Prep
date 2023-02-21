#include<bits/stdc++.h>
#define ll long long
using namespace std;

int check_prime(ll n){
    if(n%2==0){return 0;}
    else{return 1;}
}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>primes;
        vector<ll>ret(n);
        for(ll i=1; i<=n;i++){
            if (check_prime(i)==1){
                primes.push_back(i);
            }
        }

        // for(auto i:primes){cout<<"aprime: "<<i<<endl;}

        ll ind=0;
        for(ll i:primes){
            while(i<=n){
                // cout<<"i "<<i<<endl;
                ret[ind]=i;
                ind++;
                i*=2;
                // cout<<"potential i: "<<i<<endl;
            }
        }
        cout<<2<<endl;
        for(ll i:ret){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}