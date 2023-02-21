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
        map<ll, ll>m;
        vector<ll>v;
        vector<ll>stringVec;
        for(ll i=0; i<s.length(); i++){
            m[s[i]-48]++;
            stringVec.push_back(s[i]-48);
        }

        for(ll lowest=0; lowest<10; lowest++){
            if(m[lowest]==0){
                continue;
            }
            ll p1;
            bool foundLowest=false;
            for(ll i=stringVec.size()-1; i>=0; i--){
                if(foundLowest==false&&stringVec[i]==lowest){
                    p1=i;
                    pq.push(stringVec[i]);
                    foundLowest=true;
                    // cout<<"appending: "<<stringVec[i]<<endl;
                    m[stringVec[i]]--;
                } else if(foundLowest==true&&stringVec[i]==lowest){
                    pq.push(stringVec[i]);
                    m[stringVec[i]]--;
                    // cout<<"appending: "<<stringVec[i]<<endl;
                } else if(foundLowest==true){
                    pq.push(min(stringVec[i]+1, (long long)9));
                    m[stringVec[i]]--;
                    // cout<<"appending: "<<min(stringVec[i]+1, (long long)9)<<endl;
                }
            }
            stringVec.erase(stringVec.begin(), stringVec.begin()+p1+1);
            // cout<<"erasing 0 - "<<p1<<endl;
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