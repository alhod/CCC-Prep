#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        priority_queue<ll>pq;
        ll lowest=10;
        map<ll, ll>m;
        vector<ll>v;
        for(ll i=0; i<s.length(); i++){
            if(s[i]-48<lowest){
                lowest=s[i]-48;
            }
            m[s[i]-48]++;
        }
        ll remainingLowest=m[lowest];
        for(ll i=0; i<s.length(); i++){
            if(remainingLowest==0){
                pq.push(s[i]-48);
            } else if(s[i]-48==lowest){
                pq.push(s[i]-48);
                remainingLowest--;
            } else {
                pq.push(min(s[i]-48+1, 9));
            }
        }
        while(pq.size()>0){
            v.push_back(pq.top());
            pq.pop();
        }
        for(ll i=v.size()-1; i>=0; i--){
            cout<<v[i];
        }
        cout<<endl;
    }
}