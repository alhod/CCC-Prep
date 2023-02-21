#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<vector<ll>>v(n, vector<ll>(n));
    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            cin>>v[i][j];
        }
    }

    vector<ll>ans(n);
    ans[0]=v[0][0];
    ans[1]=v[0][1];

    for(ll i=2; i<n; i++){
        if(v[i-1][i]==0){
            ans[i]=ans[i-1];
            continue;
        }

        // printf("i: %d\n", i);

        bool found_diff=false;
        ll diff_up=ans[i-1]+v[i-1][i];
        ll diff_down=ans[i-1]-v[i-1][i];
        for(ll p=i-2; p>=0; p--){
            if(ans[p]==ans[p+1]){
                continue;
            }
            
            ll upper=max(max(ans[p], ans[p+1]), diff_up)-min(min(ans[p], ans[p+1]), diff_up);
            ll lower=max(max(ans[p], ans[p+1]), diff_down)-min(min(ans[p], ans[p+1]), diff_down);
            if(upper==v[p][i]){
                ans[i]=diff_up;
            } else {
                ans[i]=diff_down;
            }
            found_diff=true;
            break;
        }

        if(!found_diff){
            ans[i]=ans[i-1]+v[i-1][i];
        }
        // printf("ans[i]: %d\n", ans[i]);
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i]<<(i<n-1?" ":"");
    }
    cout<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}