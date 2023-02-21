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

    ll count=0;

    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){

            if(j>i){
                if(v[j]<=v[i]){
                    count++;
                }
            } else if(j<i){
                if(v[j]>=v[i]){
                    count++;
                }
            }
        }
    }

    cout<<count<<endl;
    
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