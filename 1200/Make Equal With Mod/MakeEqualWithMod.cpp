#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        ll ones = 0;
        for(int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            if (tmp==1){
                ones++;
            }
        }
        if (ones != 0 and ones != n){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }

    }

}