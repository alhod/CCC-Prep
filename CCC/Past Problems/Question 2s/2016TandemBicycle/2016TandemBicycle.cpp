#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll type;
    cin>>type;
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>v1(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    for(ll i=0; i<n; i++){
        cin>>v1[i];
    }

    ll sum=0;

    if(type==1){
        sort(v.begin(), v.end());
        sort(v1.begin(), v1.end());

        for(ll i=0; i<n; i++){
            sum+=max(v[i], v1[i]);
        }
    } else {
        sort(v.begin(), v.end());
        sort(v1.rbegin(), v1.rend());

        for(ll i=0; i<n; i++){
            sum+=max(v[i], v1[i]);
        }
    }

    cout<<sum<<endl;
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}