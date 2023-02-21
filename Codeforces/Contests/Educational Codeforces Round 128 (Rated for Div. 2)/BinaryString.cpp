#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int iterate_left(string arr) {
    
}

int main() {

    int t;
    cin>>t;
    while(t--) {
        string arr;
        cin>>arr;
        bool solved = false;
        int ind_left = 0;
        int ind_right = arr.length()-1;
        while (arr[ind_left] != '1') {
            if (ind_left >= arr.length()) {
                cout<<'0'<<endl;
                solved = true;
                break;
            }
            ind_left++;
        }
        arr = arr.substr(ind_left, arr.length());
        while (arr[ind_right] != '0') {
            if (ind_right < 0) {
                cout<<'0'<<endl;
                solved = true;
                break;
            }
            ind_right--;
        }
        arr = arr.substr(0, ind_right);

        if (solved == true) {
            continue;
        }


        int oneCount = 0;
        int zeroCount = count(arr.begin(), arr.end(), '0');


        
    }

}