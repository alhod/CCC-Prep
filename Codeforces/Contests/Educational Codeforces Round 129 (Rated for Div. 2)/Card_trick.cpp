# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--) {
        int n, m;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++) {
            cin>>arr[i];
        }
        cin>>m;
        int shuffles = 0;
        for(int i = 0; i<m; i++) {
            int tmp;
            cin>>tmp;
            shuffles += tmp;
        }
        int ind = shuffles%n;
        cout<<arr[ind]<<endl;
    }

}