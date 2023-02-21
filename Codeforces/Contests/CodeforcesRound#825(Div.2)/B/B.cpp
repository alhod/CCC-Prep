#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    // if(n<=2){
    //     cout<<"YES"<<endl;
    //     return 0;
    // }
    vector<ll>a(n+1);
    for(ll i=0; i<n; i++){
        if(i==0){
            a[i]=v[i];
        }

        if(i==n-1){
            a[i+1]=v[i];
        } else {
            a[i+1]=lcm<ll, ll>(v[i], v[i+1]);
        }
        if(gcd<ll, ll>(a[i], a[i+1])!=v[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    // for(ll i=2; i<n; i++){
    //     if((v[i-2]%v[i]==0||v[i]%v[i-2]==0)&&v[i-1]<v[i]){
    //         cout<<"NO"<<endl;
    //         return 0;
    //     }
    // }
    cout<<"YES"<<endl;
    return 0;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solution();    
    }
}