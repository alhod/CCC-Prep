#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>>arr(n, vector<int>(m));
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<m; j++) {
                cin>>arr[i][j];
            }
        }


        // check for baddies
        vector<int>baddies;
        for (int i = 0; i<n; i++) {
            vector<int>copiedVector = vector<int>(arr[i].begin(), arr[i].end());
            sort(copiedVector.begin(), copiedVector.end());
            for (int j = 0; j<m; j++) {
                if (arr[i][j] != copiedVector[j]) {
                    baddies.push_back(j);
                    // cout<<"pushing back "<<j<<endl;
                }

                if (baddies.size() == 2) {
                    break;
                }

                if (baddies.size() == 3) {
                    cout<<"-1"<<endl;
                    break;
                }
            }
            if (baddies.size() == 3 || baddies.size() == 2) {
                break;
            }
        }

        if (baddies.size() == 3) {
            continue;
        }

        if (baddies.size() == 0) {
            cout<<"1 1"<<endl;
            continue;
        }

        if (baddies.size() == 2) {
            for (int i = 0; i<n; i++) {
                swap(arr[i][baddies[0]], arr[i][baddies[1]]);
            }
        }

        bool impossible = false;
        for (int i = 0; i < 2; i++) {
            cout<<baddies[i]<<endl;
        }

        for (int i = 0; i<n; i++) {
            vector<int>copiedVector = vector<int>(arr[i].begin(), arr[i].end());
            sort(copiedVector.begin(), copiedVector.end());
            for (int j = 0; j<m; j++) {

                if (arr[i][j] != copiedVector[j]) {
                    impossible = true;
                }

                if (impossible == true) {
                    cout<<"-1"<<endl;
                    break;
                }
            }
            if (impossible == true) {
                break;
            }
        }

        if (impossible == true) {
            continue;
        }

        cout<<baddies[0]+1<<" "<<baddies[1]+1<<endl;

    }

}