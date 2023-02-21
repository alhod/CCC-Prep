#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(ll n, ll m){
    vector<string>v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    ll r=0;
    ll r2=0;
    ll c=0;
    ll c2=0;
    bool searching = false;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='0'&&searching==false){
                continue;
            }
            else if (v[i][j]=='1'&&searching==false){
                searching=true;
                r=i;
                c=j;
                for(ll j1=j;j1<m;j1++){
                    if(v[i][j1]=='0'||j1==m-1){
                        c2=j1;
                        break;
                    }
                    else if(v[i][j1]=='1'){
                        continue;
                    }
                }
                for(ll i1='0';i1<n;i1++){
                    if(v[i1][j]=='0'||i1==n-1){
                        r2=i1;
                        break;
                    }
                    else if(v[i1][j]==1){
                        continue;
                    }
                }
            }
            if(v[i][j]=='0'&&searching==true){
                if(r<=i<=r2&&c<=j<=c2){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            if(v[i][j]=='1'&&searching==true){
                if(i<r||i>r2||j<c||j>c2){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;

}

int main(){
    ll t;cin>>t;
    while(t--){
        ll n; ll m;cin>>n;cin>>m;
        solve(n, m);
    }
}