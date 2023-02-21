#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(n));
    map<ll, ll>rows;
    map<ll, ll>cols;
    for(ll i=0; i<m; i++){
        ll x, y;
        cin>>x>>y;
        v[x-1][y-1]++;
        rows[x-1]++;
        cols[y-1]++;
    }
    if(m>n){
        cout<<"NO"<<endl;
        return 0;
    }

    ll numInt=0;

    for(ll i=0; i<n; i++){
        if(rows[i]>=3){
            cout<<"NO"<<endl;
            return 0;
        } else if(cols[i]==2){
            numInt++;
        }
        for(ll j=0; j<n; j++){
            if(cols[j]>=3){
                cout<<"NO"<<endl;
                return 0;
            } else if (cols[j]==2){
                numInt++;
            }
        }
        if(numInt>=2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(numInt==0&&n==m){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    
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