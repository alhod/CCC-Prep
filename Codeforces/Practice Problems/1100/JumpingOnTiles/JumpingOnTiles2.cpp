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
        map<ll, vector<ll>>m;
        ans.push_back(1);
        if(v[0]<v[s.length()-1]){
            for(ll i=1; i<s.length()-1; i++){
                if(v[i]>=v[0]&&v[i]<=v[s.length()-1]){
                    m[v[i]].push_back(i);
                }
            }
            for(ll i=v[0]; i<=v[s.length()-1]; i++){
                for(auto j:m[i]){
                    ans.push_back(j+1);
                }
            }
        } else if(v[0]>v[s.length()-1]){
            for(ll i=1; i<s.length()-1; i++){
                if(v[i]<=v[0]&&v[i]>=v[s.length()-1]){
                    m[v[i]].push_back(i);
                }
            }
            for(ll i=v[0]; i>=v[s.length()-1]; i--){
                for(auto j:m[i]){
                    ans.push_back(j+1);
                }
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