// Time Complexity: O(V+E)
// Space Complexity: O(V+E)

// An articulation point (AP) is a node in a graph such that removing this node
// (as well as connected edges) would increase the number of connected components
// (disconnect the graph).

// This algorithm for detecting articulation points uses Tarjan's algorithm for
// strongly connected components, by leveraging the lowlink and discovery values.

// Condition for a node u to be a articulation point:
//      1. u is the root of a DFS tree and it has >= 2 unvisited children.
//      2. u is not the root of a DFS tree, but there exists an unvisited child 
//         node v, such that the DFS subtree rooted at v doesn't connect back to 
//         an ancestor of u. (Thus, low[v]>=disc[u].)


#include<bits/stdc++.h>
#define ll long long
using namespace std;


// Recursive function
void _ArticulationPoints(map<ll, vector<ll>>&adj, ll u, vector<bool>&visited, vector<ll>&disc, vector<ll>&low, ll time, ll parent, vector<bool>&APs){
    // Note:
    //      u --> current node
    //      v --> child node
    //      parent --> previous node


    // Count of direct children in DFS tree
    ll children=0;

    // Set u to visited
    visited[u]=true;

    // Increment time, set discovery and lowlink value of u
    disc[u]=low[u]=++time;

    // Iterate through children
    for(auto v:adj[u]){
        
        // Check already visited
        if(!visited[v]){

            // Increment direct children
            children++;

            // Recurse, with v as new current node and u as parent node
            _ArticulationPoints(adj, v, visited, disc, low, time, u, APs);
            
            // Propagate lowlink value of child
            low[u]=min(low[u], low[v]);

            // If u is not root node (i.e. parent!=-1) and lowlink value
            // of child is greater than or equal to current node's discovery
            // value (meaning child is not connected to ancestor of 
            // current node, but may or may not connect back to current 
            // node or other nodes in subtree of current node) then current 
            // node is articulation point.
            if(parent!=-1&&low[v]>=disc[u]){

                // Record articulation point
                APs[u]=true;
            }

            // Note that if lowlink value of v < discovery value of u then
            // recursive function encountered ancestor of u, thus u is not
            // an articulation point.
        } 

        // Encountered previously visited node
        // Check it is not previous node
        else if(v!=parent){

            // Propagate discovery value of previously encountered node
            low[u]=min(low[u], disc[v]);
        }
    }

    // If current node is root (i.e. parent==-1) and it has >=2 direct 
    // children, then it is an articulation point
    if(parent==-1&&children>=2){
        APs[u]=true;
    }
}



// Articulation Points algorithm
// Pass: n (number of nodes), e (number of edges), adj (adjacency list), APs 
//      (boolean vector at which APs[i]=true if i is articulation point)
void ArticulationPoints(ll n, map<ll, vector<ll>>&adj, vector<bool>&APs){

    // Discovery value
    vector<ll>disc(n);

    // Lowlink value
    vector<ll>low(n);

    // Visited array
    vector<bool>visited(n, false);
    
    // Time discovered (for discovery value) and parent (i.e. previous node)
    ll time=0, par=-1;

    // For disconnected graph
    for(ll u=0; u<n; u++){
        if(!visited[u]){
            _ArticulationPoints(adj, u, visited, disc, low, time, par, APs);
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

    vector<bool>APs(n, false);
    ArticulationPoints(n, adj, APs);

    cout<<"Articulation Points: "<<endl;
    for(ll i=0; i<n; i++){
        if(APs[i]){
            cout<<i<<endl;
        }
    }

}