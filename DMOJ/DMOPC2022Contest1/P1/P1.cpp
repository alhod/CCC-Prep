#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        bool imp = false;
        ll inc=-1;
        ll dec=-1;
        for(ll i=1; i<n; i++){
            if(v[i-1]==0||v[i]==0){
                continue;
            }
            if(v[i-1]==v[i]){
                imp = true;
                break;
            }
            if(v[i-1]<v[i]){
                if(inc==-1){
                    if(i%2==0){
                        inc=0;
                        dec=1;
                    } else {
                        inc=1;
                        dec=0;
                    }
                    continue;
                }
                if(i%2==0){
                    if(inc==0){
                        continue;
                    } else {
                        imp = true;
                        break;
                    }
                } else if(i%2!=0){
                    if(inc==1){ 
                        continue;
                    } else {
                        imp = true;
                        break;
                    }
                }
            } else if(v[i-1]>v[i]){
                if(dec==-1){
                    if(i%2==0){
                        dec=0;
                        inc=1;
                    } else{
                        inc=0;
                        dec=1;
                    }
                    continue;
                }
                if(i%2==0){
                    if(dec==0){
                        continue;
                    } else {
                        imp = true;
                        break;
                    }
                } else if(i%2!=0){
                    if(dec==1){
                        continue;
                    } else {
                        imp = true;
                        break;
                    }
                }
            }

        }
        cout<<(imp==true?"NO":"YES")<<endl;
    }
}