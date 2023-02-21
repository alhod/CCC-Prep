#include<bits/stdc++.h>
#define ll long long
using namespace std;

int recurse(ll n, ll depth){
    if(n==0){
        return 0;
    }
    if(depth==16){
        return 15;
    }

    return 1+min(recurse((n*2)%32768, depth+1), recurse((n+1)%32768, depth+1));
}

int main(){
    ll n;
    cin>>n;
    for(ll i=0; i<n; i++){
        ll num;
        cin>>num;
        cout<<recurse(num, 0)<<endl;
    }
}