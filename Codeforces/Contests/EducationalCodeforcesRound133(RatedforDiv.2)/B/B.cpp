#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            v[i]=i+1;
        }
        cout<<n<<endl;
        for(auto j:v){
            cout<<j<<" ";
        }
        cout<<endl;
        for(ll i=0; i<n-1; i++){
            swap(v[i], v[i+1]);
            for(auto j:v){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        
    }
}