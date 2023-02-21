#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    vector<ll>v2(n);
    for(ll i=0; i<n; i++){
        cin>>v2[i];
    }

    vector<ll>seen(n+1);
    ll p1=0;
    ll p2=0;
    ll op=0;
    while(p1<n){
        if(seen[v[p1]]==1){
            p1++;
            continue;
        }
        if(v[p1]==v2[p2]){
            seen[v2[p2]]=1;
            p1++;
            p2++;
        } else {
            seen[v2[p2]]=1;
            p2++;
            op++;
        }
    }

    cout<<op<<endl;
    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}