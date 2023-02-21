#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    if(n==1&&m==1){
        ll s;
        cin>>s;
        if(s==1){
            cout<<1<<endl;
        } else {
            cout<<-1<<endl;
        }
    } else if(m==1){
        vector<ll>s(n);
        for(ll i=0; i<n; i++){
            cin>>s[i];
        }

        if(s[0]==1){
            cout<<1<<endl;
        } else {
            if(n%2!=0){
                cout<<-1<<endl;
            } else {
                cout<<1<<endl;
            }
        }
    } else {
        vector<ll>s(n);
        ll num1s=0;
        for(ll i=0; i<n; i++){
            cin>>s[i];
            if(s[i]==1){
                num1s++;
            }
        }

        if((n-num1s)%2!=0){
            cout<<2<<endl;
        } else {
            cout<<1<<endl;
        }
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}