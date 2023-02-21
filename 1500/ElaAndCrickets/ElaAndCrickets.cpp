#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    ll r, c, r2, c2, r3, c3;
    cin>>r>>c>>r2>>c2>>r3>>c3;

    ll gr, gc;
    cin>>gr>>gc;
    
    if(r2==r3){
        r=r2;
    }
    if(c2==c3){
        c=c2;
    }

    if((r==1||r==n)&&(c==1||c==n)){
        cout<<((gr==r||gc==c)?"YES":"NO")<<endl;
    } else {
        if((gr+gc)%2==(r+c)%2){
            cout<<((gr%2==r%2&&gc%2==c%2)?"YES":"NO")<<endl;
        } else {
            cout<<"YES"<<endl;
        }
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