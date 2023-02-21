#include<bits/stdc++.h>
#define ll long long
using namespace std;



bool check(ll n, ll m, ll l, vector<vector<ll>>&v){
    if(l<=1){
        return true;
    }

    vector<vector<ll>>pre=v;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(pre[i][j]<l){
                pre[i][j]=0;
            } else {
                pre[i][j]=1;
            }
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(i==0&&j==0){
                continue;
            } else if(i==0){
                pre[i][j]+=pre[i][j-1];
            } else if(j==0){
                pre[i][j]+=pre[i-1][j];   
            } else {
                pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
    }

    // printf("%d %d %d\n", n, m, l);
    // for(auto i:pre){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    for(ll i=l-1; i<n; i++){
        for(ll j=l-1; j<m; j++){
            ll amount;
            if(i==l-1&&j==l-1){
                amount=pre[i][j];
            } else if(i==l-1){
                amount=pre[i][j]-pre[i][j-l];
            } else if(j==l-1){
                amount=pre[i][j]-pre[i-l][j];
            } else {
                amount=pre[i][j]-pre[i-l][j]-pre[i][j-l]+pre[i-l][j-l];
            }

            if(amount==(ll)pow(l, 2)){
                return true;
            }        
        }
    }

    return false;
}



void solution(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    ll l=0, r=min(n, m), mid, ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(n, m, mid, v)){
            l=mid+1;
            ans=mid;
        } else {
            r=mid-1;
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