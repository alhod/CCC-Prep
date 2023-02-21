#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, q;
    cin>>n>>q;
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }
    ll initSum=0;
    ll numEven=0;
    ll numOdd=0;
    for(ll i=0; i<n; i++){
        if(v[i]%2==0){
            numEven++;
        } else {
            numOdd++;
        }
        initSum+=v[i];
    }
    while(q--){
        ll type;
        cin>>type;
        ll x;
        cin>>x;
        if(type==0){
            initSum+=numEven*x;
            if(x%2==0){

            } else {
                numOdd+=numEven;
                numEven=0;
            }
        } else {
            initSum+=numOdd*x;
            if(x%2==0){

            } else {
                numEven+=numOdd;
                numOdd=0;
            }
        }
        cout<<initSum<<endl;
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