#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        if (n == 1){
            ll tmp;
            cin>>tmp;
            if (tmp%2!=0){
                cout<<-1<<endl;
            } else {
                cout<<tmp/2<<endl;
            }
            continue;
        }

        bool notOnes = false;

        ll total = 0;

        for(ll i=0; i<n; i++){
            ll num;

            if (num != 1){
                notOnes = true;
            }

            if (num%2!=0){
                num++;
            }
            total+=num;
        }

        if (notOnes == true){
            cout<<total/2<<endl;
        } else {
            cout<<-1<<endl;
        }
    }

}