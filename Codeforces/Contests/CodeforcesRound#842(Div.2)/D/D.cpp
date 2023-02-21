#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll recurse(ll ind, vector<ll>&v){
    if(ind==v[ind]){
        return 0;
    }

    swap(v[ind], v[v[ind]]);
    return 1+recurse(ind, v);
}


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1; i<=n; i++){
        cin>>v[i];
    }

    // find naturally occurring inversion
    pair<ll, ll>inversion=pair<ll, ll>(-1, -1);
    for(ll i=1; i<n+1; i++){
        if(v[i]==i+1){
            inversion=pair<ll, ll>(i+1, i); 
            break;
        } else if(i==v[i+1]){
            inversion=pair<ll, ll>(i, i+1);
            break;
        }
    }

    ll ans=0;
    // printf("inversion: %d %d\n", inversion.first, inversion.second);
    if(inversion!=pair<ll, ll>(-1, -1)){
        // cout<<"good"<<endl;
        for(ll i=1; i<=n; i++){
            if(v[i]==inversion.second){
                if(inversion.first==v[inversion.second]&&inversion.second==v[inversion.first]){
                    break;
                } else {
                    // printf("swap %d %d\n", inversion.first, i);
                    swap(v[inversion.first], v[i]);
                    ans++;
                    break;
                }
            }
        }
        // cout<<"v"<<endl;
        // for(ll i=0; i<n; i++){
            // cout<<v[i]<<" ";
        // }
        // cout<<endl;
        for(ll i=1; i<=n; i++){
            if(i==inversion.first||i==inversion.second){
                continue;
            } else if(v[i]!=i){
                ans+=recurse(i, v);
            }
        }
    } else {
        for(ll i=1; i<=n; i++){
            if(v[i]!=i){
                ans+=recurse(i, v);
            }
        }
        ans++;
    }

    cout<<ans<<endl;
    
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