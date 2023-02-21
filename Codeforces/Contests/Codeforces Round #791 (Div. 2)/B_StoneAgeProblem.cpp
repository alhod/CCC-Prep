#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    map<int, int>indToVal;
    ll total = 0;
    ll query2 = 0;
    for(int i = 0; i<n; i++) {
        int tmp;
        cin>>tmp;
        total+=tmp;
        indToVal.insert(pair<int, int>(i, tmp));
    }

    while(q--){
        int t;
        cin>>t;
        if (t == 1){
            int i, x;
            cin>>i>>x;
            i--;
            if (indToVal[i] == 0){
                total-=query2;
            } else {
                total-=indToVal[i];
            }
            total+=x;
            indToVal[i] = x;
            cout<<total<<endl;
            continue;
        }
        
        if (t==2){
            int x;
            cin>>x;
            total = n*x;
            query2 = x;
            indToVal.clear();
            cout<<total<<endl;
            continue;
        }
    }
}