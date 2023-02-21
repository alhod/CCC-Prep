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

    vector<pair<ll, ll>>ans;
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }

    for(ll i=0; i<n; i+=2){
        if(v[i]==v[i+1]){
            ans.push_back(pair<ll, ll>(i+1, i+2));
        } else {
            ans.push_back(pair<ll, ll>(i+1, i+1));
            ans.push_back(pair<ll, ll>(i+2, i+2));
        }
    }

    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
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