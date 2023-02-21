#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>ans;
    ll ind=0;
    while(ind<v.size()){
        ll smal=0;
        vector<ll>seen(n+1);
        ll latestUpdate=v.size()-1;
        for(ll i=ind; i<v.size(); i++){
            seen[v[i]]++;
            while(seen[smal]>0){
                latestUpdate=i;
                smal++;
            }
        }
        ind = latestUpdate+1;
        ans.push_back(smal);
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}