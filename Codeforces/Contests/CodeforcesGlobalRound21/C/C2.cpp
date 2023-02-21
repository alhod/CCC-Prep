#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<pair<ll, ll>> f(ll n, ll m){
    vector<pair<ll, ll>>v;
    for(ll i=0; i<n; i++){
        ll a; cin>>a;
        ll c=1;
        while(a%m==0){
            a/=m;
            c*=m;
        }
        if(v.empty()==false&&v.back().first==a)v.back().second+=c;
        else v.push_back(make_pair(a, c));
    }
    // for(ll i=0; i<v.size(); i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    return v;
}

int main(){
    ll t, n, m, k;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<pair<ll, ll>>a = f(n, m);
        cin>>k;
        vector<pair<ll, ll>>b = f(k, m);
        cout<<(a==b?"YES":"NO")<<endl;
    }
}