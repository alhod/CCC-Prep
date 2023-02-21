#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        vector<char>solved;
        ll n;cin>>n;
        string s; cin>>s;
        ll bal = 0;
        for(ll i=0; i<n; i++){
            if(find(solved.begin(), solved.end(), s[i])==solved.end()){
                solved.push_back(s[i]);
                bal+=2;
            } else {
                bal++;
            }
        }
        cout<<bal<<endl;
    }
}