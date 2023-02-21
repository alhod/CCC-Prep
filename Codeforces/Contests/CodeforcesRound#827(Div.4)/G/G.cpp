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
    vector<vector<ll>>bases(33);
    for(ll i=0; i<n; i++){
        // cout<<"log "<<v[i]<<" is "<<log2(v[i])<<endl;
        bases[log2(v[i])].push_back(v[i]);
    }
    vector<ll>ans;
    ans.push_back(0);
    map<ll, ll>toSubtract;
    // for(ll i=0; i<33; i++){
    //     if(bases[i].size()==0){
    //         continue;
    //     }
    //     cout<<"i: "<<i<<endl;
    //     for(auto j:bases[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    for(ll i=30; i>=0; i--){
        ll best=0;
        for(ll j=0; j<bases[i].size(); j++){

            // cout<<"ans.back(): "<<ans.back()<<endl;
            // cout<<"best: "<<best<<endl;
            // cout<<"bases[i][j]: "<<bases[i][j]<<endl;
            if((ans.back()|best)>=(ans.back()|bases[i][j])){
                continue;
            } else {
                best=bases[i][j];
            }
        }
        if(best==0){
            continue;
        } else {
            ans.push_back(best);
            toSubtract[best]++;
        }
    }
    for(ll i=0; i<n; i++){
        if(toSubtract[v[i]]>0){
            toSubtract[v[i]]--;
        } else {
            ans.push_back(v[i]);
        }
    }
    for(ll i=1; i<n+1; i++){
        cout<<ans[i]<<" ";
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