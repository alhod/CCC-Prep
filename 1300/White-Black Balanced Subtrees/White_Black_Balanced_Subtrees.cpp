#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;

tuple<tuple<int, int>, int> recursor(int node, map<int, vector<int>>node_to_child, map<int, char>node_to_color, int total_balanced) {
    cerr<<"------------------call-------------------"<<endl;
    // base case
    if (node_to_child[node].empty()) {
        cerr<<"base case --> node "<<node<<endl;
        cerr<<"returning total_balanced --> "<<total_balanced<<endl;
        if (node_to_color[node] == 'W') {
            return tuple<tuple<int, int>, int>(make_tuple(1, 0), total_balanced);
        } else {
            return tuple<tuple<int, int>, int>(make_tuple(0, 1), total_balanced);
        }
    }
    cerr<<"not base case --> node "<<node<<endl;

    int total_white_children = 0;
    int total_black_children = 0;

    if (node_to_color[node] == 'W') {
        total_white_children++;
    } else {
        total_black_children++;
    }

    for (int child : node_to_child[node]) {
        auto returned_value = recursor(child, node_to_child, node_to_color, total_balanced);
        total_white_children += get<0>(get<0>(returned_value));
        total_black_children += get<1>(get<0>(returned_value));
        total_balanced = get<1>(returned_value);
    }

    if (total_white_children == total_black_children) {
        total_balanced++;
    }

    cerr<<"white children: "<<total_white_children<<endl;
    cerr<<"black children: "<<total_black_children<<endl;
    cerr<<"returning total_balanced --> "<<total_balanced<<endl;
    return tuple<tuple<int, int>, int>(make_tuple(total_white_children, total_black_children), total_balanced);
}



int main() {

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        map<int, vector<int>>node_to_child;
        map<int, char>node_to_color;
        for(int i=1;i<n+1;i++){
            node_to_child.insert(pair<int, vector<int>>(i, {}));
        }
        for(int i=2;i<n+1;i++){
            int tmp;
            cin>>tmp;
            node_to_child[tmp].push_back(i);
        }
        for(auto val : node_to_child) {
            cerr<<val.first<<" --> ";
            for (auto i : val.second) {
                cerr<<i<<" ";
            }
            cerr<<endl;
        }
        string colors;
        cin>>colors;
        for(int i=1;i<n+1;i++){
            node_to_color[i]=colors[i-1];
        }
        int answer;
        answer = get<1>(recursor(1, node_to_child, node_to_color, 0));
        cout<<answer<<endl;
        
    }

    return 0;
}