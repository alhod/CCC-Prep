#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<ll>v(s.length());
        for(ll i=0; i<s.length(); i++){
            v[i]=s[i]-96;
        }

        vector<ll>ans;
        vector<pair<ll, ll>>tobe;
        ans.push_back(1);
        if(v[0]<v[s.length()-1]){
            for(ll i=1; i<s.length()-1; i++){
                if(v[i]>=v[0]&&v[i]<=v[s.length()-1]){
                    tobe.push_back(pair<ll, ll>(v[i], i+1));
                }
            }
            sort(tobe.begin(), tobe.end());
            for(auto i:tobe){
                ans.push_back(i.second);
            }
        } else if(v[0]>v[s.length()-1]){
            for(ll i=1; i<s.length()-1; i++){
                if(v[i]<=v[0]&&v[i]>=v[s.length()-1]){
                    tobe.push_back(pair<ll, ll>(v[i], i+1));
                }
            }
            sort(tobe.begin(), tobe.end(), greater<pair<ll, ll>>());
            for(auto i:tobe){
                ans.push_back(i.second);
            }
        } else if(v[0]==v[s.length()-1]){
            for(ll i=1; i<s.length()-1; i++){
                if(v[i]==v[0]){
                    ans.push_back(i+1);
                }
            }
        }
        ans.push_back(s.length());
        cout<<abs(v[0]-v[s.length()-1])<<" "<<ans.size()<<endl;
        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
        
        
    }
}