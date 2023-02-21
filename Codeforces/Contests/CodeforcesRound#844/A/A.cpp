#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll distFromPoint(ll w1, ll d1, ll w2, ll d2){
    return abs(w1-w2)+abs(d1-d2);
}


void solution(){
    ll w, d, h, a, b, f, g;
    cin>>w>>d>>h>>a>>b>>f>>g;

    ll ans=1e18;

    ll north=distFromPoint(a, b, w, b)+h+distFromPoint(w, b, f, g);
    ll south=distFromPoint(a, b, 0, b)+h+distFromPoint(0, b, f, g);
    ll east=distFromPoint(a, b, a, d)+h+distFromPoint(a, d, f, g);
    ll west=distFromPoint(a, b, a, 0)+h+distFromPoint(a, 0, f, g);

    cout<<min(north, min(south, min(east, west)))<<endl;
    
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