#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll x=0;
    ll y=0;
    for(ll i=0; i<n; i++){
        if(s[i]=='0'){
            x++;
        } else {
            y++;
        }
    }

    ll longestX=0;
    ll longestY=0;

    ll count=0;
    for(ll i=0; i<n; i++){
        if(s[i]!='0'){
            count=0;
        } else {
            count++;
            longestX=max(longestX, count);
        }
    }

    count=0;
    for(ll i=0; i<n; i++){
        if(s[i]!='1'){
            count=0;
        } else {
            count++;
            longestY=max(longestY, count);
        }
    }

    cout<<max(x*y, max(longestX*longestX, longestY*longestY))<<endl;
    
    return 0;
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