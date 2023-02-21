#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n = rand()%5;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            v[i] = rand();
        }

        cout<<n<<endl;
        for(ll i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

    }

}