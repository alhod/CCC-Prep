#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(){
    ll n;
    cin>>n;
    n*=2;
    string s;
    cin>>s;
    ll p1=-1;
    ll p2=-1;

    ll num1=0;
    ll num0=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='1'){
            num1++;
        } else {
            num0++;
        }
    }
    if(num1%2!=0||num0%2!=0){
        cout<<-1<<endl;
        return 0;
    }

    for(ll i=0; i<n/2; i+=2){
        if(s[i]!=s[i+1]){
            if(p1==-1){
                p1=i;
            } else if (p2==-1){
                p2=i;
            } else {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        
    }
}