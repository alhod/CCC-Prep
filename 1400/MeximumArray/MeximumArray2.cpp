#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<queue<ll>>cnt(n+1);

    for(ll i=0; i<n; i++){
        cnt[v[i]].push(i);
    }

    ll ind=0;
    ll start=0;
    vector<ll>ans;

    while(start<n){
        for(ll i=0; i<n+1; i++){
            if(cnt[i].size()>0){
                ind=max(ind, cnt[i].front());
            } else {
                for(ll j=start; j<=ind; j++){
                    cnt[v[j]].pop();
                }
                start=ind+1;
                ind=start;
                ans.push_back(i);
                break;
            }
        }
    }
    
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
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