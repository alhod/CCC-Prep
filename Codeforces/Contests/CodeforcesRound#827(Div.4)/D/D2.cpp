#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v(n+1);
    vector<ll>greatestInd(1002);
    for(ll i=1; i<n+1; i++){
        ll num;
        cin>>num;
        v[i]=num;
        greatestInd[num]=max(greatestInd[num], i);
    }
    ll best=-1;
    for(ll i=1000; i>=1; i--){
        if(greatestInd[i]==0){
            continue;
        }
        for(ll j=1000; j>=1; j--){
            if(greatestInd[j]>0&&gcd(i, j)==1){
                best=max(best, greatestInd[j]+greatestInd[i]);
            }
        }
    }
    cout<<best<<endl;
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