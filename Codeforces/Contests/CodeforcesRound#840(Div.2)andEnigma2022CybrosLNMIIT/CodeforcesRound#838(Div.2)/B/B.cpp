#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        pq.push(pair<ll, ll>(v[i], i+1));
    }

    ll curr=pq.top().first;
    pq.pop();
    vector<pair<ll, ll>>ans;
    while(pq.size()>0){
        pair<ll, ll>curr2=pq.top();
        // cout<<"curr: "<<curr<<endl;
        // cout<<"curr2: "<<curr2.first<<endl;
        pq.pop();
        if(curr2.first%curr!=0){
            ans.push_back(pair<ll, ll>(curr2.second, curr-curr2.first%curr));
            curr=curr2.first+curr-curr2.first%curr;
        } else {
            curr=curr2.first;
        }
        
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }


    
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