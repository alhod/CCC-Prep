#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>v2(n);
    for(ll i=0; i<n; i++){
        if(i==0){
            v2[i]=v[i];
        } else {
            v2[i]=max(v2[i-1], v[i]);
        }
    }
    vector<ll>v3;
    map<ll, ll>vsum;
    ll sum=0;
    for(ll i=0; i<n; i++){
        sum+=v[i];
        if(i==n-1||v2[i]!=v2[i+1]){
            v3.push_back(v2[i]);
            vsum[v2[i]]=sum;
        }
    }
    for(auto i:v3){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:vsum){
        cout<<i.first<<" "<<i.second<<endl;
    }
    while(q--){
        ll num;
        cin>>num;
        ll left=-1;
        ll right=v3.size();
        while(right-left>1){
            ll mid=(left+right)/2;
            if(v3[mid]<=num){
                left=mid;
            } else if(v3[mid]>num){
                right=mid;
            }
        }
        cout<<vsum[v3[right]]<<" ";//vsum[*upper_bound(v3.begin(), v3.end(), num)]
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