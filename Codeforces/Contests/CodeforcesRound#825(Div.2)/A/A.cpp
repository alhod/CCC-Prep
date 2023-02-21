#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }

    ll a1=0;
    ll b1=0;
    for(ll i=0; i<n; i++){
        if(a[i]==1){
            a1++;
        }
        if(b[i]==1){
            b1++;
        }
    }

    if(a1==b1){
        for(ll i=0; i<n; i++){
            if(a[i]!=b[i]){
                cout<<1<<endl;
                return 0;
            }
        }
        cout<<0<<endl;
        return 0;
    } else if(a1>b1){
        ll same=0;
        for(ll i=0; i<n; i++){
            if(a[i]==1&&b[i]==1){
                same++;
            }
        }
        if(same==b1){
            cout<<a1-b1<<endl;
            return 0;
        } else {
            cout<<a1-b1+1<<endl;
        }
    } else if(b1>a1){
        ll same=0;
        for(ll i=0; i<n; i++){
            if(a[i]==1&&b[i]==1){
                same++;
            }
        }
        if(same==a1){
            cout<<b1-a1<<endl;
            return 0;
        } else {
            cout<<b1-a1+1<<endl;
        }
    }
    return 0;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solution();
    }
}