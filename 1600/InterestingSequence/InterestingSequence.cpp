#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n, x, tmp;
    cin>>n>>x;
    tmp=n;
    while(true){
        if((tmp&n)==x||(tmp&n)<=0){
            break;
        }
        tmp+=(tmp&(-tmp));
    }
    cout<<((tmp&n)==x?tmp:-1)<<endl;
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