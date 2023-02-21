#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;

    vector<pair<ll, ll>>v;
    ll num=0;
    ll p1=1;
    ll p2=n*3;

    while(p1<p2){
        num++;
        v.push_back(pair<ll, ll>(p1, p2));
        p1+=3;
        p2-=3;
    }

    cout<<num<<endl;
    for(ll i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    
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