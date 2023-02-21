#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    ll sum=a+b+c+d;

    if(a==0){
        cout<<min(1ll, b+c+d)<<endl;
        return;
    }

    cout<<min(a+min(b, c)*2+min(a, d+abs(b-c))+1, sum)<<endl;
    
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