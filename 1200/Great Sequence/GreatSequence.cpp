#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n, x;
        cin>>n>>x;
        vector<ll>v(n);
        map<ll, ll>valToQuantity;
        for(int i=0; i<n; i++){
            ll tmp;
            cin>>tmp;
            v[i] = tmp;
            valToQuantity[tmp]++;
        }
        sort(v.begin(), v.end());

        ll ans = 0;

        for(ll i = 0; i<n; i++){
            if (valToQuantity[v[i]]>0){
                valToQuantity[v[i]]--;
                if (find(v.begin(), v.end(), v[i]*x) != v.end() and valToQuantity[v[i]*x]>0){
                    valToQuantity[v[i]*x]--;
                } else {
                    ans++;
                }
            }
        }

        cout<<ans<<endl;

    }

}