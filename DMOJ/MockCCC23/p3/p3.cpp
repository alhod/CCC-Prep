#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define mod 998244353


ll recurse(ll start, ll end, vector<vector<bool>>seen, map<ll, vector<ll>>&forwards, map<ll, vector<ll>>&backwards, bool direction){
    // direction=true is forwards
    // direction=false is backwards
    
    printf("start: %d, end: %d, direction: %d\n", start, end, direction);
    printf("seen: ");
    for(ll i=0; i<seen.size(); i++){
        if(seen[start][i]){
            printf("%d ", i);
        }
    }
    printf("\n");

    // if(start!=1){
    //     seen[start]=true;
    // }
    
    if(start==end&&end==seen.size()-1){
        printf("reached %d, going backwards\n", seen.size()-1);
        end=1;
        direction=false;
    } else if(start==end&&end==1){
        printf("reached 1, returning 1\n");
        return 1;
    }

    ll ans=0;

    if(direction){
        for(ll i:forwards[start]){
            if(!seen[start][i]){
                vector<vector<bool>>copy=seen;
                copy[start][i]=true;
                copy[i][start]=true;
                ans+=recurse(i, end, seen, forwards, backwards, direction);
            }
        }
        return ans;
    } else {
        for(ll i:backwards[start]){
            if(!seen[start][i]){
                vector<vector<bool>>copy=seen;
                copy[start][i]=true;
                copy[i][start]=true;
                ans+=recurse(i, end, seen, forwards, backwards, direction);
            }
        }
        return ans;
    }


}


void solution(){
    ll n, k;
    cin>>n>>k;

    map<ll, vector<ll>>forwards;
    map<ll, vector<ll>>backwards;

    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=i+k&&j<=n; j++){
            forwards[i].push_back(j);
            backwards[j].push_back(i);
        }
    }

    vector<vector<bool>>seen(n+1, vector<bool>(n+1));

    for(ll i=1; i<=n; i++){
        seen[i][i]=true;
    }

    cout<<recurse(1, n, seen, forwards, backwards, true)<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}