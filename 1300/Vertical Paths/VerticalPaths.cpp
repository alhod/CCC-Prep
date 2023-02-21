#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        map<ll, vector<ll>>adj;
        ll root=0;
        for(ll i=1; i<n+1; i++){
            if(v[i-1]==i){
                root=i;
            } else {
                adj[v[i-1]].push_back(i);
            }
        }
        vector<ll>visited(n+1);
        vector<vector<ll>>allPaths;
        vector<ll>order;

        ll numPaths=0;
        queue<ll>q;
        q.push(root);
        while(q.size()>0){
            ll curr=q.front();
            // cout<<"curr: "<<curr<<endl;
            q.pop();
            order.push_back(curr);
            for(auto i:adj[curr]){
                q.push(i);
            }
        }
        // cout<<"order size: "<<order.size()<<endl;

        for(ll i=0; i<order.size(); i++){
            // cout<<"considering "<<order[i]<<endl;
            if(visited[order[i]]==0){
                vector<ll>path;
                numPaths++;
                ll curr=order[i];
                // cout<<"new path, curr: "<<curr<<endl;
                while(true){
                    // cout<<"on path, curr: "<<curr<<endl;
                    if(adj[curr].size()==0){
                        path.push_back(curr);
                        allPaths.push_back(path);
                        visited[curr]=1;
                        // cout<<"terminate curr: "<<curr<<endl;
                        break;
                    } else {
                        path.push_back(curr);
                        visited[curr]=1;
                        curr=adj[curr][0];
                        // cout<<"non terminate curr: "<<curr<<endl;
                    }
                }
            }
        }

        cout<<numPaths<<endl;
        for(auto i:allPaths){
            cout<<i.size()<<endl;
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<endl;



    }
}