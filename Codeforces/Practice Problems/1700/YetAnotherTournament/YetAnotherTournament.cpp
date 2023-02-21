#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m;
vector<ll>v;
vector<pair<ll, ll>>min_weight;

bool is_possible(ll mid){
    // printf("mid: %d\n", mid);
    // defeat person n-mid

    ll remaining_capacity=m;
    ll people_defeated=0;


    // don't include n-mid among people to defeat
    for(ll i=0; i<n; i++){
        if(people_defeated==n-mid+1||min_weight[i].first>remaining_capacity){
            break;
        }
        
        if(min_weight[i].second==n-mid){
            continue;
        }

        remaining_capacity-=min_weight[i].first;
        people_defeated++;
    }

    if(people_defeated>=n-mid+1){
        // printf("possible 1\n");
        return true;
    }

    
    remaining_capacity=m;
    people_defeated=0;

    // include n-mid among people to defeat
    remaining_capacity-=v[n-mid];
    people_defeated++;

    if(remaining_capacity<0){
        return false;
    }

    for(ll i=0; i<n; i++){
        if(people_defeated==n-mid||min_weight[i].first>remaining_capacity){
            break;
        }
        
        if(min_weight[i].second==n-mid){
            continue;
        }

        remaining_capacity-=min_weight[i].first;
        people_defeated++;
    }

    if(people_defeated>=n-mid){
        // printf("possible 2\n");
        return true;
    }

    return false;
}



void solution(){
    cin>>n>>m;

    v.clear();
    v.resize(n);
    min_weight.clear();
    min_weight.resize(n);
    
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    
    for(ll i=0; i<n; i++){
        min_weight[i]=pair<ll, ll>(v[i], i);
    }

    sort(min_weight.begin(), min_weight.end());


    ll l=1, r=n+1, ans, mid;
    while(l<=r){
        mid=l+(r-l)/2;
        if(is_possible(mid)){
            r=mid-1;
            ans=mid;
        } else {
            l=mid+1;
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