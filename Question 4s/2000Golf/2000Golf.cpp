#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll recurse(ll d, ll n, vector<ll>*v, map<ll, ll>*m){
    if(d==0){
        return (*m)[d]=0;
    }
    
    if((*m)[d]!=0){
        return (*m)[d];
    }
    ll best=10e8;
    for(ll i=0; i<n; i++){
        if(d-(*v)[i]>=0){
            ll numStrokes=1+recurse(d-(*v)[i], n, v, m);
            if(numStrokes<best){
                best=numStrokes;
            }
        }
    }
    return (*m)[d]=best;
}

int main(){
    ll d;
    cin>>d;
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    map<ll, ll>m;
    ll val = recurse(d, n, &v, &m);
    if(val>=10e8){
        cout<<"Roberta acknowledges defeat."<<endl;
    } else {
        cout<<"Roberta wins in "<<val<<" strokes."<<endl;
    }
    

}