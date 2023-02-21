#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, x;
    cin>>n>>x;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>pre(n+1);

    for(ll i=1; i<n+1; i++){
        ll p1=0;
        ll p2=i-1;
        ll best=-1e18;
        ll sum=0;
        for(ll l=p1; l<=p2; l++){
            sum+=v[l];
        }

        while(p2<n){
            best=max(best, sum);
            sum-=v[p1];
            p1++;
            p2++;
            sum+=v[p2];
        }

        pre[i]=best;
    }

    // for(auto i:pre){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    for(ll i=0; i<n+1; i++){
        ll best=0;
        for(ll j=0; j<n+1; j++){
            best=max(best, pre[j]+min(i, j)*x);
        }
        cout<<best<<" ";
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