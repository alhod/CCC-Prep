#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct Edge {
    ll x, y, w;
    bool original;
    Edge (ll x, ll y, ll w, bool original){
        this->x=x;
        this->y=y;
        this->w=w;
        this->original=original;
    }
};

bool operator<(Edge a, Edge b){
    if(a.w!=b.w){
        return a.w<b.w;
    }

    if(a.original&&!b.original){
        return true;
    } else {
        return false;
    }
}

void init(ll arr[], ll size[], ll n){
    for(ll i=1; i<n+1; i++){
        arr[i]=i;
        size[i]=1;
    }
}

ll root(ll arr[], ll x){
    ll i=x;
    while(i!=arr[i]){
        i=arr[i];
        arr[i]=arr[arr[i]];
    }
    return i;
}

void Union(ll arr[], ll size[], ll x, ll y){
    ll root_x=root(arr, x);
    ll root_y=root(arr, y);

    if(size[root_x]<size[root_y]){
        arr[root_x]=root_y;
        size[root_y]+=size[root_x];
    } else {
        arr[root_y]=root_x;
        size[root_x]+=size[root_y];
    }
}

bool Find(ll arr[], ll x, ll y){
    return root(arr, x)==root(arr, y);
}


void solution(){
    ll n, m, d, x, y, z;
    ll days=0, c=0;
    vector<Edge>edges;

    cin>>n>>m>>d;

    for(ll i=0; i<m; i++){
        cin>>x>>y>>z;
        edges.push_back(Edge(x, y, z, i<n-1));
    }

    sort(edges.begin(), edges.end());

    ll connected[n+1];
    ll size[n+1];

    init(connected, size, n);

    Edge maxEdge(-1, -1, -1, false);
    
    for(ll i=0; i<edges.size()&&c<n-1; i++){
        Edge t=edges[i];
        if(!Find(connected, t.x, t.y)){
            Union(connected, size, t.x, t.y);
        } else {
            continue;
        }
        days+=!t.original;
        maxEdge=t;
        c++;
    }

    init(connected, size, n);

    if(!maxEdge.original){
        for(ll i=0; i<edges.size(); i++){
            Edge edge=edges[i];
            if(!Find(connected, edge.x, edge.y)){
                if(edge.w<maxEdge.w||(edge.w==maxEdge.w&&edge.original)){
                    Union(connected, size, edge.x, edge.y);
                } else if(edge.original&&edge.w<=d){
                    days--;
                    break;
                }
            }
        }
    }

    cout<<days<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}