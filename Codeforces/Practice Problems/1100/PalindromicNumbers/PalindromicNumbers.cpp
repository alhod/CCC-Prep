#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){

        ll n, num;
        cin>>n>>num;
        ll total = 0;

        if (long(pow(10, n))-num<=long(pow(10, n-1))){
            string s = "";
            for (ll i=0; i<n; i++){
                s = s + "1";
            }
            ll s1 = stoi(s);
            cout<<long(pow(10, n))-num+s1<<endl;
        } else {
            string s = "";
            for (ll i=0; i<n; i++){
                s = s + "9";
            }
            ll s1 = stoi(s);
            cout<<s1-num<<endl;
        }
    }
}
