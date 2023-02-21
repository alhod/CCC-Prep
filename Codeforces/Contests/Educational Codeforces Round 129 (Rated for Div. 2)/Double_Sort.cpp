#include <bits/stdc++.h>


using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr1(n);
        vector<int> arr2(n);
        vector<vector<int>> arr(n, vector<int>(2));
        vector<vector<int>> sortedArr(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin>>arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin>>arr2[i];
        }
        for (int i = 0; i < n; i++) {
            arr[i][0] = arr1[i];
            arr[i][1] = arr2[i];
            sortedArr[i][0] = arr1[i];
            sortedArr[i][1] = arr2[i];
        }

        sort(sortedArr.begin(), sortedArr.end());

        vector<int> postSortArr1(n);
        vector<int> sortedPostSortArr1(n);
        vector<int> postSortArr2(n);
        vector<int> sortedPostSortArr2(n);

        for (int i = 0; i < n; i++) {
            postSortArr1[i] = sortedArr[i][0];
            sortedPostSortArr1[i] = sortedArr[i][0];
            postSortArr2[i] = sortedArr[i][1];
            sortedPostSortArr2[i] = sortedArr[i][1];
        }

        sort(sortedPostSortArr1.begin(), sortedPostSortArr1.end());
        sort(sortedPostSortArr2.begin(), sortedPostSortArr2.end());

        bool impossible = true;

        for (int i = 0; i < n; i++) {
            if ((sortedPostSortArr1[i] != postSortArr1[i])||(sortedPostSortArr2[i] != postSortArr2[i])) {
                
            }
        }
        
        

        
    }


}