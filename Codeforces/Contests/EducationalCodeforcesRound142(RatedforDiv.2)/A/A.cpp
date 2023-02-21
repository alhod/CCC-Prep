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

    ll count_ones=0;
    for(ll i=0; i<n; i++){
        if(v[i]==1){
            count_ones++;
        }
    }

    if(count_ones%2==1){
        count_ones--;
    }

    cout<<count_ones/2+n-count_ones<<endl;
    
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