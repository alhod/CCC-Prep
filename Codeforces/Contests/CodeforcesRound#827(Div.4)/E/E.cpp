#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    while(q--){
        ll num;
        cin>>num;
        ll run=0;
        bool printed=false;
        for(ll i=0; i<n; i++){
            if(v[i]>num){
                cout<<run<<" ";
                printed=true;
                break;
            } else {
                run+=v[i];
            }
        }
        if(printed==false){
            cout<<run<<" ";
        }
    }
    cout<<endl;
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