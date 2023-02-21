#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

    int t;
    cin>>t;
    while(t--){

        ll n;
        string num;
        cin>>n>>num;
        ll total = n;
        for(ll i=0; i<n; i++){
            if (i == 0){
                continue;
            }
            if (num[i] == num[i-1]){
                continue;
            }
            total+=i;
        }
        cout<<total<<endl;

    }

}