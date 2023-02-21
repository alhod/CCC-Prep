#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        bool onZeros=true;
        ll total = 0;

        for(auto i : v){
            if (i == 0){
                onZeros=true;
                continue;
            }

            if (i != 0){
                if (onZeros == true){
                    total++;
                    onZeros=false;
                }

                if (onZeros == false){
                    continue;
                }
            }
        }

        cout<<total<<endl;

    }

}