#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m;
vector<ll>v;


bool check(ll k){
    // printf("k: %d\n", k);
    vector<ll>first_half;
    vector<ll>second_half;
    vector<ll>best_case;

    for(ll i=0; i<(n-k)/2; i++){
        first_half.push_back(v[i]);
    }
    for(ll i=(n-k)/2; i<n-k; i++){
        second_half.push_back(v[i]);
    }

    reverse(second_half.begin(), second_half.end());
    for(ll i=0; i<n-k; i++){
        if(i%2==0){
            best_case.push_back(second_half[i/2]);
        } else {
            best_case.push_back(first_half[i/2]);
        }
    }

    // for(auto i:best_case){
        // cout<<i<<" ";
    // }
    // cout<<endl;

    for(ll i=0; i<n-k-1; i++){
        if(best_case[i]+best_case[i+1]>m){
            // cout<<"false"<<endl;
            return false;
        }
    }

    // cout<<"true"<<endl;
    return true;
}


void solution(){
    cin>>n>>m;
    v.resize(n);
    

    ll sum=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }

    sort(v.begin(), v.end());

    ll l=0, r=n-1, mid, ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }

    cout<<ans+sum+1<<endl;

    
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}