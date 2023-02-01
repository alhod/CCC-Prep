#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, vector<ll>>m;
map<ll, ll>numFriends;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
map<ll, ll>dist;
map<ll, bool>visited;

map<ll, ll> dijkstras(ll startingNode){

    dist.clear();
    visited.clear();

    for(auto aNode:m){  // initialize distance map
        dist.insert(pair<ll, ll>(aNode.first, 10e8));
    }

    dist[startingNode]=0;
    pq.push(pair<ll, ll>(dist[startingNode], startingNode));

    while(!pq.empty()){
        pair<ll, ll>curr=pq.top();
        pq.pop();
        visited[curr.second]=true;

        for(ll i=0; i<51; i++){
            if(m[curr.second][i]==0){
                continue;
            }
            if(visited[i]==true){
                continue;
            }

            if(curr.first+1<dist[i]){
                dist[i]=curr.first+1;
                pq.push(pair<ll, ll>(dist[i], i));
            }
             
        }

    }

    // for(auto i:dist){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    return dist;

}

int main(){
    

    for(ll i=1; i<51; i++){
        vector<ll>aVec(51);
        m[i]=aVec;
    }
    for(auto i:{2, 1, 7, 5, 4, 3}){
        m[6][i]=1;
        m[i][6]=1;
    }

    numFriends[1]=1;
    numFriends[2]=1;
    numFriends[3]=4;
    numFriends[4]=3;
    numFriends[5]=3;
    numFriends[7]=2;
    numFriends[8]=2;
    numFriends[6]=6;
    numFriends[9]=3;
    numFriends[10]=2;
    numFriends[11]=2;
    numFriends[12]=3;
    numFriends[13]=3;
    numFriends[14]=1;
    numFriends[15]=2;
    numFriends[16]=2;
    numFriends[17]=2;
    numFriends[18]=2;
    m[5][4]=1;
    m[4][5]=1;
    m[5][3]=1;
    m[3][5]=1;
    m[3][4]=1;
    m[4][3]=1;
    m[3][15]=1;
    m[15][3]=1;
    m[15][13]=1;
    m[13][15]=1;
    m[13][14]=1;
    m[14][13]=1;
    m[13][12]=1;
    m[12][13]=1;
    m[12][11]=1;
    m[11][12]=1;
    m[11][10]=1;
    m[10][11]=1;
    m[12][9]=1;
    m[9][12]=1;
    m[10][9]=1;
    m[9][10]=1;
    m[8][9]=1;
    m[9][8]=1;
    m[7][8]=1;
    m[8][7]=1;
    m[16][17]=1;
    m[17][16]=1;
    m[17][18]=1;
    m[18][17]=1;
    m[18][16]=1;
    m[16][18]=1;
    

    while(true){
        char com;
        cin>>com;
        if(com=='i'){
            ll x, y;
            cin>>x>>y;
            if(m[x][y]!=1){
                m[x][y]=1;
                numFriends[x]++;
            }
            if(m[y][x]!=1){
                m[y][x]=1;
                numFriends[y]++;
            }
        } else if(com=='d'){
            ll x, y;
            cin>>x>>y;
            if(m[x][y]==1){
                m[x][y]=0;
                numFriends[x]--;
            }
            if(m[y][x]==1){
                m[y][x]=0;
                numFriends[y]--;
            }
            // cout<<"deleted friends: "<<x<<" and "<<y<<endl;
            // cout<<m[x][y]<<endl;
            // cout<<m[y][x]<<endl;
        } else if(com=='n'){
            ll x;
            cin>>x;
            cout<<numFriends[x]<<endl;
        } else if(com=='f'){
            vector<ll>v(51);
            ll x;
            cin>>x;
            ll totalNumFriends=0;
            for(ll i=0; i<51; i++){
                if(m[x][i]==1){
                    for(ll j=0; j<51; j++){
                        if(m[i][j]==1&&m[x][j]==0&&j!=x&&v[j]==0){
                            totalNumFriends++;
                            v[j]=1;
                        }
                    }
                }
            }
            cout<<totalNumFriends<<endl;
        } else if(com=='s'){
            ll x, y;
            cin>>x>>y;
            ll degreesOfSeparation=dijkstras(x)[y];
            if(degreesOfSeparation==10e8){
                cout<<"Not connected"<<endl;
            } else {
                cout<<degreesOfSeparation<<endl;
            }
        } else if(com=='q'){
            return 0;
        }
        
    }
}