#include<bits/stdc++.h>
#define ll long long
using namespace std;


void dfs(vector<vector<int>>&edges, vector<int>& component, int currv, int id){
    for(int child: edges[currv]){
        if(component[child]!=id){
            component[child]=id;
            dfs(edges, component, child, id);
        }
    }
}


void solution(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>>edges(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int>component(n);
    iota(component.begin(), component.end(), 0);
    for(int i=0; i<n; i++){
        if(component[i]==i){
            dfs(edges, component, i, i);
        }
    }
    
    if(component[0]==component[n-1]){
        cout<<0<<endl;
        return;
    }

    vector<vector<int>>componentToVertices(n);

    for(int i=0; i<n; i++){
        componentToVertices[component[i]].push_back(i);
    }
  
    ll ans=1e18;
    vector<ll>srcCost(n, 1e9);
    vector<ll>dstCost(n, 1e9);
    int srcidx=0;
    int dstidx=0;

    for(int i=0; i<n; i++){
        while(srcidx<componentToVertices[0].size()){
            srcCost[component[i]]=min(srcCost[component[i]], (ll)abs(i-componentToVertices[component[0]][srcidx]));
            if(componentToVertices[component[0]][srcidx]<i)srcidx++;
            else break;
        }
        if(srcidx)srcidx--;
        while(dstidx<componentToVertices[component[n-1]].size()){
            dstCost[component[i]]=min(dstCost[component[i]], (ll)abs(i-componentToVertices[component[n-1]][dstidx]));
            if(componentToVertices[component[n-1]][dstidx]<i)dstidx++;
            else break;
        }
        if(dstidx)dstidx--;
    }
    for(int i=0; i<n; i++)ans=min(ans, srcCost[i]*srcCost[i]+dstCost[i]*dstCost[i]);
    cout<<ans<<endl;
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