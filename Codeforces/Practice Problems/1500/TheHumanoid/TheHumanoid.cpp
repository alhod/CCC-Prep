#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(priority_queue<ll, vector<ll>, greater<ll>>pq, ll h, ll numGreen, ll numBlue){
    ll ans=0;
    while(pq.size()>0){
        if(pq.top()<h){
            h+=pq.top()/2;
            pq.pop();
            ans++;
        } else {
            break;
        }
    }

    if(pq.size()>0){
        ll best=0;
        if(numGreen>0){
            best=max(best, solve(pq, h*2, numGreen-1, numBlue));
        }
        if(numBlue>0){
            best=max(best, solve(pq, h*3, numGreen, numBlue-1));
        }
        ans+=best;
    }

    return ans;
}

int solution(){
    ll n, h;
    cin>>n>>h;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(ll i=0; i<n; i++){
        pq.push(v[i]);
    }

    cout<<solve(pq, h, 2, 1)<<endl;
    
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