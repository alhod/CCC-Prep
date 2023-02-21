// The most common primality test is to iterate from 2 to sqrt(n)
// and to check if n is divisible by any of those numbers.

#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;

    if(n<=1){
        cout<<"NO"<<endl;
    } else if (n==2){
        cout<<"YES"<<endl;
    }

    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    return;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}