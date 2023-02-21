#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll t;

bool compare(ll x, ll y){
    if((x|t)>(y|t)){
        return true;
    } else {
        return false;
    }
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    t=0;
    for(ll i=0; i<min(n, (long long)32); i++){
        sort(v.begin()+i, v.end(), compare);
        t|=v[i];
    }
    for(ll i=0; i<n; i++){
        cout<<v[i]<<" ";
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