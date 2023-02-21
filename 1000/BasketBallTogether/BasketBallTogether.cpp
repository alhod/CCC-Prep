#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, d;
    cin>>n>>d;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    deque<ll>q;
    for(auto i:v){
        q.push_back(i);
    }
    ll numTeams=0;
    while(true){
        if(q.size()==0){
            break;
        }
        ll curr = q.front();
        q.pop_front();
        ll need = d/curr;
        if(q.size()<need){
            break;
        } else {
            while(need--){
                q.pop_back();
            }
            numTeams++;
        }

    }
    cout<<numTeams<<endl;
    
}