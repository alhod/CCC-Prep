#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        vector<ll>s(n);
        vector<ll>a(n);
        for(ll i=0; i<n; i++){
            ll tmp;
            cin>>tmp;
            v[i] = tmp;
            s[i] = tmp;
        }

        sort(s.begin(), s.end());
        ll operations = 0;

        if (v == s){
            cout<<n-1<<endl;
            continue;
        }

        ll currGreatestDifference = 0;
        ll currGreatestInd = -1;
        ll distanceFromCenter = n;

        for(ll i=0; i<n; i++){
            if (v[i]-s[i] >= currGreatestDifference){
                currGreatestDifference = v[i]-s[i];
                currGreatestInd = i;
                if ((n/2)-i<distanceFromCenter){
                    distanceFromCenter = i;
            }
            }

            
        }
        
        v[currGreatestInd] = 0;
        for(ll i=currGreatestInd+1; i<n; i++){
            if (i==currGreatestInd+1){
                continue;
            }

            operations++;
            if (v[i]<v[i-1]){
                operations+=(v[i-1]/v[i]);
            }
        }

        for(ll i=currGreatestInd-1; i>-1; i--){
            if (i==currGreatestInd-1){
                continue;
            }

            operations++;
            if (v[i] < v[i+1]) {
                
            }
        }



    }

}