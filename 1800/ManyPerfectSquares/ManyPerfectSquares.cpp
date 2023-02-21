#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll n;
vector<ll>v;
ll best;

void haha(ll d, ll ai, ll aj){
    ll q=(aj-ai)/d+d;
    if(q%2==0){ // is integer
        q/=2;
        ll x=q*q-aj;
        if(x<0){
            return;
        }
        ll count=0;
        for(ll i=0; i<n; i++){
            ll u=sqrt(v[i]+x);
            if(u*u==v[i]+x){
                count++;
            }
        }  
        best=max(best, count);
    }
}


void factorization(ll ai, ll aj){
    
    for(ll i=1; i<=sqrt(aj-ai); i++){
        if((aj-ai)%i==0){
            haha(i, ai, aj);
            haha((aj-ai)/i, ai, aj);
        }
    }
}



void solution(){
    cin>>n;
    v.resize(n, 0);
    best=1;
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            factorization(v[i], v[j]);
        }
    }
    
    cout<<best<<endl;
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