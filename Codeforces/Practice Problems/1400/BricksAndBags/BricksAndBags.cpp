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

    sort(v.begin(), v.end());

    ll smallest=v.front();
    ll greatest=v.back();

    stack<ll>s;

    for(ll i=1; i<n-1; i++){
        s.push(v[i]);
    }

    ll best=0;
    while(s.size()>=1){
        // cout<<"greatest: "<<greatest<<endl;
        // cout<<"lowest: "<<smallest<<endl;
        best=max(best, greatest-smallest+greatest-s.top());
        greatest=s.top();
        s.pop();
    }

    smallest=v.front();
    greatest=v.back();

    for(ll i=n-1; i>=1; i--){
        s.push(v[i]);
    }

    while(s.size()>=1){
        // cout<<"greatest: "<<greatest<<endl;
        // cout<<"lowest: "<<smallest<<endl;
        best=max(best, greatest-smallest+s.top()-smallest);
        smallest=s.top();
        s.pop();
    }

    cout<<best<<endl;

    
    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
        solution();
    }
}