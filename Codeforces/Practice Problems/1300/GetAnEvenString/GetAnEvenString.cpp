#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<ll>seen(27);
        ll m=0;
        for(ll i=0; i<s.length(); i++){
            // for(auto i:seen){
                // cout<<i<<" ";
            // }
            // cout<<endl;
            if(seen[s[i]-97]==1){
                // cout<<"seen "<<s[i]<<endl;
                memset(&seen[0], 0, sizeof(seen[0])*seen.size());
                m+=2;
            } else {
                // cout<<"not seen "<<s[i]<<endl;
                seen[s[i]-97]=1;
            }
        }
        cout<<s.length()-m<<endl;
    }
}