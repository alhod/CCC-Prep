#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
map<ll, vector<ll>>g;
ll id;
ll sccCount;

vector<ll>ids(10001);
vector<ll>low(10001);
vector<bool>onStack(10001);
stack<ll>s;


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

vector<ll> findSccs(){
    for(auto i:g){
        ids[i.first]=-1;
    }

    for(auto i:g){
        if(ids[i.first]==-1){
            dfs(i.first);
        }
    }
    return low;
}



map<ll, ll>dist;
map<ll, bool>visited;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;

map<ll, ll>dijkstras(ll start){
    dist.clear();
    visited.clear();
    
    for(auto i:g){
        dist[i.first]=10e8;
    }

    dist[start]=0;
    visited[start]=true;
    pq.push(pair<ll, ll>(0, start));

    while(!pq.empty()){
        pair<ll,ll> curr = pq.top();
        pq.pop();

        visited[curr.second]=true;

        for(auto adjNode:g[curr.second]){
            if(visited[adjNode]){
                continue;
            }
            if(curr.first+1<dist[adjNode]){
                dist[adjNode]=curr.first+1;
                pq.push(pair<ll, ll>(dist[adjNode], adjNode));
            }
        }
    }

    return dist;
}




int main(){

    ll n;
    cin>>n;
    while(n--){
        ll f1, f2;
        cin>>f1>>f2;
        g[f1].push_back(f2);
    }

    id = 0;
    sccCount = 0;

    vector<ll>lowLinkValues = findSccs();

    while(true){
        ll f1, f2;
        cin>>f1>>f2;

        if(f1==0&&f2==0){
            break;
        }

        if(lowLinkValues[f1]==lowLinkValues[f2]){
            map<ll, ll>dist = dijkstras(f1);
            cout<<"Yes "<<dist[f2]-1<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

	


    return 0;
}