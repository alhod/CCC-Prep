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
            // printf("new size %d and %d\n", sz[root1], sz[root2]);
            numComponents--;
        }
};



void solution(){    
    ll n, d;
    cin>>n>>d;

    vector<ll>nodes(n);
    for(ll i=0; i<n; i++){
        nodes[i]=i;
    }

    UnionFind uf=UnionFind(n, nodes);
    
    ll extra_edges=0;

    for(ll i=0; i<d; i++){
        ll a, b;
        cin>>a>>b;
        a--;
        b--;

        ll groupA=uf.Find(a);
        ll groupB=uf.Find(b);

        // printf("groupA: %d, groupB: %d\n", groupA, groupB);

        if(groupA==groupB){
            extra_edges++;
            // ll biggest_component=0;
            // ll biggest_component_node;
            // for(ll j=0; j<n; j++){
            //     if(uf.Find(j)!=groupA){
            //         printf("%d is not in group %d\n", j, groupA);
            //         if(uf.sz[j]>biggest_component){
            //             biggest_component=uf.sz[j];
            //             biggest_component_node=j;
            //         }
            //     }
            // }
            // b=biggest_component_node;
        } else {
            uf.Union(a, b);
        }
        

        // gets biggest component
        ll best=0;
        ll biggest_component_id;
        for(ll j=0; j<n; j++){
            // printf("size node %d is %d\n", j, uf.sz[j]);
            if(uf.sz[j]>best){
                best=uf.sz[j];
                biggest_component_id=j;
            }
        }

        // printf("biggest_component_id: %d, best: %d, extra_edges: %d\n", biggest_component_id, best, extra_edges);

        vector<ll>seen(n);
        vector<pair<ll, ll>>other_components;
        seen[biggest_component_id]=1;
        for(ll j=0; j<n; j++){
            ll curr_root=uf.Find(j);
            if(seen[curr_root]){
                continue;
            }
            other_components.emplace_back(uf.sz[curr_root], curr_root);
            seen[curr_root]=1;
        }

        sort(other_components.rbegin(), other_components.rend());

        ll copy=extra_edges;
        for(ll j=0; j<other_components.size()&&copy; j++){
            copy--;

            // uf.Union(other_components[j].second, biggest_component_id);
            best+=uf.sz[other_components[j].second];
        }


        // best=0;
        // for(ll j=0; j<n; j++){
        //     best=max(best, uf.sz[j]);
        // }


        cout<<best-1<<endl;
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}