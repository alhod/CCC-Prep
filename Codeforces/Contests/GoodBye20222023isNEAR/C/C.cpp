#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(v[i]==v[j]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }


    ll numEven=0;
    ll numOdd=0;
    for(ll i=0; i<n; i++){
        if(v[i]%2==0){
            numEven++;
        } else {
            numOdd++;
        }
    }

    if(numEven>=2&&numOdd>=2){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
    
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