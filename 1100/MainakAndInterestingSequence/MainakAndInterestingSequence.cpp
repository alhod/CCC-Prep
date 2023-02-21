#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        vector<ll>v(n);
        if(n>m||n%2==0&&m%2!=0){
            cout<<"No"<<endl;
            continue;
        }

        if(n%2!=0){
            ll valOfFinalNum=m-n+1;
            for(ll i=0; i<n-1; i++){
                v[i]=1;
            }
            v[n-1]=valOfFinalNum;
        } else if(n%2==0){
            ll valOfFinalNum=m-n+2;
            for(ll i=0; i<n-1; i++){
                v[i]=1;
            }
            valOfFinalNum/=2;
            v[n-1]=valOfFinalNum;
            v[n-2]=valOfFinalNum;
        }
        cout<<"Yes"<<endl;
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}