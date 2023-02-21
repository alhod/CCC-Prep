#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;

        if (n == 1) {
            int random_shit;
            cin>>random_shit;
            cout<<1<<endl;
            continue;
        }

        map<int, int>map_count;
        int counter = 0;

        for (int i = 0; i<n; i++) {
            int val;
            cin>>val;

            if (map_count.count(val) > 0 && map_count[val] == 2) {
                continue;
            } else if (map_count.count(val) > 0) {
                map_count[val]++;
            } else {
                map_count.insert(pair<int, int>(val, 0));
            }
            
            counter++;
        }

        cout<<counter/2<<endl;





    }

    return 0;
}