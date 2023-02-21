#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll prev = -1;
        ll numSequence = 0;
        ll p1 = 0;
        vector<ll>v(n);
        bool impossible = false;
        for(int i=0; i<n; i++){
            ll tmp;
            cin>>tmp;

            if (i == n-1 and tmp != prev){
                impossible = true;
                break;
            }

            if (i == n-1){
                v[p1] = i;
                break;
            }

            if (prev == -1){
                prev = tmp;
                v[i+1] = i;
                numSequence = 1;
                p1=0;
                continue;
            }

            if (tmp != prev){
                if (numSequence == 1){
                    impossible = true;
                }
                v[p1] = v[i];
                v[i+1] = i;
                prev = tmp;
                numSequence = 1;
                p1 = i;
                continue;
            }

            v[i+1] = i;
            numSequence++;

            
        }

        if (impossible == true){
            cout<<-1<<endl;
            continue;
        } else {
            for(int i=0; i<n; i++){
                cout<<v[i]+1<<" ";
            }
        }
        cout<<endl;
    }

}