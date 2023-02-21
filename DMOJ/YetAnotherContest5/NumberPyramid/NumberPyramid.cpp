#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, k, x;
    cin>>n>>k>>x;
    vector<vector<ll>>v(n);
    v[0].push_back(x);
    for(ll i=0; i<n-1; i++){
        v[n-1].push_back(k-1);
    }
    for(ll i=n-2; i>0; i--){
        for(ll j=0; j<i; j++){
            v[i].push_back((v[i+1][j]+v[i+1][j+1])%k);
        }
    }
    // for(auto i:v){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    for(ll i=1; i<n; i++){
        if(v[i-1][i-1]+k-v[i][i-1]<k){
            v[i].push_back(v[i-1][i-1]+k-v[i][i-1]);
        } else {
            v[i].push_back(v[i-1][i-1]-v[i][i-1]);
        }
    }

    for(ll i=0; i<n; i++){
        cout<<v[n-1][i]<<" ";
    }
    cout<<endl;
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}