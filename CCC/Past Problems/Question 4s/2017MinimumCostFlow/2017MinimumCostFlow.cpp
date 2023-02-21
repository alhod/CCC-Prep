#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<tuple<ll, ll, ll, ll>>edges;


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
        UnionFind(ll size){
            size=numComponents=size;
            for(ll i=0; i<size; i++){
                id[i]=i;
                sz[i]=1;
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
void KruskalsMST(ll n, ll e, map<ll, vector<tuple<ll, ll, ll>>>&adj, ll total_weight, vector<tuple<ll, ll, ll>>&MST){
    
    // Make sure you pass in empty total_weight and MST map
    total_weight=0;
    MST.clear();
    
    UnionFind uf(n);

    // vector<tuple<ll, ll, ll>>edges;
    // for(auto i:adj){
    //     for(auto j:i.second){
    //         edges.push_back(tuple<ll, ll, ll>(j.second, i.first, j.first));
    //     }
    // }


    // Sort by increasing edge weight
    sort(edges.begin(), edges.end());


    for(auto i:edges){

        ll w=get<0>(i);
        ll _=get<1>(i);
        ll a=get<2>(i);
        ll b=get<3>(i);

        if(uf.Find(a)==uf.Find(b)){
            continue;
        }

        uf.Union(a, b);
        MST.push_back(tuple<ll, ll, ll>(b, _, w));
        // MST[b].push_back(tuple<ll, ll, ll>(a, _, w));  // Assumes it is undirected graph, remove if not
    }
}



void solution(){
    ll n, e, d;
    cin>>n>>e>>d;

    map<ll, vector<tuple<ll, ll, ll>>>adj;
    
    for(ll i=0; i<e; i++){
        ll a, b, w;
        cin>>a>>b>>w;
        a--;
        b--;
        adj[a].push_back(tuple<ll, ll, ll>(b, (i<n-1?0:1), w));
        adj[b].push_back(tuple<ll, ll, ll>(a, (i<n-1?0:1), w));
        edges.push_back(tuple<ll, ll, ll, ll>(w, (i<n-1?0:1), a, b));
    }


    // map<ll, vector<tuple<ll, ll, ll>>>MST;

    sort(edges.begin(), edges.end());
    ll ans=0;
    tuple<ll, ll, ll>greatest_cost=tuple<ll, ll, ll>(-1, -1, -1);
    vector<tuple<ll, ll, ll>>MST;

    KruskalsMST(n, e, adj, 0, MST);
    
    for(auto i:MST){
        if(get<2>(i)>get<2>(greatest_cost)){
            greatest_cost=i;
        }

        if(get<1>(i)==0){
            continue;
        } else {
            ans++;
        }
    }


    if(get<1>(greatest_cost)==0){
        cout<<ans<<endl;
        return;
    }

    UnionFind uf(n);

    for(auto e:edges){
        if(uf.Find(get<2>(e))==uf.Find(get<3>(e))){
            continue;
        }

        if(get<0>(e)<get<2>(greatest_cost)||(get<0>(e)==get<2>(greatest_cost)&&get<1>(e)==0)){
            uf.Union(get<2>(e), get<3>(e));
        } else if(get<1>(e)==0&&get<0>(e)<=d){
            ans--;
            break;
        }
    }

    cout<<ans<<endl;



    




    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}