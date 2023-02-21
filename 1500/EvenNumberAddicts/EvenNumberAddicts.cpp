#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    ll numEven=0;
    ll numOdd=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        if(x%2==0){
            numEven++;
        } else {
            numOdd++;
        }
    }

    if(numOdd%4==2){
        cout<<"Bob"<<endl;
    } else if(numOdd%4==3){
        cout<<"Alice"<<endl;
    } else if(numOdd%4==0){
        cout<<"Alice"<<endl;
    } else if(numOdd%4==1){
        cout<<(numEven%2==1?"Alice":"Bob")<<endl;
    }
    
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