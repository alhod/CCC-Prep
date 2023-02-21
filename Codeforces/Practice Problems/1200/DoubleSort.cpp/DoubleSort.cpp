#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>initA(n);
        vector<ll>initB(n);
        for(ll i=0;i<n;i++) cin>>initA[i];
        for(ll i=0;i<n;i++) cin>>initB[i];
        vector<pair<ll, ll>>v(n);
        for(ll i=0;i<n;i++)v[i]=pair<ll,ll>(initA[i],initB[i]);

        // for(ll i=0;i<n;i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }

        // sort
        ll numSwaps=0;
        vector<pair<ll, ll>>swapPosition;
        for(ll i=1;i<n;i++){
            ll ind=i;
            while(true){
                if (ind<1) break;
                if(v[ind].first<v[ind-1].first){
                    swap(v[ind],v[ind-1]);
                } else if(v[ind].first==v[ind-1].first and v[ind].second<v[ind-1].second){
                    swap(v[ind],v[ind-1]);
                } else{
                    break;
                }
                swapPosition.push_back(pair<ll,ll>(ind-1+1, ind+1));
                ind--;
                numSwaps++;
            }
        }

        // for(ll i=0;i<n;i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }

        // check
        bool imp = false;
        sort(initA.begin(), initA.end());
        sort(initB.begin(), initB.end());
        for(ll i=0;i<n;i++){
            if(initA[i]!=v[i].first||initB[i]!=v[i].second){
                imp = true;
                cout<<-1<<endl;
                break;
            }
        }
        if(imp)continue;

        cout<<numSwaps<<endl;
        for(pair<ll,ll>aPair:swapPosition){
            cout<<aPair.first<<" "<<aPair.second<<endl;
        }

        
    }
}