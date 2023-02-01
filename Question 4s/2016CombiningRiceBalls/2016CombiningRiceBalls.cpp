#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse(ll ind, ll n, map<ll, ll>&m, vector<ll>&v){
    // cout<<"vector: "<<endl;
    // for(auto i:v){
        // cout<<i<<" ";
    // }
    // cout<<endl;
    // cout<<"ind: "<<ind<<endl;

    if(m[ind]!=0){
        return m[ind];
    }

    // if(ind==n-1){
    //     ll maxVal=0;
    //     for(ll i=0; i<n; i++){
    //         maxVal=max(maxVal, v[i]);
    //     }
    //     return maxVal;
    // }

    ll best=0;
    for(ll i=0; i<n; i++){
        best=max(best, v[i]);
    }
    for(ll i=ind; i<n; i++){
        if(i<n-1&&v[i]==v[i+1]){
            vector<ll>newVec;
            for(ll j=0; j<n; j++){
                if(i==j){
                    newVec.push_back(v[i]+v[i+1]);
                } else if(j==i+1){
                    continue;
                } else {
                    newVec.push_back(v[j]);
                }
            }
            best=max(best, recurse(max((long long)0, i-2), n-1, m, newVec));
            // cout<<"callback to "<<ind<<endl;
        }
        if(i<n-2&&v[i]==v[i+2]){
            vector<ll>newVec;
            for(ll j=0; j<n; j++){
                if(j==i){
                    newVec.push_back(v[i]+v[i+1]+v[i+2]);
                } else if(j==i+1||j==i+2){
                    continue;
                } else {
                    newVec.push_back(v[j]);
                }
            }
            best=max(best, recurse(max((long long)0, i-2), n-2, m, newVec));
            // cout<<"callback to "<<ind<<endl;
        }
    }

    return m[ind]=best;
}

int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    map<ll, ll>m;
    cout<<recurse(0, n, m, v)<<endl;

    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}