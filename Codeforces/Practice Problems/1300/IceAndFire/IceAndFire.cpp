#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;


    ll farthest_one=-1;
    ll farthest_zero=-1;
    for(ll i=1; i<n; i++){
        if(s[i-1]=='1'){
            farthest_one=max(farthest_one, i-1);
        } else {
            farthest_zero=max(farthest_zero, i-1);
        }

        if(farthest_one==-1){
            cout<<1<<" ";
        } else if(farthest_zero==-1){
            cout<<1<<" ";
        } else {
            cout<<(farthest_one+1)-(i-farthest_zero-1)+1<<" ";
        }
    }
    cout<<endl;
    
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