#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll>dp(1001, 999);



void setup(){
    dp[1]=0;    
    
    for(ll i=1; i<1001; i++){
        for(ll j=i; j>=1&&((i+(i/j))<1001); j--){
            dp[i+i/j]=min(dp[i+i/j], 1+dp[i]);
            
        }
    }
}



//Function to return max value that can be put in knapsack of capacity W.
ll knapSack(ll W, vector<ll>&wt, vector<ll>&val, ll n)
{ 
    // vector<ll>arr(W+1, 0);
    // for(ll i=0; i<n; i++){
    //     for(ll j=W-wt[i]; j>=0; j--){   
    //         arr[j+wt[i]]=max(arr[j+wt[i]], arr[j]+val[i]);
    //     }
    // }

    // return *max_element(arr.begin(), arr.end());
    
    vector<vector<ll>>v(n+1, vector<ll>(W+1));
    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<W+1; j++){
            if(wt[i-1]>j){
                v[i][j]=v[i-1][j];
            } else {
                v[i][j]=max(v[i-1][j], val[i-1]+v[i-1][j-wt[i-1]]);
            }
        }
    }
    return v[n][W];
}


void solution(){
    // ll n;
    // cin>>n;
    // cout<<cost(n)<<endl;
    
    ll n, k;
    cin>>n>>k;
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>b[i];        
    }
    vector<ll>c(n);
    for(ll i=0; i<n; i++){
        cin>>c[i];
    }

    ll ans=0;

    vector<ll>weights;
    vector<ll>values;
    for(ll i=0; i<n; i++){
        if(b[i]==1){
            ans+=c[i];
        } else {
            weights.push_back(dp[b[i]]);
            values.push_back(c[i]);
        }
    }


    ll sum=0;
    for(ll i=0; i<n; i++){
        sum+=dp[b[i]];
    }

    k=min(k, sum);

    
    ans+=knapSack(k, weights, values, weights.size());

    // ll ans=0;
    // vector<ll>arr(k+1);
    // for(ll i=0; i<n; i++){
    //     for(ll j=k-dp[b[i]]; j>=0; j--){
    //         arr[j+dp[b[i]]]=max(arr[j+dp[b[i]]], arr[j]+c[i]);
    //     }
    // }

    cout<<ans<<endl;
    
    // cout<<*max_element(arr.begin(), arr.end())<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    setup();

    // for(auto i:adj){
    //     printf("----%d----\n", i.first);
    //     for(auto j:i.second){
    //         printf("%d, ", j);
    //     }
    // }

    // for(ll i=0; i<1001; i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;

    while(t--){
        solution();
    }
}