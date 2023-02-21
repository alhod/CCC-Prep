#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Edge {
    ll to, length, cost;
    Edge (ll to_val, ll length_val, ll cost_val){
        to=to_val;
        length=length_val;
        cost=cost_val;
    }
};

bool operator<(Edge a, Edge b){
    if(a.length!=b.length){
        return a.length<b.length;
    } else {
        return a.cost<b.cost;
    }
}


ll total_cost;


class dijkstras{

    public:
        dijkstras(ll start, vector<ll>&nodes, map<ll, vector<Edge>>&adjList){
            startingNode=start;
            nodesArr=nodes;
            adjacencyList=adjList;  // where .first = node key and .second = weighted edge
        }

        map<ll, ll>run(){
            return runDijkstras();
        }

    private:
        ll startingNode=0;
        vector<ll>nodesArr;
        map<ll, vector<Edge>>adjacencyList;

        priority_queue<Edge, vector<Edge>, greater<Edge>>pq;
        
        map<ll, ll>dist;
        map<ll, bool>visited;

        
        map<ll, ll> runDijkstras(){

            for(ll aNode:nodesArr){  // initialize distance map
                dist[aNode]=1e18;
            }

            dist[startingNode]=0;
            pq.push(Edge(startingNode, dist[startingNode], 0));

            while(!pq.empty()){
                // curr.first = distance from edge to this node
                // curr.second = node id

                Edge curr = pq.top();
                pq.pop();

                total_cost+=curr.cost;

                visited[curr.to]=true;
                for(Edge adjacentNode:adjacencyList[curr.to]){
                    // adjacentNode.first = node id
                    // adjacentNode.second = distance from edge to this node

                    if(visited[adjacentNode.to]==true){
                        continue;
                    }

                    if(curr.length+adjacentNode.length<dist[adjacentNode.to]){
                        dist[adjacentNode.to]=curr.length+adjacentNode.length;
                        pq.push(Edge(adjacentNode.to, dist[adjacentNode.to], adjacentNode.cost));
                    }
                    
                }

            }

            return dist;
        }


};



void solution(){
    ll n, m;
    cin>>n>>m;

    total_cost=0;

    map<ll, vector<Edge>>adj;

    for(ll i=0; i<m; i++){
        ll x, y, l, c;
        cin>>x>>y>>l>>c;
        
        x--;
        y--;
        
        adj[x].push_back(Edge(y, l, c));
        adj[y].push_back(Edge(x, l, c));
    }

    vector<ll>nodes;
    for(ll i=0; i<n; i++){
        nodes.push_back(i);
    }

    dijkstras dij(0, nodes, adj);


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}