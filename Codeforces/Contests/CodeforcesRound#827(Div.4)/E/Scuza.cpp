#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    vector<ll>v(n+1);
    vector<ll>vmax(n+1);
    for(ll i=1; i<n+1; i++){
        ll num;
        cin>>num;
        if(i==1){
            v[i]=num;
            vmax[i]=num;
        } else {
            v[i]=v[i-1]+num;
            vmax[i]=max(vmax[i-1], num);
        }
    }
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:vmax){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    while(q--){
        ll num;
        cin>>num;
        // cout<<"best ind: "<<max(upper_bound(vmax.begin(), vmax.end(), num)-vmax.begin()-1, (long long)0)<<endl;
        cout<<v[max(upper_bound(vmax.begin(), vmax.end(), num)-vmax.begin()-1, (long long)0)]<<" ";
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