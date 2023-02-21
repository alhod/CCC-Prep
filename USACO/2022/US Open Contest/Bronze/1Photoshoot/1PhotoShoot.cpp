#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll count=0;
    vector<ll>v;
    for(ll i=0; i<n; i+=2){
        if(s[i]==s[i+1]){
            continue;
        } else if(s[i]=='H'&&s[i+1]=='G'){
            v.push_back(0);
        } else {
            v.push_back(1);
        }
    }

    ll last=0;
    for(ll i=v.size()-1; i>=0; i--){
        if(v[i]!=last){
            last=v[i];
            count++;
        }
    }
    cout<<count<<endl;
}