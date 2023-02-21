#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        vector<pair<ll, ll>>ans;
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        ll op=0;
        if(v[0]%2==0){
            ll farthestEven=0;
            for(ll i=v.size()-1; i>=0; i--){
                if(v[i]%2==0){
                    farthestEven=i;
                    break;
                }
            }
            if(farthestEven==0){
                for(ll i=1; i<v.size(); i++){
                    op++;
                    ans.push_back(pair<ll, ll>(1, i+1));
                }
            } else {
                op++;
                ans.push_back(pair<ll, ll>(1, farthestEven+1));
                for(ll i=1; i<v.size(); i++){
                    if(i==farthestEven){
                        continue;
                    } else if(v[i]%2==0){
                        op++;
                        ans.push_back(pair<ll, ll>(i+1, farthestEven+1));
                    } else {
                        op++;
                        ans.push_back(pair<ll, ll>(1, i+1));
                    }
                }
            }
        } else {
            ll farthestOdd=0;
            for(ll i=v.size()-1; i>=0; i--){
                if(v[i]%2!=0){
                    farthestOdd=i;
                    break;
                }
            }
            if(farthestOdd==0){
                for(ll i=1; i<v.size(); i++){
                    op++;
                    ans.push_back(pair<ll, ll>(1, i+1));
                }
            } else {
                op++;
                ans.push_back(pair<ll, ll>(1, farthestOdd+1));
                for(ll i=1; i<v.size(); i++){
                    if(i==farthestOdd){
                        continue;
                    } else if(v[i]%2==0){
                        op++;
                        ans.push_back(pair<ll, ll>(1, i+1));
                    } else {
                        op++;
                        ans.push_back(pair<ll, ll>(i+1, farthestOdd+1));
                    }
                }
            }

        }
        cout<<op<<endl;
        for(auto i:ans){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}