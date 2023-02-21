#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll x=0, y=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='U'){
            y++;
        } else if(s[i]=='D'){
            y--;
        } else if(s[i]=='R'){
            x++;
        } else {
            x--;
        }
        if(x==1&&y==1){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    
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