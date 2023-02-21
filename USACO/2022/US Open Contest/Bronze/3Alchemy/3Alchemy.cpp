#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll dfs(ll n, vector<ll>&v, vector<vector<vector<ll>>>&r){
    if(r[n].size()==0){
        return 0;
    }

    for(ll i=0; i<r[n].size(); i++){
        
    }
}


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }    
    ll k;
    cin>>k;

    vector<vector<vector<ll>>>r(10^4+10);

    while(k--){
        ll num;
        cin>>num;
        ll sz;
        cin>>sz;
        vector<ll>rec;
        while(sz--){
            ll num1;
            cin>>num1;
            rec.push_back(num1);
        }
        r[num].push_back(rec);
    }

    cout<<dfs(n, v, r)<<endl;
    
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