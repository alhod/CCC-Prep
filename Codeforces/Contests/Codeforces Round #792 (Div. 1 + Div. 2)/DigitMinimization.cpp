#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        string n;
        cin>>n;
        int length = n.length();

        if (length == 1){
            cout<<n[0]<<endl;
            continue;
        } else if (length == 2){
            cout<<n[1]<<endl;
            continue;
        }

        vector<int>vals(n.length());
        for (int i = 0; i<n.length(); i++){
            vals[i] = n[i]-48;
        }

        cout<<*min_element(vals.begin(), vals.end())<<endl;

    }

}