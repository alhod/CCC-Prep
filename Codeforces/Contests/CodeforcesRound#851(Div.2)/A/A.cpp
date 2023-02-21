#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    ll num_2=0;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        num_2+=v[i]==2;
    }

    if(num_2%2){
        cout<<-1<<endl;
        return;
    }

    ll twos_encountered=0;
    for(ll i=0; i<n; i++){
        twos_encountered+=v[i]==2;
        if(twos_encountered==num_2/2){
            cout<<i+1<<endl;
            return;
        }
    }
    
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