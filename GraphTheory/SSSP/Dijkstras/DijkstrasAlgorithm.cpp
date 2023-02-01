#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, vector<pair<ll, ll>>>adjacencyList;
priority_queue<pair<ll, ll>>pq;
// prioriy_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq; if you want max priority queue
map<ll, ll>dist;
map<ll, bool>visited;
ll startingNode=0;

map<ll, ll> dijkstras(){

    for(pair<ll, vector<pair<ll, ll>>>aNode:adjacencyList){  // initialize distance map
        dist[aNode.first]=1e18;
    }

    dist[startingNode]=0;
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
            }
            
        }

    }

    return dist;
}

