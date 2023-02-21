#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        string num;
        cin>>n>>num;
        ll total = n;

        for (ll i=0; i<n; i++){
            if (i==0){
                continue;
            }
            if (num[i] == '0'){  // left 1 search from 0
                ll curr = i-1;
                ll found0 = true;
                while (true){
                    
                    if (num[curr] == '1'){
                        total++;
                        found0 = false;
                    }
                    if (num[curr] == '0'){
                        if (found0 == true){
                            break;
                        }
                        found0 = true;
                        total++;
                        
                    }
                    if (curr == 0){
                        break;
                    }
                    curr--;
                }
            }

            if (num[i] == '1'){ // left 0 search from 1
                ll curr = i-1;
                ll found1 = true;
                while (true){
                    if (num[curr] == '0'){
                        total++;
                        found1 = false;
                    }
                    if (num[curr] == '1'){
                        if (found1 == true){
                            break;
                        }
                        found1 = true;
                        total++;
                    }
                    if (curr == 0){
                        break;
                    }
                    curr--;
                }
            }
        }
        cout<<total<<endl;

    }

}