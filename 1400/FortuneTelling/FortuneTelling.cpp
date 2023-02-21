#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, x, y, tot;
    cin>>n>>x>>y;
    tot=x;
    for(ll i=0, a; i<n; i++){
        cin>>a;
        tot+=a;
    }

    if(tot%2==0){
        cout<<(y%2==0?"Alice":"Bob")<<endl;
    } else {
        cout<<(y%2!=0?"Alice":"Bob")<<endl;
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