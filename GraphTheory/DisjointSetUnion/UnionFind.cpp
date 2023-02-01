#include<bits/stdc++.h>
#define ll long long
using namespace std;

// class UnionFind{

//     public:
//         ll size;
//         ll numComponents;
//         vector<ll>sz;
//         vector<ll>id;
//         UnionFind(ll Size){
//             size=numComponents=Size;
//             sz.resize(Size);
//             id.resize(Size);
//             for(ll i=0; i<Size; i++){
//                 id[i]=i;
//                 sz[i]=1;
//             }
//         }

//     public:
//         ll Find(ll node){
//             ll root=node;
//             while(id[root]!=root){
//                 root=id[root];
//             }

//             ll next;
//             ll start = node;
//             while(id[start]!=start){
//                 next = id[start];
//                 id[start]=root;
//                 start = next;
//             }
//             return root;
//         }

//     public:
//         void Union(ll node1, ll node2){
//             ll root1 = Find(node1);
//             ll root2 = Find(node2);

//             if(root1==root2){
//                 return;
//             }

//             if(sz[root1]>=sz[root2]){
//                 id[root2]=root1;
//                 sz[root2]+=sz[root1];
//             } else {
//                 id[root1]=root2;
//                 sz[root1]+=sz[root2];
//             }
//             numComponents--;
//         }
// };


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

int main(){
    ll n;
    cin>>n;


    UnionFind uf = UnionFind(n);


    ll c;
    cin>>c;
    while(c--){
        string in;
        cin>>in;
        if(in=="Find"){
            ll node;
            cin>>node;
            cout<<uf.Find(node)<<endl;
        } else if(in=="Union"){
            ll node1, node2;
            cin>>node1>>node2;
            uf.Union(node1, node2);
            cout<<"Done"<<endl;
        }
    }
}