#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>bad(n);
    for(ll i=1; i<n; i++){
        if(2*v[i]<=v[i-1]){
            bad[i]=1;
        }
    }
    
    ll p1=0;
    ll p2=k;

    ll ans=0;
    ll numBad=0;

    for(ll i=p1+1; i<=p2; i++){
        if(bad[i]!=0){
            numBad++;
        }
    }

    while(p2<n){
        if(numBad==0){
            ans++;
        }
        p1++;
        if(bad[p1]==1){
            numBad--;
        }
        p2++;
        if(bad[p2]==1){
            numBad++;
        }
    }

    cout<<ans<<endl;


    
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