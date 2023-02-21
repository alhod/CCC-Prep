# include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        map<int,int>counter;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int val;
            cin>>val;
            counter[val]++;
        }

        int total = 0;

        for(auto it : counter) {
            if (it.second > 1) {
                total+= 2;
            } else {
                total++;
            }
        }

        cout << (total+1)/2 << endl;
    }

    return 0;
}