#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--){

        ll n, s;
        cin>>n>>s;
        vector<ll>v(n);
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        ll bestLength = -1;
        ll qsum = 0;
        ll itemsInQ = 0;
        ll ind = 0;
        ll indToSubtractAt = 0;
        vector<ll>q;

        while (true){
            if (ind == n){
                break;
            }

            q.push_back(v[ind]);
            qsum += v[ind];
            itemsInQ++;

            if (qsum == s){
                if (itemsInQ > bestLength){
                    bestLength = itemsInQ;
                }
            }

            while (qsum > s){
                qsum-=q[indToSubtractAt];
                indToSubtractAt++;
                itemsInQ--;
            }

            ind++;
        }

        if (bestLength == -1){
            cout<<-1<<endl;
            continue;
        }

        cout<<n-bestLength<<endl;
        

    }

}