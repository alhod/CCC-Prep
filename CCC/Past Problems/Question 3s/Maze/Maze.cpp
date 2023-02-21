#include<bits/stdc++.h>
#define ll long long
using namespace std;


map<pair<ll, ll>, ll>dijkstras(pair<ll, ll>start, map<pair<ll, ll>, vector<pair<ll, ll>>>adj, map<pair<ll, ll>, bool>blocked){
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>>pq;
    map<pair<ll, ll>, ll>dist;
    map<pair<ll, ll>, ll>visited;

    for(auto i:adj){
        dist[i.first]=10e8;
    }

    dist[start]=0;
    visited[start]=true;
    pq.push(pair<ll, pair<ll, ll>>(dist[start], start));
    while(!pq.empty()){
        pair<ll, pair<ll, ll>>curr=pq.top();
        pq.pop();

        visited[curr.second]=true;

        for(auto node:adj[curr.second]){
            if(blocked[node]==true||visited[node]==true){
                continue;
            }

            ll newDist = curr.first+1;
            if(newDist<dist[node]){
                dist[node]=newDist;
                pq.push(pair<ll, pair<ll, ll>>(dist[node], node));
            }
        }

    }

    return dist;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll r, c;
        cin>>r>>c;
        vector<string>v;
        for(ll i=0; i<r; i++){
            string aRow;
            cin>>aRow;
            v.push_back(aRow);
        }

        if(v[r-1][c-1]=='*'){
            cout<<-1<<endl;
            continue;
        }

        map<pair<ll, ll>, vector<pair<ll, ll>>>m;
        map<pair<ll, ll>, bool>cannotOccupy;
        for(ll i=0; i<r; i++){
            for(ll j=0; j<c; j++){
                if(v[i][j]=='+'){
                    m[pair<ll,ll>(i, j)].push_back(pair<ll, ll>(i+1, j));
                    m[pair<ll,ll>(i, j)].push_back(pair<ll, ll>(i-1, j));
                    m[pair<ll,ll>(i, j)].push_back(pair<ll, ll>(i, j+1));
                    m[pair<ll,ll>(i, j)].push_back(pair<ll, ll>(i, j-1));
                } else if(v[i][j]=='-'){
                    m[pair<ll, ll>(i, j)].push_back(pair<ll, ll>(i, j-1));
                    m[pair<ll, ll>(i, j)].push_back(pair<ll, ll>(i, j+1));
                } else if(v[i][j]=='|'){
                    m[pair<ll, ll>(i, j)].push_back(pair<ll, ll>(i+1, j));
                    m[pair<ll, ll>(i, j)].push_back(pair<ll, ll>(i-1, j));
                } else {
                    cannotOccupy[pair<ll, ll>(i, j)]=true;
                }
            }
        }

        ll distance = dijkstras(pair<ll, ll>(0, 0), m, cannotOccupy)[pair<ll, ll>(r-1, c-1)];
        if(distance==10e8){
            cout<<-1<<endl;
        } else {
            cout<<distance+1<<endl;
        }
    }
}