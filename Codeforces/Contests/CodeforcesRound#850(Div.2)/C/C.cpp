#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(ll i=0; i<n; i++){
        pq.push(v[i]);
    }

    ll ans=0;
    ll cnt=1;
    while(pq.size()>0){
        ll curr=pq.top();
        pq.pop();
        // printf("curr: %d, cnt: %d\n", curr, cnt);
        if(curr<=cnt){
            if(curr==cnt){
                cnt++;
            }
            continue;
        }

        ans+=curr-cnt;
        cnt++;
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