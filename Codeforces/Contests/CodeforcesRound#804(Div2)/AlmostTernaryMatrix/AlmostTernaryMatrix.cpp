#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n; ll m;
        cin>>n>>m;
        string s1="10";
        string s2="01";
        for(ll i=1;i<m;i++){
            if(i%2!=0){
                s1+="01";
                s2+="10";
            } else{
                s1+="10";
                s2+="01";
            }
        }
        vector<string>v(n);
        for(ll i=0;i<(n/2);i++){
            if(i%2==0){
                v[i*2]=s1;
                v[i*2+1]=s2;
            } else {
                v[i*2]=s2;
                v[i*2+1]=s1;
            }
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}