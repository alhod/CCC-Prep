#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        if(m==0){
            break;
        }
        for(ll j=0; j<n; j++){
            if(m==0){
                break;
            }

            if(j<=i){
                v[i][j]=-1;
            } else {
                v[i][j]=1;
                m--;
            }
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            if(v[i][j]==1){
                cout<<i+1<<" "<<j+1<<endl;
            }
        }
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}