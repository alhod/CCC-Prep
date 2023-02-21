#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse(ll n, ll m, string s, vector<pair<ll, ll>>&q, map<ll, bool>&visited, hash<string>&hasher, map<ll, ll>&memo){
    // cout<<s<<endl;
    if(memo[hasher(s)]!=0){
        return memo[hasher(s)];
    }
    ll best=10e8;
    if(s[0]==s[n-1]){
        return 0;
    }
    if(visited[hasher(s)]==true){
        return best;
    }
    visited[hasher(s)]=true;
    for(ll i=0; i<m; i++){
        string sCopy = s;
        swap(sCopy[q[i].first-1], sCopy[q[i].second-1]);
        // cout<<"new copy: "<<sCopy<<endl;
        // cout<<"swapped: "<<q[i].first<<" "<<q[i].second<<endl;
        ll currBest = 1+recurse(n, m, sCopy, q, visited, hasher, memo);
        best=min(best, currBest);
    }
    return memo[hasher(s)]=best;
}

int main(){
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    string s;
    for(ll i=0; i<n; i++){
        char p;
        cin>>p;
        s.push_back(p);
    }
    vector<pair<ll, ll>>q;
    for(ll i=0; i<m; i++){
        ll p1, p2;
        cin>>p1>>p2;
        q.push_back(pair<ll, ll>(p1, p2));
    }
    // for(auto i:q){
        // cout<<i.first<<" "<<i.second<<endl;
    // }

    hash<string>hasher;
    map<ll, bool>visited;
    map<ll, ll>memo;
    ll ans = recurse(n, m, s, q, visited, hasher, memo);
    cout<<(ans==10e8?-1:ans)<<endl;


}