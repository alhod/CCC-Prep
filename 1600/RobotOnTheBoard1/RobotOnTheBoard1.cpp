#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, m;
    cin>>n>>m;

    string s;
    cin>>s;
    ll currHorizontal=0;
    ll currVertical=0;
    ll farthestLeft=0;
    ll farthestRight=0;
    ll farthestUp=0;
    ll farthestDown=0;

    for(ll i=0; i<s.length(); i++){
        if(s[i]=='L'){
            currHorizontal--;
            farthestLeft=min(farthestLeft, currHorizontal);
            if(farthestRight-farthestLeft>=m){
                farthestLeft++;
                break;
            }
        } else if(s[i]=='R'){
            currHorizontal++;
            farthestRight=max(farthestRight, currHorizontal);
            if(farthestRight-farthestLeft>=m){
                farthestRight--;
                break;
            }
        } else if(s[i]=='U'){
            currVertical--;
            farthestUp=min(farthestUp, currVertical);
            if(farthestDown-farthestUp>=n){
                farthestUp++;
                break;
            }
        } else {
            currVertical++;
            farthestDown=max(farthestDown, currVertical);
            if(farthestDown-farthestUp>=n){
                farthestDown--;
                break;
            }
        }
        // printf("%d %d %d %d\n", farthestUp, farthestDown, farthestLeft, farthestRight);
    }


    printf("%lld %lld\n", farthestUp*-1+1, farthestLeft*-1+1);
    
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