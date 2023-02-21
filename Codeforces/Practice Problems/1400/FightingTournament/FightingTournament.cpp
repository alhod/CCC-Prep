#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    for(ll i=0; i<n; i++){
        ll num;
        cin>>num;
    }
    while(q--){
        ll ind, k;
        cin>>ind>>k;
        if(k<=n){
            cout<<n-((n-1-(ind-1)+k)%n)<<endl;
        } else {
            if(ind==n){
                cout<<1<<endl;
            }
            k-=n-1;
            k%=n-1;
            cout<<n-(((n-ind-1)+k)%n)<<endl;
        }
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