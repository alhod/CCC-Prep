#include <bits/stdc++.h>
#define ll long long
using namespace std;

string caseEven(ll n){
    ll lowest=-1;ll lowestInd;
    for(ll i=1;i<n+1;i++){
        ll tmp;cin>>tmp;
        if(tmp<lowest||lowest==-1)lowest=tmp,lowestInd=i;
    }
    return(lowestInd%2==0?"Mike":"Joe");
}

string caseOdd(ll n){
    for(ll i=1;i<n+1;i++){
        ll tmp;cin>>tmp;
    }
    return("Mike");
}

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n; string answer;
        if (n%2==0) answer = caseEven(n);
        else answer = caseOdd(n);
        cout<<answer<<endl;
    }
}