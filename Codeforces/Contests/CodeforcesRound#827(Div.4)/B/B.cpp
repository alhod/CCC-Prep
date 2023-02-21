#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    map<ll, ll>m;
    for(ll i=0; i<n; i++){
        if(m[v[i]]==1){
            cout<<"NO"<<endl;
            return 0;
        } else {
            m[v[i]]++;
        }
    }
    cout<<"YES"<<endl;
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