#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, x;
    cin>>n>>x;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>seen(500005);
    for(ll i=0; i<n; i++){
        seen[v[i]]++;
    }

    ll fact=1;
    bool start=false;
    while(true){
        if(!seen[fact]){
            fact++;
            continue;
        }
        
        if(seen[fact]%(fact+1)==0){
            seen[fact+1]+=seen[fact]/(fact+1);
        } else {
            if(x<=fact){
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
            return;
        }
        fact++;
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}