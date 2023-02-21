#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v1(n+1);
        vector<pair<ll, ll>>v;
        map<ll, ll>m;
        for(ll i=1; i<=n; i++){
            ll tmp;
            cin>>tmp;
            v1[i]=tmp;
        }
        for(ll i=1; i<=n; i++){
            if(v1[i]<i){
                v.push_back(pair<ll, ll>(i, v1[i]));
            }
        }
        for(auto i:v){
            m[i.second]++;
        }

        // cout<<"vector"<<endl;
        // for(auto i:v){
            // cout<<i.first<<" "<<i.second<<endl;
        // }
        // cout<<"map"<<endl;
        // for(auto i:m){
            // cout<<i.first<<" "<<i.second<<endl;
        // }

        ll tot=0;
        vector<ll>toErase;
        for(ll i=0; i<v.size(); i++){
            // cout<<"A"<<endl;
            // cout<<"erasing v[i].first: "<<v[i].first<<endl;
            m.erase(v[i].first);
            // cout<<"map"<<endl;
            // for(auto i:m){
                // cout<<i.first<<" "<<i.second<<endl;
            // }
            for(auto j:m){
                // cout<<"B"<<endl;
                // cout<<"new pair: "<<j.first<<" "<<j.second<<endl;
                if(j.first<=v[i].first){
                    // cout<<"erasing: "<<j.first<<" "<<j.second<<endl;
                    toErase.push_back(j.first);
                    // cout<<"map"<<endl;
                    // for(auto i:m){
                    //     cout<<i.first<<" "<<i.second<<endl;
                    // }
                    continue;
                }
                
                // cout<<"valid"<<endl;
                tot+=j.second;
            }
            for(auto i:toErase){
                m.erase(i);
            }
            toErase.clear();
        }
        // for(ll i=0; i<v.size(); i++){
        //     for(ll j=i+1; j<v.size(); j++){
        //         if(v[i].first<v[j].second){
        //             tot++;
        //         }
        //     }
        // }

        cout<<tot<<endl;
        // cout<<"------------"<<endl;
        
    }
}