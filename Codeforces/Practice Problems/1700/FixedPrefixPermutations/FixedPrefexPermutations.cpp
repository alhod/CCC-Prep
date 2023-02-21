#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll beauty(vector<ll>&a, vector<ll>&b){
    ll ret=0;
    for(ll i=0; i<a.size(); i++){
        if(a[i]==b[i]){
            ret++;
        } else {
            break;
        }
    }

    return ret;
}


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>>v(n, vector<ll>(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin>>v[i][j];
            v[i][j]--;
        }
    }

    vector<vector<ll>>inverses(n, vector<ll>(m));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            inverses[i][v[i][j]]=j;
        }
    }

    sort(inverses.begin(), inverses.end());

    vector<ll>ans(n);

    // cout<<"all inverses:"<<endl;
    // for(ll i=0; i<n; i++){
    //     for(ll j=0; j<m; j++){
    //         cout<<inverses[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(ll i=0; i<n; i++){
        auto iter=lower_bound(inverses.begin(), inverses.end(), v[i]);
        
        // cout<<"original"<<endl;
        // for(auto j:v[i]){
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        // cout<<"inverse: "<<endl;
        // for(auto j:*iter){
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        // if(iter!=inverses.begin()){
        //     cout<<"inverses 2:"<<endl;
        //     for(auto j:*(--iter)){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //     iter++;
        // }

        if(iter!=inverses.end()){
            ans[i]=max(ans[i], beauty(v[i], *iter));
        }
        if(iter!=inverses.begin()){
            ans[i]=max(ans[i], beauty(v[i], *(--iter)));
        }
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
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