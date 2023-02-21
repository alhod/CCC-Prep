#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    vector<ll>tmp;
    vector<ll>tmp2;

    vector<ll>ans(n);


    for(ll i=(n-1)/2; i>=0; i--){
        tmp.push_back(v[i]);
    }

    for(ll i=(n-1)/2+1; i<n; i++){
        tmp2.push_back(v[i]);
    }

    for(ll i=0; i<n; i++){
        ans[i]=(i%2?tmp2[i/2]:tmp[i/2]);
    }

    for(ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;



    
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}