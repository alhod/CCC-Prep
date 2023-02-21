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
        vector<ll>aSimple;
        vector<ll>kSimple;

        for (ll j=0; j<n; j++){
            for (ll i=1; i<99999; i++){
                ll thePower = pow(m, i);
                if (a[j]%thePower==0){
                    continue;
                } else {
                    for (ll x=0; x<pow(m, i-1); x++){
                        aSimple.push_back(a[j]/pow(m, i-1));
                    }
                    break;
                }
            }
        }

        for (ll j=0; j<k1; j++){
            for (ll i=1; i<99999; i++){
                ll thePower = pow(m, i);
                if (k[j]%thePower==0){
                    continue;
                } else {
                    for (ll x=0; x<pow(m, i-1); x++){
                        kSimple.push_back(k[j]/pow(m, i-1));
                    }
                    break;
                }
            }
        }

        if (aSimple.size() != kSimple.size()){
            cout<<"NO"<<endl;
            continue;
        }

        bool imp = false;

        // cout<<"----------aSimple----------"<<endl;
        // for(auto i:aSimple){
        //     cout<<i<<endl;
        // }
        // cout<<"----------done-------------"<<endl;

        // cout<<"----------kSimple----------"<<endl;
        // for(auto i:kSimple){
        //     cout<<i<<endl;
        // }
        // cout<<"----------done-------------"<<endl;

        for(ll i=0; i<aSimple.size(); i++){
            if (aSimple[i] != kSimple[i]){
                cout<<"NO"<<endl;
                imp = true;
                break;
            }
        }

        if (imp == true){
            continue;
        }

        cout<<"YES"<<endl;

        // printf("%s", "----------------------aSimple--------------\n");
        // for(ll i : aSimple){
        //     cout<<i<<endl;
        // }
        // printf("%s", "--------------------done------------------\n");

        // bool imp = false;
        // ll indAtK = 0;
        // ll ind = 0;
        // for(ll i=0; i<k1; i++){
        //     if (imp==true) break;

        //     ll currPower = 0;
        //     while (true){
        //         ll sum = accumulate(aSimple.begin(), aSimple.begin()+pow(m, currPower), 0);
        //         // cout<<"sum "<<sum<<endl;
        //         if (sum == k[i]){
        //             aSimple.erase(aSimple.begin(), aSimple.begin()+pow(m, currPower));
        //             // cout<<"new aSimple---------"<<endl;
        //             // for(ll i : aSimple){
        //             //     cout<<i<<endl;
        //             // }
        //             // printf("%s", "--------------------done------------------\n");

        //             break;

        //         if (sum > k[i] or pow(m, currPower)>aSimple.size()){
        //             imp = true;
        //             break;
        //         }

        //         if (sum<k[i]){
        //             currPower++;
        //         }
        //     }
        // }

        // if (imp == true){
        //     printf("%s\n", "NO");
        //     continue;
        // }

        // printf("%s\n", "YES");
        

    }

}