#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Edge {
    ll b, t, h;
    Edge(ll b, ll t, ll h){
        this->b=b;
        this->t=t;
        this->h=h;
    }
};


bool operator<(Edge a, Edge b){
    if(a.t!=b.t){
        return a.t<b.t;
    } else {
        return a.h<b.h;
    }
}


ll k, n, m;
map<ll, vector<Edge>>adj;


class dijkstras{
    // Create object by doing "dijkstras dij(start, nodes, adjList)".

    // Returns map, at which map[node]=distance of shortest path from
    // root node to this node.

    // If you want, you can also return "prev" vector to track path.
    // Just dfs through prev (curr = prev[curr]) and once
    // curr==prev[curr] then you have reached root node.

    public:
        dijkstras(ll start, map<ll, vector<Edge>>&adjList){
            startingNode=start;
            adjacencyList=adjList;  // where .first = node key and .second = weighted edge
        }

        vector<vector<ll>> run(){
            return runDijkstras();
        }

    private:
        ll startingNode=0;
        map<ll, vector<Edge>>adjacencyList;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
        // **IMPORTANT: This is min priority queue**
        // prioriy_queue<pair<ll, ll>>pq; if you want max priority queue
        
        vector<vector<ll>>dist;
        vector<bool>visited;
        vector<bool>in_queue;

        
        vector<vector<ll>> runDijkstras(){

            // note do not add to pq if node neighbor already in pq because if it already is then it means
            // the distance to neighboring node from different path is shorter than distance to neighboring node
            // from this path.
            //      **also it doesn't matter that much the distance used in the pq because the distance in the actual
            //      **dist array is determined by iterating through all possible hull costs
            //      then when we reach that node and iterate over all possible hull costs, we will set 
            //      dist[neighbor][hull cost]=dist[current][hull cost]+edge cost

            dist.resize(n, vector<ll>(k, 1e18));
            visited.resize(n, false);
            in_queue.resize(n, false);

            for(ll i=0; i<k; i++){
                dist[startingNode][i]=0;
            }

            pq.push(pair<ll, ll>(dist[startingNode][0], startingNode));
            in_queue[startingNode]=true;
            while(!pq.empty()){
                // curr.first = distance from edge to this node
                // curr.second = node id

                pair<ll, ll>curr = pq.top();
                pq.pop();

                // printf("curr: %d %d\n", curr.first, curr.second);

                in_queue[curr.second]=false;
                visited[curr.second]=true;

                for(Edge adjacentNode:adjacencyList[curr.second]){
                    // adjacentNode.first = node id
                    // adjacentNode.second = distance from edge to this node

                    // if(visited[adjacentNode.b]){
                    //     continue;
                    // }
                    // printf("adjacentNode: %d %d %d\n", adjacentNode.b, adjacentNode.t, adjacentNode.h);
                    for(ll j=0; j<k-adjacentNode.h; j++){
                        if(dist[curr.second][j]+adjacentNode.t<dist[adjacentNode.b][j+adjacentNode.h]){
                            dist[adjacentNode.b][j+adjacentNode.h]=dist[curr.second][j]+adjacentNode.t;
                            if(in_queue[adjacentNode.b]){
                                continue;
                            }
                            pq.push(pair<ll, ll>(dist[adjacentNode.b][j+adjacentNode.h], adjacentNode.b));
                            // in_queue[adjacentNode.b]=true;
                        }
                    }

                    
                    
                }

            }

            // also return "prev" array if you want to track path
            return dist;
        }


};


void solution(){
    cin>>k>>n>>m;
    for(ll i=0; i<m; i++){
        ll a, b, t, h;
        cin>>a>>b>>t>>h;
        a--;
        b--;
        Edge obj(b, t, h);
        Edge obj2(a, t, h);
        adj[a].push_back(obj);
        adj[b].push_back(obj2);
    }

    ll a, b;
    cin>>a>>b;
    a--;
    b--;


    dijkstras dij(a, adj);
    vector<vector<ll>>dist=dij.run();

    ll best=1e18;
    for(ll j=0; j<k; j++){
        best=min(best, dist[b][j]);
    }

    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<k; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<(best==1e18?-1:best)<<endl;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}