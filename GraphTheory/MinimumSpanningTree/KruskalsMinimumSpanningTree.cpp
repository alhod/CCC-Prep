// Time Complexity: O(Elog(V))
// Space Complexity: O(log(E))

// Kruskal's Minimum Spanning Tree is a MST algorithm. 

// MST:
//      A minimum spanning tree is a set of edges that connects all nodes in a graph with minimum weight.
//      Note: There can be multiple MSTs
//      Note: Assuming no negative edge weights, all MSTs have n-1 edges, thus they are called trees.

// Kruskal's MST:
//      Sorts all edges by increasing edge weight. Iterates through edges. Calls UnionFind.Find(a)==UnionFind.Find(b)
//      to see if node a is already connected to node b. If so, it continues iterating. If not, it will union 
//      UnionFind.Union(a, b) the two, include this edge in the MST, and add the weight of the edge to the total cost
//      of the MST.


#include<bits/stdc++.h>
#define ll long long
using namespace std;


class UnionFind{
    // Create object by doing "UnionFind obj(size, nodes)"

    // "Find(node)" method returns the root of the group that 
    // "node" belongs to

    // "Union(node1, node2)" method unions the groups that 
    // "node1" and "node2" belong to 

    public:
        ll size;  // number of nodes in total
        ll numComponents;  // number of components
        map<ll, ll>sz;  // size of component based on id
        // Note: sz[node] is only accurate if node is the root of the component

        map<ll, ll>id;  // id[node]=id of the node
        UnionFind(ll size, vector<ll>&nodes){
            size=numComponents=size;
            for(ll node:nodes){
                id[node]=node;
                sz[node]=1;
            }
        }

    public:
        ll Find(ll node){
            // Finds the root of node

            ll root=node;
            while(id[root]!=root){
                root=id[root];
            }

            ll next;
            ll start = node;
            while(id[start]!=start){
                next = id[start];
                id[start]=root;
                start = next;
            }
            return root;
        }

    public:
        void Union(ll node1, ll node2){
            // Unions two nodes together

            ll root1 = Find(node1);
            ll root2 = Find(node2);

            if(root1==root2){
                return;
            }

            if(sz[root1]>=sz[root2]){
                id[root2]=root1;
                sz[root1]+=sz[root2];
            } else {
                id[root1]=root2;
                sz[root2]+=sz[root1];
            }
            numComponents--;
        }
};


// Pass in "total_weight" which is the weight of the MST and "MST" which is an empty adjacency list to store the MST
void KruskalsMST(ll n, ll e, vector<ll>&nodes, map<ll, vector<pair<ll, ll>>>&adj, ll total_weight, map<ll, vector<pair<ll, ll>>>&MST){
    
    // Make sure you pass in empty total_weight and MST map
    total_weight=0;
    MST.clear();
    
    UnionFind uf(n, nodes);

    vector<tuple<ll, ll, ll>>edges;
    for(auto i:adj){
        for(auto j:i.second){
            edges.push_back(tuple<ll, ll, ll>(j.second, i.first, j.first));
        }
    }


    // Sort by increasing edge weight
    sort(edges.begin(), edges.end());


    for(auto i:edges){

        ll w=get<0>(i);
        ll a=get<1>(i);
        ll b=get<2>(i);

        if(uf.Find(a)==uf.Find(b)){
            continue;
        }

        uf.Union(a, b);
        MST[a].push_back(pair<ll, ll>(b, w));
        MST[b].push_back(pair<ll, ll>(a, w));  // Assumes it is undirected graph, remove if not
    }
}



void solution(){
    ll n, e;
    cin>>n>>e;
    
    map<ll, vector<pair<ll, ll>>>adj;
    for(ll i=0; i<e; i++){
        ll a, b, w;
        cin>>a>>b>>w;

        // Note that this is undirected weighted graph
        adj[a].push_back(pair<ll, ll>(b, w));
        adj[b].push_back(pair<ll, ll>(a, w));
    }

    ll total_cost;
    map<ll, vector<pair<ll, ll>>>MST;
    
    vector<ll>nodes;
    for(ll i=1; i<=n; i++){
        nodes.push_back(i);
    }
    KruskalsMST(n, e, nodes, adj, total_cost, MST);

    cout<<"This is one of the minimum spanning trees: "<<endl;
    for(auto i:MST){
        for(auto j:i.second){
            cout<<i.first<<" "<<j.first<<" "<<j.second<<endl;
        }
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}