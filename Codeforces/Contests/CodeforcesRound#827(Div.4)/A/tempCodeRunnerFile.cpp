#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, x, y;
    cin>>n>>x>>y;
    if(x+y==n){
        cout<<"YES"<<endl;
    } else if(n+x==y){
        cout<<"YES"<<endl;
    } else if(y+n==x){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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