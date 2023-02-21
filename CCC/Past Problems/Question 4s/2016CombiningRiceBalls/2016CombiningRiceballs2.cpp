#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll>>dp;


bool f(ll n, ll i, ll j, vector<ll>&v, vector<ll>&pre){
    // printf("%d %d %d\n", n, i, j);

    if(i>=j){
        // printf("returning true\n");
        return true;
    }

    if(j-i+1<=3){
        // printf("returning %d\n", v[i]==v[j]);
        return v[i]==v[j];
    }

    if(dp[i][j]!=-1){
        // printf("returning %d\n", dp[i][j]);
        return dp[i][j];
    }
    
    ll p1=i, p2=j;
    while(p1<p2){
        ll p1_val=(i==0?pre[p1]:pre[p1]-pre[i-1]);
        ll p2_val=(p2==0?pre[j]:pre[j]-pre[p2-1]);
        // printf("p1: %d, p1_val: %d, p2: %d, p2_val: %d\n", p1, p1_val, p2, p2_val);

        if(p1_val==p2_val){
            // printf("calling %d %d\n", i, p1);
            // printf("calling %d %d\n", p2, j);
            // printf("calling %d %d\n", p1+1, p2-1);
            
            if(f(n, i, p1, v, pre)&&f(n, p2, j, v, pre)&&f(n, p1+1, p2-1, v, pre)){
                // printf("returning true\n");
                return dp[i][j]=true;
            }
            p1++;
            p2--;
        } else if(p1_val<p2_val){
            p1++;
        } else if(p1_val>p2_val){
            p2--;
        }
    }

    // printf("returning false\n");
    return dp[i][j]=false;
}


void solution(){
    ll n;
    cin>>n;
    dp.resize(n, vector<ll>(n, -1));
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>pre=v;
    for(ll i=1; i<n; i++){
        pre[i]+=pre[i-1];
    }


    ll best=0;
    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            best=max(best, f(n, i, j, v, pre)*pre[j]-(i==0?0:pre[i-1]));
        }
    }

    cout<<best<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}