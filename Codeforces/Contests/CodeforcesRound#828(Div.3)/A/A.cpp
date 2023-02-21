#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    string s;
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    cin>>s;
    map<ll, vector<char>>m;
    for(ll i=0; i<n; i++){
        if(m[v[i]].size()==0){
            m[v[i]].push_back(s[i]);
            continue;
        }
        if(s[i]==m[v[i]][0]){
            continue;
        } else if(s[i]!=m[v[i]][0]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
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