#include<bits/stdc++.h>
#define ll long long
using namespace std;
int solution(){
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=n-k; i<n; i++){
        cin>>v[i];
    }
    if(k==1){
        cout<<"YES"<<endl;
        return 0;
    }
    vector<ll>a(n);
    for(ll i=n-k+1; i<n; i++){
        a[i]=v[i]-v[i-1];
    }
    if(!is_sorted(a.begin()+n-k+1, a.end())){
        cout<<"NO"<<endl;
        return 0;
    }
    if(a[n-k+1]*(n-k+1)<v[n-k]){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        solution();
    }
}