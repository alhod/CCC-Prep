#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<string>v(m);
    vector<ll>output(m);
    for(ll i=0; i<m; i++){
        cin>>v[i];
        cin>>output[i];
    }

    
    for(ll i=0; i<m; i++){
        ll ret;
        if(n==1){
            if(v[i][0]=='0'){
                ret=0;
            } else {
                ret=1;
            }
        } else {
            if(v[i][1]=='1'){
                ret=1;
            } else if(v[i][0]=='0'){
                ret=0;
            } else {
                ret=1;
            }
        }
        if(ret!=output[i]){
            cout<<"LIE"<<endl;
            return;
        }
    }

    cout<<"OK"<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}