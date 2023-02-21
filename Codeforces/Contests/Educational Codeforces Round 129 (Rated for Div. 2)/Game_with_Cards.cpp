# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n;
        vector<int>alice_arr(n);
        for (int i=0;i<n;i++) {
            cin>>alice_arr[i];
        }
        cin>>m;
        vector<int>bob_arr(m);
        for (int i=0;i<m;i++) {
            cin>>bob_arr[i];
        }
        int max_alice = *max_element(alice_arr.begin(), alice_arr.end());
        int max_bob = *max_element(bob_arr.begin(), bob_arr.end());
        if (max_alice == max_bob) {
            cout<<"Alice\nBob"<<endl;
        } else if (max_alice > max_bob) {
            cout<<"Alice\nAlice"<<endl;
        } else {
            cout<<"Bob\nBob"<<endl;
        }
    }

}