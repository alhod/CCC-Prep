#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution() {

    ll n, m;
    cin>>n>>m;

    vector<vector<ll>>v(n, vector<ll>(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<vector<pair<ll, ll>>>seen(1000001);
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            // printf("v[i][j]: %d\n", v[i][j]);
            seen[v[i][j]].push_back(pair<ll, ll>(i, j));
        }
    }

    // cout<<"aeouli";

    vector<vector<bool>>visited(1001, vector<bool>(1001));

    vector<bool>visited_nums(1000001);

    queue<pair<ll, ll>>q;

    q.push(pair<ll, ll>(n-1, m-1));
    while(q.size()>0){
        pair<ll, ll>curr=q.front();
        q.pop();

        if(visited[curr.first][curr.second]){
            continue;
        }

        visited[curr.first][curr.second]=true;

        if(curr.first==0&&curr.second==0){
            cout<<"yes"<<endl;
            return;
        }

        // printf("curr.first: %d, curr.second: %d\n", curr.first, curr.second);

        if(visited_nums[(curr.first+1)*(curr.second+1)]){
            continue;
        }

        visited_nums[(curr.first+1)*(curr.second+1)]=true;

        for(auto possible:seen[(curr.first+1)*(curr.second+1)]){
            if(visited[possible.first][possible.second]){
                continue;
            }
            // printf("possible.first: %d, possible.second: %d\n", possible.first, possible.second);
            q.push(possible);
        }

    }

    cout<<"no"<<endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}