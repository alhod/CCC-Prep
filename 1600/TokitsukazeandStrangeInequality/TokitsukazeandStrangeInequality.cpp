#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<vector<ll>>m(n+1, vector<ll>(n+1, 0));
    for(ll i=0; i<n; i++){
        for(ll j=n-1; j>=i; j--){
            if(v[j]<v[i]){
                m[i][j]++;
            }
            m[i][j]+=m[i][j+1];
        }
    }

    for(ll i=1; i<n; i++){
        for(ll j=0; j<n; j++){
            m[i][j]+=m[i-1][j];
        }
    }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<n; j++){
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ans=0;
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if(v[i]<v[j]){
                ans+=m[j-1][j+1]-m[i][j+1];
            }
        }
    }

    cout<<ans<<endl;
    
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