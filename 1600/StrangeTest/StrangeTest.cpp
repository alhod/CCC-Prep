#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll a, b;
    cin>>a>>b;

    ll best=b-a;

    for(ll a_prime=a; a_prime<b; a_prime++){
        ll b_prime=0;
        for(ll i=21; i>=0; i--){
            if(b&(1<<i)){
                b_prime|=(1<<i);
            } else {
                if(a_prime&(1<<i)){
                    b_prime|=(1<<i);
                    break;
                }
            }
        }

        best=min(best, a_prime+(a_prime|b_prime)+1-a-b);
    }

    cout<<best<<endl;
    
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