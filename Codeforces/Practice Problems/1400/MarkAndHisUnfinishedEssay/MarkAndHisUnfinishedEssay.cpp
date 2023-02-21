#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, c, q;
    cin>>n>>c>>q;
    string s;
    cin>>s;
    vector<pair<pair<ll, ll>, ll>>v;
    v.push_back(pair<pair<ll, ll>, ll>(pair<ll, ll>(1, s.length()), (ll)0));
    ll length=s.length();
    while(c--){
        ll p1, p2;
        cin>>p1>>p2;
        v.push_back(pair<pair<ll, ll>, ll>(pair<ll, ll>(v.back().first.second+1, v.back().first.second+1+p2-p1), length-(p1-1)));
        length+=p2-p1+1;
    }
    // for(auto i:v){
    //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }
    while(q--){
        ll k;
        cin>>k;
        while(true){
            if(k<=s.length()){
                cout<<s[k-1]<<endl;
                break;
            } else {
                for(auto i:v){
                    if(k>=i.first.first&&k<=i.first.second){
                        k-=i.second;
                        break;
                    }
                }
            }
        }
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