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


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>node_to_child(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        v[i]--;
        node_to_child[v[i]]=i;
    }

    vector<ll>nodes;
    for(ll i=0; i<n; i++){
        nodes.push_back(i);
    }

    UnionFind uf(n, nodes);

    for(ll i=0; i<n; i++){
        uf.Union(i, v[i]);
    }

    ll best=1e18;
    ll cycles=uf.numComponents;
    // for(ll i=0; i<n; i++){
    //     if(uf.Find(i)==i){
    //         cycles++;
    //     }
    // }

    for(ll i=0; i<n-1; i++){
        if(uf.Find(node_to_child[i])==uf.Find(node_to_child[i+1])){
            best=min(best, n-(cycles+1));
        } else {
            best=min(best, n-(cycles-1));
        }
    }

    cout<<best<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}