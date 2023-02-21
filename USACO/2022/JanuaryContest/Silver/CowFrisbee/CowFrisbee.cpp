#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    vector<ll>numToInd(n+1);
    for(ll i=0; i<n; i++){
        cin>>v[i];
        numToInd[v[i]]=i;
    }
    ll ans=0;
    set<ll>s;
    s.insert(numToInd[n]);
    for(ll i=n-1; i>0; i--){

        ll ind=numToInd[i];
        auto it=s.insert(ind).first;
        auto it2=next(it);
        auto it3=next(it, -1);

        if(it2!=end(s)){
            ans+=(*it2)-ind+1;
        }

        if(it!=begin(s)){
            ans+=ind-(*it3)+1;
        }
    }

    cout<<ans<<endl;
}

// void solution(){
//     ll n;
//     cin>>n;
//     vector<ll>v(n);
//     for(auto &d:v)cin>>d;
//     ll ans=0;
//     vector<ll>numToInd(n+1);
//     for(ll i=0; i<n; i++) numToInd[v[i]]=i;
//     set<ll>s;
//     for(int i=n; i; i--){
//         auto it=s.insert(numToInd[i]).first;
//         if(next(it)!=end(s))ans+=*next(it)-numToInd[i]+1;
//     }
//     reverse(v.begin(), v.end());
//     numToInd.clear();
//     numToInd.resize(n+1);
//     s.clear();
//     for(ll i=0; i<n; i++) numToInd[v[i]]=i;
//     for(int i=n; i; i--){
//         auto it=s.insert(numToInd[i]).first;
//         if(next(it)!=end(s))ans+=*next(it)-numToInd[i]+1;
//     }
//     cout<<ans<<endl;
// }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}