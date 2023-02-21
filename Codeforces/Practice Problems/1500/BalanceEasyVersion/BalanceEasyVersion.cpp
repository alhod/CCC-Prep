#include<bits/stdc++.h>
#define ll long long
using namespace std;


map<ll, ll>mex;
map<ll, bool>contains;

int solution(){
    char type;
    ll num;
    cin>>type>>num;
    if(type=='+'){
        contains[num]=true;
    } else {
        ll x=num;
        mex[x]=max(mex[x], x);
        while(contains[mex[x]]){
            mex[x]+=num;
        }
        cout<<mex[x]<<endl;
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