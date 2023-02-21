# include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    map<int,int>counter;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            counter[val]++;
        }

        int total = 0;

        for(auto it : counter) {
            if (counter[it.second] > 1) {
                total+= 2;
            } else {
                total++;
            }
        }

        cout << (total+1)/2 << endl;
    }

    return 0;
}