#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<string>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        vector<ll>ans(n);
        
        for(ll i=0; i<n; i++){
            for(ll j=0; j<v[i].length(); j++){
                if(v[j].length()>v[i].length()){continue;}
                string left = v[i].substr(0, j);
                string right = v[i].substr(j);
                bool found = false;
                for(auto a:v){
                    if(found==true){
                        break;
                    }
                    if(a==left){
                        for(auto b:v){
                            if(b==right){
                                ans[i]=1;
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for(auto i:ans){
            cout<<i;
        }
        cout<<endl;

    }
}