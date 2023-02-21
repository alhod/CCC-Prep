#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n, m;
    if(n<m){
        n, m=m, n;
    }
    cout<<2*(m-1)+2*(n-m)-1<<endl;
    
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