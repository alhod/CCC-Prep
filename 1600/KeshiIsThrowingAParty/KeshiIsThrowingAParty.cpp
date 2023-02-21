#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
vector<pair<ll, ll>>v;


bool check(ll mid){
    ll count=0;
    ll numMore=mid-1;
    ll numLess=0;
    // printf("mid: %d\n", mid);
    for(ll i=0; i<n; i++){
        if(v[i].first>=numMore&&v[i].second>=numLess){
            // printf("person %d works. count=%d\n", i, count);
            count++;
            numMore--;
            numLess++;
        }
    }

    if(count>=mid){
        return true;
    } else {
        return false;
    }
}


void solution(){
    
    cin>>n;
    v.clear();
    v.resize(n);
    for(ll i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }

    ll l=0, r=n, mid, ans=0;
    while(l<=r){
        mid=l+(r-l)/2;
        if(check(mid)){
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