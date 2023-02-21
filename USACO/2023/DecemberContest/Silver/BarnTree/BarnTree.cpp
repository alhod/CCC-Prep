#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n;
ll root;
ll root_haybales;
ll total_haybales;
ll haybales_per_node;
vector<ll>haybales;
map<ll, vector<ll>>adj;
vector<ll>needed_haybales;
vector<tuple<ll, ll, ll>>ans;


// add the returned haybales to haybales[curr]
// have needed_haybales[curr]=(sum of needed_haybales[neighbors])+haybales_per_node-haybales[curr]
//      if less than 0, set to zero and return extra
ll dfs(ll curr, ll prev){
    // check leaf
    // printf("curr: %d, prev: %d\n", curr, prev);

    if(adj[curr].size()==1&&adj[curr][0]==prev){
        if(haybales[curr]==haybales_per_node){
            return needed_haybales[curr]=0;
        } else if(haybales[curr]>haybales_per_node){
            needed_haybales[curr]=0;
            ll extra=haybales[curr]-haybales_per_node;
            haybales[curr]=haybales_per_node;
            ans.push_back(tuple<ll, ll, ll>(curr, prev, extra));
            // printf("extra: %d\n", extra);
            return extra;
        } else if(haybales[curr]<haybales_per_node){
            needed_haybales[curr]=haybales_per_node-haybales[curr];
            return 0;
        }
    }


    for(auto neighbor:adj[curr]){
        if(neighbor==prev)continue;
        haybales[curr]+=dfs(neighbor, curr);
        needed_haybales[curr]+=needed_haybales[neighbor];
    }

    needed_haybales[curr]+=haybales_per_node-haybales[curr];
    if(needed_haybales[curr]<0){
        ll extra=needed_haybales[curr]*-1;
        needed_haybales[curr]=0;
        haybales[curr]=haybales_per_node;
        ans.push_back(tuple<ll, ll, ll>(curr, prev, extra));
        return extra;
    } else if(needed_haybales[curr]==0){
        return 0;
    } else {  // needed_haybales[curr]>0
        return 0;
    }
}


void dfs2(ll curr, ll prev){
    for(auto neighbor:adj[curr]){
        if(neighbor==prev)continue;

        if(needed_haybales[neighbor]>0){
            ans.push_back(tuple<ll, ll, ll>(curr, neighbor, needed_haybales[neighbor]));
            haybales[neighbor]+=needed_haybales[neighbor];
            haybales[curr]-=needed_haybales[neighbor];
            needed_haybales[neighbor]=0;
        }

        dfs2(neighbor, curr);
    }
}


void solution(){
    cin>>n;
    haybales.resize(n);
    needed_haybales.resize(n);
    root_haybales=-1;
    total_haybales=0;
    for(ll i=0; i<n; i++){
        ll x;
        cin>>x;
        haybales[i]=x;
        if(x>root_haybales){
            root=i;
            root_haybales=x;
        }
        total_haybales+=x;
    }

    haybales_per_node=total_haybales/n;

    for(ll i=0; i<n-1; i++){
        ll x, y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // printf("haybales_per_node: %d\n", haybales_per_node);

    dfs(root, -1);
    // cout<<"finished dfs"<<endl;
    // for(ll i=0; i<n; i++){
    //     cout<<needed_haybales[i]<<" ";
    // }
    // cout<<endl;
    dfs2(root, -1);


    // reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<get<0>(i)+1<<" "<<get<1>(i)+1<<" "<<get<2>(i)<<endl;
    }


    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}