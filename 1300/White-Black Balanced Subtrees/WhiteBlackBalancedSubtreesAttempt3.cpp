#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

int main() {

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        map<int, vector<int>>node_to_child;
        map<int, int>node_to_parent;
        map<int, int>node_to_color;
        for(int i=1;i<n+1;i++){
            node_to_child.insert(pair<int, vector<int>>(i, {}));
        }
        for(int i=2;i<n+1;i++){
            int tmp;
            cin>>tmp;
            node_to_child[tmp].push_back(i);
            node_to_parent.insert(pair<int, int>(i, tmp));
        }
        string colors;
        cin>>colors;
        for(int i=1;i<n+1;i++){
            if (colors[i-1] == 'W') {
                node_to_color[i]=1;
            } else {
                node_to_color[i]=-1;
            }
            
        }


        // layer-order traversal
        vector<int>queue;
        int curr;
        vector<int>correctOrderQueue;
        queue.push_back(1);
        while(!queue.empty()) {
            curr = queue[0];
            correctOrderQueue.insert(correctOrderQueue.begin(), queue[0]);
            queue.erase(queue.begin());
            for(int child : node_to_child[curr]) {
                queue.push_back(child);
            }
        }

        int totalBalancedSubtrees = 0;

        for (int node : correctOrderQueue) {
            if (node_to_color[node] == 0) {
                totalBalancedSubtrees++;
            }

            node_to_color[node_to_parent[node]]+=node_to_color[node];
        }

        cout<<totalBalancedSubtrees<<endl;
        // for (auto i : node_to_child) {
        //     cout<<i.first<<" --> ";
        //     for (int j : i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<"correctOrderQueue"<<endl;

        // for (int i : correctOrderQueue){
        //     cout<<i<<endl;
        // }
        
    }

    return 0;
}