#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>nums(n);
        vector<ll>v(n);
        bool impossible = false;
        for(ll i=0; i<n; i++){
            cin>>nums[i];
            v[i] = 0;
        }
        ll ind = n-1;

        while(ind>0){

            ll complement = nums[ind]-v[ind];
            if(complement>0){
                impossible = true;
                break;
            } else if(complement==0&&nums[ind]!=0){
                impossible = true;
                break;
            }
            v[ind]+=complement;
            v[ind-1]-=complement;
            ind--;
        }

        if (impossible == true){
            cout<<"NO"<<endl;
            continue;
        }

        if (v[ind] == nums[ind]){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }

}