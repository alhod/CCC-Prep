#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        vector<vector<ll>>v(n);
        for(ll i=0; i<n; i++){
            v[i]=vector<ll>(i+1);
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<i+1; j++){
                if(j==0||j==v[i].size()-1){
                    v[i][j]=1;
                }
            }
        }
        for(auto i:v){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
}