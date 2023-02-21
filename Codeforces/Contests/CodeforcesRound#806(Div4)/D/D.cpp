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
            bool found = false;
            for(ll j=0; j<n; j++){ 
                if(found==true){
                    break;
                }
                if(mismatch(v[j].begin(), v[j].end(), v[i].begin(), v[i].end()).first==v[j].end()){
			    }
                if(v[i].rfind(v[j], 0)==true){
                    cout<<"found "<<v[j]<<" in "<<v[i]<<endl;
                    for(ll x=0; x<n; x++){
                        if((v[i].rfind(v[x], v[j].length()))==true){
                            cout<<"found "<<v[j]<<" and "<<v[x]<<" in "<<v[i]<<endl;
                            ans[i]=1;
                            found = false;
                            break;
                        }
                    }
                }
            }
            // for(ll j=0; j<v[i].length(); j++){
            //     string left = v[i].substr(0, j);
            //     string right = v[i].substr(j);
            //     bool found = false;
            //     for(auto a:v){
            //         if(found==true){
            //             break;
            //         }
            //         if(a==left){
            //             for(auto b:v){
            //                 if(b==right){
            //                     ans[i]=1;
            //                     found = true;
            //                     break;
            //                 }
            //             }
            //         }
            //     }
            // }
        }
        for(auto i:ans){
            cout<<i;
        }
        cout<<endl;

    }
}