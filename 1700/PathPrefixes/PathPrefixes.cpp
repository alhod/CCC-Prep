#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
    ll to, a, b;
    Edge(ll to_val, ll a_val, ll b_val){
        to=to_val;
        a=a_val;
        b=b_val;
    }
};

ll n;
map<ll, vector<Edge>>adj;
vector<ll>pre_a;
vector<ll>pre_b;
vector<ll>back_track;
vector<ll>ans;
vector<ll>top;
vector<ll>node_to_ind;

pair<ll, ll> dfs(ll curr, ll prev, ll prea, ll preb, ll length){
    // printf("curr: %d, prev: %d, prea: %d, preb: %d\n", curr, prev, prea, preb);

    pre_a[curr]=prea;
    pre_b[curr]=preb;
    back_track[curr]=prev;
    
    ll ind=curr;

    ll new_length=length;
    for(auto neighbor:adj[curr]){
        if(neighbor.to==prev)continue;
        pair<ll, ll>ret=dfs(neighbor.to, curr, prea+neighbor.a, preb+neighbor.b, length+1);
        if(node_to_ind[ret.first]>node_to_ind[ind]){
            continue;
        }
        ind=ret.first;
        new_length=ret.second;
    }
    length=new_length;
    preb=pre_b[ind];
    while(preb>prea){
        ind=back_track[ind];
        preb=pre_b[ind];
        length--;
    }

    ans[curr]=length;
    // printf("end of curr: %d, prev: %d, prea: %d, preb: %d, returning: %d, ans[curr]=%d\n", curr, prev, prea, preb, ind, ans[curr]);
    return pair<ll, ll>(ind, length);

}


void TopologicalSort(ll n, ll e, vector<ll>&v, map<ll, vector<Edge>>&adj){
    vector<bool>visited(n, false);
    stack<ll>s;
    for(ll i=0; i<n; i++){
        if(!visited[i]){
            stack<ll>tmp;
            queue<ll>q;
            q.push(i);
            while(q.size()>0){
                ll curr=q.front();
                q.pop();
                tmp.push(curr);
                if(visited[curr]){
                    continue;
                }
                visited[curr]=true;
                for(auto neighbor:adj[curr]){
                    q.push(neighbor.to);
                }
            }
            while(tmp.size()>0){
                s.push(tmp.top());
                tmp.pop();
            }
        }
    }
    while(s.size()){
        v.push_back(s.top());
        s.pop();
    }
}


void solution(){
    cin>>n;
    pre_a.resize(n, 0);
    pre_b.resize(n, 0);
    ans.resize(n, 0);
    adj.clear();
    back_track.resize(n);
    back_track[0]=0;
    top.clear();
    node_to_ind.resize(n);

    for(ll i=1; i<n; i++){
        ll anc, a, b;
        cin>>anc>>a>>b;
        adj[anc-1].push_back(Edge(i, a, b));
    }

    TopologicalSort(n, n-1, top, adj);
    for(ll i=0; i<n; i++){
        node_to_ind[top[i]]=i;
    }

    // cout<<"top: "<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<top[i]<<" ";
    // }
    // cout<<endl;

    // cout<<"node_to_ind:"<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<node_to_ind[i]<<" ";
    // }
    // cout<<endl;


    dfs(0, -1, 0, 0, 0);

    for(ll i=1; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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