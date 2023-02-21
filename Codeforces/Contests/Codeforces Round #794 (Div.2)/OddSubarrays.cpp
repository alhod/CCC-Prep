#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            cin>>arr[i];
        }
        int ind = 0;
        int oddSubarrays = 0;
        int found = 0;
        while (ind < n){
            if (ind == 0){
                ind++;
                continue;
            }

            if ((arr[ind]<arr[ind-1]) && found == 0){
                oddSubarrays++;
                found = 1;
            } else {
                found = 0;
            }
            ind++;
        }
        cout<<oddSubarrays<<endl;
    }

}