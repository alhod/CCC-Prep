#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        while(n%3!=0){
            n--;
        }
        cout<<(n/3)-2<<endl;
    }
}