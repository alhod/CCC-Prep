// Time Complexity: O(V+E)
// Space Complexity: O(B^M) (B is maximum branching factor of search tree, M is maximum depth of 
//                   the state space) or O(V^2) (2D bridges array) or O(V+E) idk honestly

// Bridges are edges in a graph such that by removing these edges, the number of connected
// components would increase. (i.e. they disconnect the graph.)

// This bridge detecting algorithm uses Tarjan's strongly connected components algorithm, and 
// leverages lowlink and discovery values to detect bridges.
// Note:
//      This version will modify a 2D matrix of size V * V to reflect bridges.
//      If V>=10^5, bridges should be appended in pairs to a dynamic array instead to save
//      memory. Slight modifications to algorithm must be made in this scenario.  

// Condition for an edge from u --> v to be a bridge:
//      The DFS subtree rooted at v doesn't connect back to an ancestor of u, or to u itself.
//      (Thus low[v]>disc[u] for u-->v to be a bridge.)



#include<bits/stdc++.h>
#define ll long long
using namespace std;


// Recursively checks for bridges
// Condition for bridges:
//      u --> v is a bridge if the subtree rooted at node v
//      does not connect to an ancestor of u or to u itself
void _Bridges(map<ll, vector<ll>>&adj, ll u, vector<ll>&visited, vector<ll>&disc, vector<ll>&low, ll time, ll parent, vector<vector<bool>>&bridges){
    // Note:
    //      u --> current node
    //      v --> child node
    //      parent --> previous node
    
    // Set current node to visited
    visited[u]=true;

    // Increment time and set discovery and lowlink values
    disc[u]=low[u]=++time;

    // Iterates through children
    for(auto v:adj[u]){

        // If not visited
        if(!visited[v]){

            // Recurse, where new current node is v and parent is u
            _Bridges(adj, v, visited, disc, low, time, u, bridges);

            // Propagate lowlink value of child (callback)
            low[u]=min(low[u], low[v]);

            // Checks condition for bridge:
            // If lowlink value of v is lesser than or equal to the discovery
            // value of u, then its subtree connects back to an ancestor of 
            // u (low[v]<disc[u]) or its subtree connects back to u itself
            // (low[v]==disc[u]) and the condition is false.
            // Otherwise it is true and u --> v is a bridge.
            if(low[v]>disc[u]){

                // Record bridge
                bridges[v][u]=true;
                bridges[u][v]=true;
            }
        }

        // If already visited, check to make sure v is not previous node
        else if(v!=parent){

            // Propagate lowlink value from previously visited node
            low[u]=min(low[u], disc[v]);
        }
    }
}


// Detects bridges within a graph.
// Pass n (number of nodes), adj (adjacency list), and bridges (2D array at which 
// bridges[i][j]==true if the edge from i --> j, and vice versa, is a bridge).
void Bridges(ll n, map<ll, vector<ll>>&adj, vector<vector<bool>>&bridges){

    // Visited array
    vector<ll>visited(n, false);
    
    // Discovery value
    vector<ll>disc(n);

    // Lowlink value
    vector<ll>low(n);

    // Time and parent (i.e. previous node)
    ll time=0, parent=-1;

    // For disconnected graph
    for(ll u=0; u<n; u++){

        // Check for already visited
        if(!visited[u]){
            _Bridges(adj, u, visited, disc, low, time, parent, bridges);
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, e;
    cin>>n>>e;
    map<ll, vector<ll>>adj;
    for(ll i=0; i<e; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<vector<bool>>bridges(n, vector<bool>(n));
    Bridges(n, adj, bridges);

    for(auto i:bridges){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}