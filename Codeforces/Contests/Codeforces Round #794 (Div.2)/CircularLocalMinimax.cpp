#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        vector<int>solved(n);
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }

        if (n% 2 != 0){
            cout<<"NO"<<endl;
        }

        int curr = *min_element(arr.begin(), arr.end());
        int ind = 0;

        while (ind < n) {

        }

    }

}