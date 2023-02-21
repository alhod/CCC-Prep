#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string>v;
vector<vector<ll>>visited;
vector<ll>order;

ll bfs(ll row, ll col, ll numRows, ll numCols){
    queue<pair<ll, ll>>q;
    q.push(pair<ll, ll>(row, col));
    ll total=0;
    while(q.size()>0){
        ll r=q.front().first;
        ll c=q.front().second;
        q.pop();
        if(visited[r][c]==1||v[r][c]=='I'){
            continue;
        }
        // cout<<r<<" "<<c<<endl;
        visited[r][c]=1;
        total++;
        if(r+1<numRows&&visited[r+1][c]==0&&v[r+1][c]!='I'){
            q.push(pair<ll, ll>(r+1, c));
        }
        if(r-1>=0&&visited[r-1][c]==0&&v[r-1][c]!='I'){
            q.push(pair<ll, ll>(r-1, c));
        }
        if(c+1<numCols&&visited[r][c+1]==0&&v[r][c+1]!='I'){
            q.push(pair<ll, ll>(r, c+1));
        }
        if(c-1>=0&&visited[r][c-1]==0&&v[r][c-1]!='I'){
            q.push(pair<ll, ll>(r, c-1));
        }
    }
    return total;
}

int main(){

    ll flooring;
    cin>>flooring;
    ll r, c;
    cin>>r>>c;
    v.resize(r);
    
    for(ll i=0; i<r; i++){
        vector<ll>aVec(c);
        visited.push_back(aVec);
    }
    for(ll i=0; i<r; i++){
        string s;
        cin>>s;
        v[i]=s;
    }

    for(ll i=0; i<r; i++){
        for(ll j=0; j<c; j++){
            if(v[i][j]=='I'||visited[i][j]==1){
                continue;
            } else {
                // cout<<"bfs on: "<<i<<" "<<j<<endl;
                order.push_back(bfs(i, j, r, c));
            }

        }
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    // for(auto i:order){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    ll ind=0;
    ll numRooms=0;
    while(ind<order.size()){
        if(flooring-order[ind]<0){
            break;
        } else {
            flooring-=order[ind];
            numRooms++;
        }
        ind++;
    }

    if(numRooms==1){
        cout<<1<<" room, "<<flooring<<" square metre(s) left over"<<endl;
        return 0;
    }
    cout<<numRooms<<" rooms, "<<flooring<<" square metre(s) left over"<<endl;



}