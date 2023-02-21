#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    // cin>>n;
    cin>>n;
    vector<string>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll total1s=0, total0s=0, best=0;
    for(ll col=0; col<n; col++){
        ll line=0;
        for(ll i=0; i<n; i++){
            char curr=v[i][(col+i)%n];
            if(curr=='1'){
                total1s++;
                line++;
            } else {
                total0s++;
            }
        }

        best=max(line, best);
    }

    printf("%lld\n", n-best+total1s-best);
    
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