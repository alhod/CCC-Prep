#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;
    vector<ll>freqStart(5001);
    vector<ll>freqEnd(5001);
    for(ll i=0; i<n; i++){
        ll x, y;
        cin>>x>>y;
        freqStart[x]++;
        freqEnd[y]++;
    }

    vector<ll>winStart(10001);
    vector<ll>winEnd(10001);
    for(ll i=0; i<5001; i++){
        for(ll j=0; j<5001; j++){
            winStart[i+j]+=freqStart[i]*freqStart[j];
            winEnd[i+j]+=freqEnd[i]*freqEnd[j];
        }
    }

    ll sum=0;
    for(ll i=0; i<m*2+1; i++){
        sum+=winStart[i];
        cout<<sum<<endl;
        sum-=winEnd[i];
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}