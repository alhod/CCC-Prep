#include<bits/stdc++.h>
#define ll long long
using namespace std;


pair<ll, ll>merge(pair<ll, ll>d1, pair<ll, ll>d2){
    ll left=max(d1.first, d2.first);
    ll right=min(d1.second, d2.second);
    return pair<ll, ll>(left, right);
}


void solution(){
    ll n, w, h;
    cin>>n>>w>>h;
    vector<pair<ll, ll>>a(n);
    vector<pair<ll, ll>>b(n);
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        a[i]=pair<ll, ll>(x-w, x+w);
    }
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        b[i]=pair<ll, ll>(x-h, x+h);
    }

    vector<pair<ll, ll>>adjustment(n);
    for(ll i=0; i<n; i++){
        ll diff_one=a[i].first-b[i].first;
        ll diff_two=a[i].second-b[i].second;
        adjustment[i]=pair<ll, ll>(diff_one, diff_two);
    }

    pair<ll, ll>domain=adjustment[0];
    for(ll i=1; i<n; i++){
        if(domain.second<adjustment[i].first||domain.first>adjustment[i].second){
            cout<<"NO"<<endl;
            return;
        }

        domain=merge(domain, adjustment[i]);
    }

    cout<<"YES"<<endl;
    
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