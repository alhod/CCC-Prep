#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int t;
    cin>>t;

    while (t--) {
        int n;
        cin>>n;

        vector<int>sorted(n);
        vector<int>unsorted(n);
        vector<int>to_sort(n);

        for (int i = 0; i < n; i++){
            int tmp;
            cin>>tmp;
            sorted[i] = tmp;
            unsorted[i] = tmp;
        }

        sort(sorted.begin(), sorted.end());


        // for (int i = 0; i<n; i++) {
        //    cout<<"sorted index "<<i<<" --> "<<sorted[i]<<endl;
        // }


        int to_sort_insertion_point = 0;

        for (int i = 0; i < n; i++) {
            if (unsorted[i] != sorted[i]) {
                to_sort[to_sort_insertion_point] = unsorted[i];
                to_sort_insertion_point++;
            }
        }


        // for (int i : to_sort) {
        //    cout<<"to_sort value --> "<<i<<endl;
        // }


        int curr = to_sort[0];

        for (int i = 1; i < to_sort_insertion_point; i++) {
            curr = (curr&to_sort[i]);
        }

        cout<<curr<<endl;
        // cout<<"----------------"<<endl;


        
        
    }

    return 0;
}