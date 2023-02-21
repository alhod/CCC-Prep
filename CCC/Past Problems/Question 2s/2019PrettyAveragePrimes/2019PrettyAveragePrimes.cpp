#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool is_prime(ll n){

    if(n<=1){
        return false;
    } else if (n==2){
        return true;
    }

    for(ll i=2; i<=sqrt(n); i++){
        if(n%i==0){
            
            return false;
        }
    }

    
    return true;
}


void solution(){
    ll n;
    cin>>n;

    ll a=n, b=n;
    while(true){
        if(is_prime(a)&&is_prime(b)){
            break;
        }

        a--;
        b++;
    }

    printf("%d %d\n", a, b);


    // ll copy=n;
    // bool is_first=false;

    // ll nth;
    // ll count=0;

    // while(true){
    //     if(copy%((ll)sqrt(copy))==0){
    //         nth=(sqrt(copy)-2)*2; 
    //         break;
    //     } else {
    //         if(!is_first&&is_prime(copy)){
    //             is_first=true;
    //         }
    //         count++;
    //     }
    // }

    // ll a, b;
    // if(is_first){
    //     nth--;
    //     a=n-2*nth;
    //     b=n+2*nth;
    // } else {
    //     a=n-2*nth;
    //     b=n+2*nth;
    // }

    // printf("%d %d\n", a, b);
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