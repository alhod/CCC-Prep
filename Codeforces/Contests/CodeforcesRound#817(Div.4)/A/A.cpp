#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string word;
        cin>>word;
        if(n!=5){
            cout<<"NO"<<endl;
            continue;
        }
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            v[i]=word[i];
        }
        string timur = "Timur";
        bool imp = false;
        for(ll i=0; i<n; i++){
            if(count(v.begin(), v.end(), timur[i]) !=1){
                imp = true;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(imp==false){
            cout<<"YES"<<endl;
        }
    }

}