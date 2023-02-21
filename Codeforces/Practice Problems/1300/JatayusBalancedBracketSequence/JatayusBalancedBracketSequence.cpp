#include<bits/stdc++.h>
#define ll long long
using namespace std;

class UnionFind{
    public:
        ll size;
        ll numComponents;
        vector<ll>sz;
        vector<ll>id;
        UnionFind(ll Size){
            size=numComponents=Size;
            sz.resize(Size);
            id.resize(Size);
            for(ll i=0; i<Size; i++){
                id[i]=i;
                sz[i]=1;
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
                sz[root2]+=sz[root1];
            } else {
                id[root1]=root2;
                sz[root1]+=sz[root2];
            }
            numComponents--;
        }
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        UnionFind uf = UnionFind(2*n);
        string s;
        cin>>s;
        stack<ll>sta;
        
        for(ll i=0; i<2*n-1; i++){
            bool imp = false;
            // cout<<"starting i: "<<i<<endl;
            if(s[i]==')'){
                continue;
            } else {
                sta.push(1);
            }
            for(ll j=i+1; j<2*n; j++){
                if(s[j]=='('){
                    sta.push(1);
                } else if(s[j]==')'){
                    if(sta.size()==0){
                        break;
                    } else {
                        sta.pop();
                    }
                }
                if(sta.size()==0){
                    // cout<<i<<" to "<<j<<" is a valid palindrome"<<endl;
                    uf.Union(i, j);
                }
            }
        }
        // for(auto i:m){
        //     cout<<"i.first: "<<i.first<<endl;
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        cout<<uf.numComponents<<endl;;


    }
}