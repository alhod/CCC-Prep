#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    ll alice_white=0;
    ll alice_black=0;
    ll bob_white=0;
    ll bob_black=0;

    for(ll i=0; n>0; i++){
        ll to_add=min(1+i*4, n);
        n-=to_add;
        if(i%2==0){
            // cout<<"to_add: "<<to_add<<endl;
            alice_white+=to_add-to_add/2;
            alice_black+=to_add/2;
        } else {
            // cout<<"to_add2: "<<to_add<<endl;
            bob_black+=to_add-to_add/2;
            bob_white+=to_add/2;
        }
    }
    
    printf("%d %d %d %d\n", alice_white, alice_black, bob_white, bob_black);
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