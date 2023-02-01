#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n, w, d;
map<ll, vector<pair<ll, ll>>>adj;
vector<ll>perm;
vector<ll>perm_time;


class dijkstras{
    // Create object by doing "dijkstras dij(start, nodes, adjList)".

    // Returns map, at which map[node]=distance of shortest path from
    // root node to this node.

    // If you want, you can also return "prev" vector to track path.
    // Just dfs through prev (curr = prev[curr]) and once 
    // curr==prev[curr] then you have reached root node.
CodeforcesRound#847(Div.3)
    public:
        dijkstras(ll start, vector<ll>&nodes, map<ll, vector<pair<ll, ll>>>&adjList){
            startingNode=start;
            nodesArr=nodes;
            adjacencyList=adjList;  // where .first = node key and .second = weighted edge
        }

        map<ll, ll>run(){
            return runDijkstras();
        }

    private:
        ll startingNode=0;
        vector<ll>nodesArr;
        map<ll, ll>prev;
        map<ll, vector<pair<ll, ll>>>adjacencyList;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
        // prioriy_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq; if you want max priority queue
        
        map<ll, ll>dist;
        map<ll, bool>visited;

        
        map<ll, ll> runDijkstras(){
            // queue<ll>q;
            // vector<bool>seen(n);
            // q.push(n-1);

            // for(ll i=0; i<n; i++){
            //     dist[i]=1e9;
            // }

            // dist[n-1]=0;

            // while(q.size()>0){
            //     ll curr=q.front();
            //     q.pop();

            //     for(auto i:adj[curr]){
            //         if(seen[i.first]){
            //             continue;
            //         }

            //         dist[i.first]=dist[curr]+1;
            //         seen[i.first]=true;
            //         q.push(i.first);
            //     }
            // }

            // map<ll, ll>ret;
            // for(ll i=0; i<n; i++){
            //     ret[i]=dist[i];
            // }

            // return ret;


            for(ll aNode:nodesArr){  // initialize distance map
                dist[aNode]=1e18;
            }

            dist[startingNode]=0;
            prev[startingNode]=startingNode;
            pq.push(pair<ll, ll>(dist[startingNode], startingNode));

            while(!pq.empty()){
                // curr.first = distance from edge to this node
                // curr.second = node id

                pair<ll, ll>curr = pq.top();
                pq.pop();

                visited[curr.second]=true;
                for(pair<ll, ll>adjacentNode:adjacencyList[curr.second]){
                    // adjacentNode.first = node id
                    // adjacentNode.second = distance from edge to this node

                    if(visited[adjacentNode.first]==true){
                        continue;
                    }

                    if(curr.first+adjacentNode.second<dist[adjacentNode.first]){
                        dist[adjacentNode.first]=curr.first+adjacentNode.second;
                        pq.push(pair<ll, ll>(dist[adjacentNode.first], adjacentNode.first));
                        prev[adjacentNode.first]=curr.second;
                    }
                    
                }

            }

            // also return "prev" array if you want to track path
            return dist;
        }


};


void solution(){
    cin>>n>>w>>d;

    perm.resize(n);
    perm_time.resize(n);

    for(ll i=0; i<w; i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        adj[y].push_back(pair<ll, ll>(x, 1));
    }

    for(ll i=0; i<n; i++){
        cin>>perm[i];
        perm[i]--;
        perm_time[perm[i]]=i;
    }

    vector<ll>nodes;
    for(ll i=0; i<n; i++){
        nodes.push_back(i);
    }


    dijkstras dij(n-1, nodes, adj);
    map<ll, ll>dist=dij.run();


    // map<ll, ll>dist;
    // queue<ll>q;
    // vector<bool>seen(n);
    // q.push(n-1);

    // for(ll i=0; i<n; i++){
    //     dist[i]=1e9;
    // }

    // dist[n-1]=0;

    // while(q.size()>0){
    //     ll curr=q.front();
    //     q.pop();

    //     for(auto i:adj[curr]){
    //         if(seen[i.first]){
    //             continue;
    //         }

    //         dist[i.first]=dist[curr]+1;
    //         seen[i.first]=true;
    //         q.push(i.first);
    //     }
    // }
    
    multiset<pair<ll, ll>>best_time;

    for(ll i=0; i<n; i++){
        best_time.insert({dist[i]+perm_time[i], i});
    }


    while(d--){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;

        best_time.erase({dist[perm[x]]+x, perm[x]});
        best_time.erase({dist[perm[y]]+y, perm[y]});
        best_time.insert({dist[perm[y]]+x, perm[y]});
        best_time.insert({dist[perm[x]]+y, perm[x]});
        swap(perm[x], perm[y]);
        // best_time.insert(dist[perm[x]]+x);
        // best_time.insert(dist[perm[y]]+y);

        // perm_time[perm[x]]=x;
        // perm_time[perm[y]]=y;

        // ll best=1e18;
        // for(ll i=0; i<n; i++){
        //     best=min(best, perm_time[i]+dist[i]);
        // }

        cout<<(*best_time.begin()).first<<endl;
    }

    // for(ll i=0; i<n; i++){
    //     best_time.insert(dist[i]+perm_time[i]);
    // }


    // while(d--){
    //     ll x, y;
    //     cin>>x>>y;
    //     x--;
    //     y--;

    //     best_time.erase(dist[perm[x]]+x);
    //     best_time.erase(dist[perm[y]]+y);

    //     swap(perm[x], perm[y]);
    //     // swap(perm_time[perm[x]], perm_time[perm[y]]);

    //     best_time.insert(dist[perm[x]]+x);
    //     best_time.insert(dist[perm[y]]+y);

    //     cout<<*best_time.begin()<<endl;
    // }

    
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}