#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        queue<ll>q;
        for(ll i=0; i<n; i++){
            ll num;
            cin>>num;
            q.push(num);
        }
        vector<ll>v;
        for(ll i=n; i>=1; i--){
            ll count=1;
            while(true){
                ll curr=q.front();
                q.pop();
                if(curr==i){
                    v.push_back(count%i);
                    break;
                } else {
                    count++;
                    q.push(curr);
                }
            }
        }
        for(ll i=v.size()-1; i>=0; i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}