#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;


tuple<int, int> recursor(int node, int totalBalancedSubtrees, map<int, vector<int>>node_to_child, map<int, int>node_to_color) {

    // base case
    if (node_to_child[node].empty()) {
        return tuple<int, int>(node_to_color[node], totalBalancedSubtrees);
    }


    int color = node_to_color[node];

    for (int child : node_to_child[node]) {
        auto return_value = recursor(child, totalBalancedSubtrees, node_to_child, node_to_color);
        color+=get<0>(return_value);
        totalBalancedSubtrees=get<1>(return_value);
    }

    if (color == 0) {
        totalBalancedSubtrees++;
    }

    return tuple<int, int>(color, totalBalancedSubtrees);
    

}


int main() {

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        map<int, vector<int>>node_to_child;
        map<int, int>node_to_color;
        for(int i=1;i<n+1;i++){
            node_to_child.insert(pair<int, vector<int>>(i, {}));
        }
        for(int i=2;i<n+1;i++){
            int tmp;
            cin>>tmp;
            node_to_child[tmp].push_back(i);
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
        cout<<get<1>(recursor(1, 0, node_to_child, node_to_color))<<endl;
        
    }

    return 0;
}