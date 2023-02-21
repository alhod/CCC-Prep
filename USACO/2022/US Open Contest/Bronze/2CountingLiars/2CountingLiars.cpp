#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll numg=0;
    ll numl=0;
    vector<ll>g;
    vector<ll>l;
    ll liars=10e8;
    for(ll i=0; i<n; i++){
        char type;
        cin>>type;
        ll dist;
        cin>>dist;
        if(type=='G'){
            numg++;
            g.push_back(dist);
        } else {
            numl++;
            l.push_back(dist);
        }
    }

    for(ll i=0; i<g.size(); i++){
        ll numInconsistent=0;
        for(ll j=0; j<l.size(); j++){
            if(l[j]<g[i]){
                numInconsistent++;
            }
        }
        liars=min(liars, numInconsistent);
    }
    for(ll i=0; i<l.size(); i++){
        ll numInconsistent=0;
        for(ll j=0; j<g.size(); j++){
            if(l[i]<g[j]){
                numInconsistent++;
            }
        }
        liars=min(liars, numInconsistent);
    }
    cout<<liars<<endl;
}