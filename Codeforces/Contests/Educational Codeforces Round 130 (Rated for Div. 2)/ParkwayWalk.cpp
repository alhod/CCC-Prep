#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int total = 0;
        for (int i=0; i<n; i++){
            int tmp;
            cin>>tmp;
            total+=tmp;
        }
        total-=m;
        if (total<0){
            total = 0;
        }
        cout<<total<<endl;
    }

}
