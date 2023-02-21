#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>s(n);
    ll ceoS=-1;
    for(ll i=0; i<n; i++){
        cin>>s[i];
        if(s[i]==-1){
            ceoS=i;
        }
    }   
    ll ceoT=-1;
    vector<ll>t(n);
    for(ll i=0; i<n; i++){
        cin>>t[i];
        if(t[i]==-1){
            ceoT=i;
        }
    }
    if(ceoS!=ceoT){
        cout<<-1<<endl;
        return;
    }

    map<ll, vector<ll>>adj;
    for(ll i=0; i<n; i++){
        adj[s[i]-1].push_back(i);
    }

    vector<ll>order;
    queue<ll>q;
    q.push(ceoS);
    while(q.size()>0){
        ll curr=q.front();
        q.pop();
        order.push_back(curr);
        for(auto child:adj[curr]){
            q.push(child);
        }
    }

    reverse(order.begin(), order.end());

    vector<pair<ll, ll>>ans;

    for(auto curr:order){
        if(s[curr]==t[curr]){
            continue;
        } else {
            ans.push_back(pair<ll, ll>(curr, t[curr]-1));
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first+1<<" "<<i.second+1<<endl;
    }

    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}