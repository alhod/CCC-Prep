#include <iostream>
#include <vector>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m; 
        vector<string>arr(n);
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        bool found = false;
        int col;
        int row;

        for (int i = 0; i<n; i++){
            if (found == true){
                break;
            }
            for (int j = 0; j<m; j++) {
                if (arr[i][j] == 'R') {
                    found = true;
                    col = j;
                    row = i;
                    break;
                }
            }
        }

        bool impossible = false;

        for (int i = row+1; i < n; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j] == 'R') {
                    impossible = true;
                    break;
                }
            }
        }

        if (impossible == false) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }

}