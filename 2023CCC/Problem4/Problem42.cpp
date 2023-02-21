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
void KruskalsMST(ll n, ll e, vector<ll>&nodes, map<ll, vector<pair<ll, ll>>>&adj, ll &total_weight, map<ll, vector<pair<ll, ll>>>&MST){
    
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

        total_weight+=w;

        uf.Union(a, b);
        MST[a].push_back(pair<ll, ll>(b, w));
        MST[b].push_back(pair<ll, ll>(a, w));  // Assumes it is undirected graph, remove if not
    }
}


void solution(){
    ll n, m;
    cin>>n>>m;

    map<ll, vector<pair<ll, ll>>>adj;

    for(ll i=0; i<m; i++){
        ll x, y, l, c;
        cin>>x>>y>>l>>c;

        x--;
        y--;

        adj[x].push_back(pair<ll, ll>(y, c));
        adj[y].push_back(pair<ll, ll>(x, c));
    }

    vector<ll>nodes;
    for(ll i=0; i<n; i++){
        nodes.push_back(i);
    }

    ll total_weight=0;

    map<ll, vector<pair<ll, ll>>>MST;

    KruskalsMST(n, m, nodes, adj, total_weight, MST);

    cout<<total_weight<<endl;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}