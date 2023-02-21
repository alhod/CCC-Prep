#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m, a, b;
    cin>>n>>m>>a>>b;
    map<ll, vector<ll>>adj;
    vector<ll>visited(n+1);
    for(ll i=0; i<m; i++){
        ll num1, num2;
        cin>>num1>>num2;
        adj[num1].push_back(num2);
        adj[num2].push_back(num1);
    }

    queue<ll>q;
    q.push(a);
    visited[a]=1;
    while(q.size()>0){
        ll curr=q.front();
        q.pop();
        for(auto i:adj[curr]){
            if(visited[i]==0){
                visited[i]=1;
                q.push(i);
            }
        }
    }

    cout<<(visited[b]==1?"GO SHAHIR!":"NO SHAHIR!")<<endl;
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}