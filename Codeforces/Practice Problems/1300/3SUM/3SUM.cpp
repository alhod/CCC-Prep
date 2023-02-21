#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){

    ll t;
    cin>>t;
    while(t--){

        ll n;
        cin>>n;

        map<ll, ll>m;
        vector<ll>complements;
        vector<ll>finalComplements;
        bool foundSolution = false;
        vector<string>inputs(n);

        for(ll i=0; i<n; i++){
            cin>>inputs[i];
        }


        for(ll i=0; i<n; i++){
            string num1 = inputs[i];
            ll num = int(num1[num1.length()-1])-48;

            //cout<<"num "<<num<<endl;


            if (m[num] == 3){
                continue;
            } else {
                m[num]++;
            }

            if (find(finalComplements.begin(), finalComplements.end(), num) != finalComplements.end()){
                foundSolution = true;
                break;
            }

            for (ll i : complements){
                if (i-num>=0 and find(finalComplements.begin(), finalComplements.end(), i-num) == finalComplements.end()){
                    finalComplements.push_back(i-num);
                }
            }

            for (auto i : {3, 13, 23}){
                if (i-num>=0 and find(complements.begin(), complements.end(), i-num) == complements.end()){
                    complements.push_back(i-num);
                }
            }

        }

        if (foundSolution == true){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }

}