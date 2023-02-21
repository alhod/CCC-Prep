#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m;
    cin>>n>>m;
    ll k=1;
    ll initN=n;
    ll cnt2=0;
    ll cnt5=0;
    while(n!=0&&n%2==0){
        n/=2;
        cnt2++;
    }
    while(n!=0&&n%5==0){
        n/=5;
        cnt5++;
    }
    while(cnt2<cnt5&&k*2<=m){
        cnt2++;
        k*=2;
    }
    while(cnt2>cnt5&&k*5<=m){
        cnt5++;
        k*=5;
    }
    while(k*10<=m){
        k*=10;
    }
    if(k==1){   // meaning we didn't do anything
        cout<<initN*m<<endl;
    } else {
        k*=m/k;
        cout<<initN*k<<endl;
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