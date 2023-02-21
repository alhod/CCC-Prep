#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        
        bool imp = false;

        // case n>3
        if(n>3){
            for(ll i=0; i<n; i++){
                if(v[i] != 0){
                    imp = true;
                    break;
                }
            }
        }

        // case n == 3
        ll total=0;
        if(n==3){
            for(ll i=0; i<n; i++){
                total+=v[i];
            }
            if (find(v.begin(), v.end(), total)==v.end()){
                imp=true;
            }
        }

        if(imp==true){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;




    }

}