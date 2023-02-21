#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    map<ll, ll>m;
    for(ll i=0; i<n; i++){
        cin>>v[i];
        m[v[i]%10]++;
    }
    if(m[5]!=0){
        for(ll i=0; i<n; i++){
            v[i]=v[i]+v[i]%10;
        }
        for(ll i=1; i<n; i++){
            if(v[i]!=v[i-1]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        return 0;
    } else if(m[0]!=0){
        for(ll i=1; i<n; i++){
            if(v[i]!=v[i-1]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        return 0;
    } else {
        for(ll i=0; i<n; i++){
            while(v[i]%10!=2){
                v[i]=v[i]+v[i]%10;
            }
            v[i]%=20;
        }
        for(ll i=1; i<n; i++){
            if(v[i]!=v[i-1]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }
    
    
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