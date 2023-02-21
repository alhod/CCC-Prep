#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n, m; 
        cin>>n;
        cin>>m;
        vector<ll>a(n);
        for(ll i=0; i<n; i++){
            cin>>a[i];
        }
        ll k1; 
        cin>>k1;
        vector<ll>k(k1);
        for(ll i=0; i<k1; i++){
            cin>>k[i];
        }
        vector<vector<ll, ll>>a2;
        vector<vector<ll, ll>>b2;


        for (ll j=0; j<n; j++){
            ll val = a[j];
            ll numVal = 1;
            while (true){
                if (val%m==0){
                    val /= m;
                    numVal *= m;
                    continue;
                } else {
                    if (a2.empty() == false and a2[-1][0] == val){
                        a2[-1][1]+=numVal;
                    } else {
                        vector<ll, ll>tmp = {val, numVal};
                        a2.push_back(tmp);
                    }
                    break;
                }
            }
        }

        for (ll j=0; j<k1; j++){
            ll val = k[j];
            ll numVal = 1;
            while (true){
                if (val%m==0){
                    val /= m;
                    numVal *= m;
                    continue;
                } else {
                    if (b2.empty() == false and b2[-1][0] == val){
                        b2[-1][1] +=numVal;
                    } else {
                        b2.push_back({val, numVal});
                    }
                    break;
                }
            }
        }

        for(ll i=0; i<a2.size(); i++){
            cout<<a2[i][0]<<" "<<a2[i][1]<<endl;
        }

        bool imp = false;

        for(ll i=0; i<a2.size(); i++){
            if (a2[i][0] == b2[i][0] and a2[i][1] == b2[i][1]){
                continue;
            } else{
                imp == true;
                break;
            }
        }

        if (imp == true){
            cout<<"NO"<<endl;
        } else {
            cout<<"YES"<<endl;
        }

    }
}