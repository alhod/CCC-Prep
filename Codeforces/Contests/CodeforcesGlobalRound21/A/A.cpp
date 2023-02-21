#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n, z;
        cin>>n>>z;
        ll best = 0;
        for(ll i=0; i<n; i++){
            ll tmp;
            cin>>tmp;
            ll tmp2 = tmp|z;
            if (tmp2 > best){
                best=tmp2;
            }
        }    

        cout<<best<<endl;

    }

}