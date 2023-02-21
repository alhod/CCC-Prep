#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll mod=1e9+7;

map<ll, ll>memo;

ll pow_mod(ll x, ll n, ll m){
    ll y = 1;
    while(n > 0){
        if(n%2==1){
            y = (y*x)%m;
        }
        n = n/2;
        x = (x*x)%m;
    }
    return y;
}


ll recurse(ll n){
    if(n%2==0){
        return ((ll)pow(recurse(n/2), 2)+1);
    } else {
        return 1;
    }
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll count=1;
    for(ll i=0; i<n; i++){
        if(v[i]%2==0){
            count=(count*(recurse(v[i])));
        }
    }
    cout<<count<<endl;

    
    return 0;
}

// map<pair<ll, ll>, ll>memo;
// ll m;

// ll rec(ll x, vector<ll>used, vector<pair<ll, ll>>&v){
//     if(x==m){
//         return 0;
//     }

//     ll best=1e18;
//     for(ll i=0; i<v.size(); i++){
//         if(used[i]==0){
//             vector<ll>tmp=used;
//             tmp[i]=1;
//             best=min(best, v[i].first*x+v[i].second+rec(x+1, tmp, v));
//         }
//     }
//     return best;
// }

// ll rec(ll x, ll ind, vector<pair<ll, ll>>&v){
//     cout<<x<<" "<<ind<<endl;
//     if(x==m){
//         return 0;
//     }
    
//     if(ind==v.size()&&x!=m){
//         return -1;
//     }

//     if(memo[pair<ll, ll>(x, ind)]!=0){
//         return memo[pair<ll, ll>(x, ind)];
//     }

//     ll best=-1;
//     for(ll i=ind; i<v.size(); i++){
//         printf("calling %d %d from %d %d\n", x+1, i+1, x, ind);
//         ll ret=v[i].first*x+v[i].second+rec(x+1, i+1, v);
//         printf("ret (%d, %d): %d\n", x, i, ret);
//         if(ret==-1){
//             continue;
//         } else if(best==-1){
//             best=ret;
//         } else {
//             best=min(best, ret);
//         }
//     }
//     return memo[pair<ll, ll>(x, ind)]=best;
// }

// void solution(){
    // ll n;
    // cin>>n>>m;
    // vector<pair<ll, ll>>v(n);
    // for(ll i=0; i<n; i++){
    //     cin>>v[i].first>>v[i].second;
    // }

    // vector<ll>used(n);

    // cout<<rec(0, used, v)<<endl;
// }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}