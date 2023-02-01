#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse(ll x, ll y, ll r, ll c, vector<vector<ll>>&v, map<pair<ll, ll>, ll>&m){
    if(x==r-1&&y==c-1){
        return 1;
    }

    if(m[pair<ll, ll>(x, y)]!=0){
        return m[pair<ll, ll>(x, y)];
    }

    ll sum=0;
    if(x+1<r&&v[x+1][y]!=1){
        sum+=recurse(x+1, y, r, c, v, m);
    }
    if(y+1<c&&v[x][y+1]!=1){
        sum+=recurse(x, y+1, r, c, v, m);
    }
    return m[pair<ll, ll>(x, y)]=sum;
}

int solution(){
    ll r, c;
    cin>>r>>c;
    ll q;
    cin>>q;
    vector<vector<ll>>v(r, vector<ll>(c));
    for(ll i=0; i<q; i++){
        ll x, y;
        cin>>x>>y;
        v[x-1][y-1]=1;
    }
    map<pair<ll, ll>, ll>memo;
    cout<<recurse(0, 0, r, c, v, memo)<<endl;

    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}