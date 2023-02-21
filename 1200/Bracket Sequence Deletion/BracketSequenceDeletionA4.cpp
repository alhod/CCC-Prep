#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        string v;
        cin>>n>>v;
        int i = 0;
        int operations = 0;
        bool skip = false;
        bool imp = false;
        while(true){
            if (i >= n-1){
                cout<<operations<<" "<<n-i<<endl;
                break;
            }
            if (v[i] == '('){
                i+=2;
                operations++;
                continue;
            }
            if (v[i] == ')'){
                int j = i+1;
                while (true) {
                    if (v[j] == ')'){
                        i+=j+1;
                        operations++;
                        break;
                    }

                    if (j == n){
                        imp = true;
                        cout<<operations<<" "<<(j-i)+1<<endl;
                        break;
                    }
                    j++;
                }
            }

            if (imp == true){
                break;
            }
        }
    }

}