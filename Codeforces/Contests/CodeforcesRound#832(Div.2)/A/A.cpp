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

    ll sumNeg=0;
    ll sumPos=0;

    for(ll i=0; i<n; i++){
        if(v[i]<0){
            sumNeg+=-1*v[i];
        } else {
            sumPos+=v[i];
        }
    }

    cout<<abs(sumNeg-sumPos)<<endl;
    
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