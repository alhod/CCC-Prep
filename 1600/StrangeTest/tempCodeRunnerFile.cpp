#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll firstBitDiff(ll a, ll b){
    ll count=0;
    ll copy=a;
    while(copy>1){
        copy>>=1;
        count++;
    }

    // printf("a: %d, b: %d, count: %d\n", a, b, count);

    for(ll i=count; i>=0; i--){
        ll tmp=(1<<i);
        if((a&tmp)&&!(b&tmp)){
            return i;
        }
    }

    return -1;
}


void solution(){
    ll a, b;
    cin>>a>>b;
    ll best=1e18;
    best=min(best, b-a);
    best=min(best, 1+(a|b)-b);
    ll firstBitDifference=firstBitDiff(a, b);

    // ll exp=(1<<(greatestPowerOf2(a)+1));
    // printf("greatestPowerOf2(%d) is %d, and exp=%d\n", a, greatestPowerOf2(a), exp);
    // printf("firstBitDifference: %d\n", firstBitDifference);

    ll exp=(1<<(1+firstBitDifference));

    if(firstBitDifference!=-1){
        best=min(best, 1+(a%exp)-(b%exp));
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