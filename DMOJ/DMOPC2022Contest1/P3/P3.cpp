#include<bits/stdc++.h>
#define ll long long
using namespace std;

string solve(ll n, ll m, vector<vector<ll>>&v){
    
}

int main(){
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>>v(n+1, vector<ll>(n+1));
    vector<ll>v2(n, n-1);
    for(ll i=0; i<m; i++){
        ll p1, p2;
        cin>>p1>>p2;
        v[p1][p2]=1;
        v[p2][p1]=1;
    }
    
}