#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define MAXN 405

ll n;
vector<ll>v;
vector<ll>pre;
vector<vector<ll>>dp;


bool can_merge(ll start, ll end){
    if(start==end){
        return true;
    }

    // printf("start: %d, end: %d\n", start, end);

    return dp[start][end]!=-1;
}


void solution(){
    cin>>n;
    v.resize(n);
    pre.resize(n+1);
    dp.resize(MAXN, vector<ll>(MAXN, -1));



    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    for(ll i=1; i<n+1; i++){
        pre[i]=pre[i-1]+v[i-1];
    }

    for(ll i=0; i<n; i++){
        dp[i][i]=v[i];
    }



    for(ll range=2; range<=n; range++){
        
        // merge two
        for(ll left_start=0; left_start<n-range+1; left_start++){
            ll right_end=left_start+range-1;
            for(ll mid_point=left_start; mid_point<right_end; mid_point++){
                if(can_merge(left_start, mid_point)&&can_merge(mid_point+1, right_end)){
                    if(dp[left_start][mid_point]==dp[mid_point+1][right_end]){
                        // printf("merge 2: %d %d %d\n", left_start, mid_point, right_end);
                        dp[left_start][right_end]=dp[left_start][mid_point]+dp[mid_point+1][right_end];
                    }
                }
            }
        }

        if(range==2){
            continue;
        }

        // merge three
        for(ll left_start=0; left_start<n-range+1; left_start++){
            ll right_end=left_start+range-1;
            if(dp[left_start][right_end]!=-1){
                continue;
            }

            for(ll mid_start=left_start+1; mid_start<right_end; mid_start++){
                ll left_end=mid_start-1;
                for(ll mid_end=mid_start; mid_end<right_end; mid_end++){
                    ll right_start=mid_end+1;
                    if(can_merge(left_start, left_end)&&can_merge(mid_start, mid_end)&&can_merge(right_start, right_end)){
                        if(dp[left_start][left_end]==dp[right_start][right_end]){
                            // printf("merge 3: %d %d %d %d %d %d\n", left_start, left_end, mid_start, mid_end, right_start, right_end);
                            dp[left_start][right_end]=dp[left_start][left_end]+dp[mid_start][mid_end]+dp[right_start][right_end];
                        }
                    }
                }
            }
        }
    }

    // for(ll i=0; i<n; i++){
        // for(ll j=0; j<n; j++){
            // cout<<dp[i][j]<<" ";
        // }
        // cout<<endl;
    // }

    ll ans=0;
    for(ll i=0; i<n; i++){
        for(ll j=i; j<n; j++){
            ans=max(ans, dp[i][j]);
        }
    }

    cout<<ans<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}