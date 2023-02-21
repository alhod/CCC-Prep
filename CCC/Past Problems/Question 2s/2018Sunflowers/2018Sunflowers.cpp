#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<vector<ll>>v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cin>>v[i][j];
        }
    }

    if(v[0][0]<v[0][1]&&v[0][0]<v[1][0]){
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    } else if(v[0][0]<v[1][0]&&v[0][0]>v[0][1]){
        for(ll j=n-1; j>=0; j--){
            for(ll i=0; i<n; i++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    } else if(v[0][0]>v[1][0]&&v[0][0]<v[0][1]){
        for(ll j=0; j<n; j++){
            for(ll i=n-1; i>=0; i--){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        for(ll i=n-1; i>=0; i--){
            for(ll j=n-1; j>=0; j--){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}