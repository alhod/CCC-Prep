#include<bits/stdc++.h>
#define ll long long
using namespace std;


class tarjans {
    // Create class by doing "tarjans tar(n, e, edgeList)"

    // Assumes the n nodes are numbered from [0, n)

    // If nodes are not numbered this way, then create
    // hash table to translate them into these numbers
    // and insert translated numbers into edgeList

    // Returns vector called lowlink, at which the lowlink
    // value of node i is represented by lowlink[i]

    // If two nodes have the same lowlink value, that means
    // they are a part of the same strongly connected 
    // component

    public:
        tarjans(ll nodes, ll edges, map<ll, vector<ll>>&edgeList){
            n = nodes;
            numEdges = edges;
            g = edgeList;
            ids.resize(n);
            low.resize(n);
            onStack.resize(n);    
        }

        vector<ll> run(){
            return findSccs();
        }

    private:
        ll n;
        ll numEdges;
        map<ll, vector<ll>>g;
        ll id=0;
        ll sccCount=0;


        vector<ll>ids;
        vector<ll>low;
        vector<bool>onStack;
        stack<ll>s;


        vector<ll> findSccs(){
            for(ll i=0; i<n; i++){
                ids[i]=-1;
            }

            for(ll i=0; i<n; i++){
                if(ids[i]==-1){
                    dfs(i);
                }
            }
            return low;
        }


        int dfs(ll at){
            s.push(at);
            onStack[at]=true;
            ids[at]=low[at]=id++;
            
            // Visit all neighbours & min low-link on callback
            for(ll to:g[at]){
                if(ids[to]==-1){
                    dfs(to);
                }
                if(onStack[to]){
                    low[at]=min(low[at], low[to]);
                }
            }

            // After having visited all the neighbours of 'at'
            // if we're at the start of a SCC empty the seen
            // stack until until we're back to the start of the SCC.
            if(ids[at]==low[at]){
                while(true){
                    ll node = s.top();
                    s.pop();
                    onStack[node]=false;
                    low[node]=ids[at];
                    if(node==at){
                        break;
                    }
                }
                sccCount++;
            }
            return 0;
        }
};


void solution(){
    ll n;
    cin>>n;

    ll sum=0;

    vector<pair<ll, ll>>nodes(n);
    for(ll i=0; i<n; i++){
        cin>>nodes[i].first>>nodes[i].second;
        nodes[i].first--;
        sum+=nodes[i].second;
    }

    map<ll, vector<ll>>adj;
    for(ll i=0; i<n; i++){
        adj[i].push_back(nodes[i].first);
    }

    tarjans scc(n, n, adj);
    vector<ll>low=scc.run();

    vector<ll>low_to_count(n);
    vector<ll>low_to_min_moo(n, 1e18);
    for(ll i=0; i<n; i++){
        low_to_count[low[i]]++;
        low_to_min_moo[low[i]]=min(low_to_min_moo[low[i]], nodes[i].second);
    }

    ll ans=0;
    for(ll i=0; i<n; i++){
        if(low_to_count[i]>1){
            ans+=low_to_min_moo[i];
        }
    }

    cout<<sum-ans<<endl;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}