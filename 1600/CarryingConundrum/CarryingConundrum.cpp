#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    string s;
    cin>>s;

    ll a=0, b=0;
    
    for(ll i=0; i<s.length(); i++){
        if(i%2==0){
            a+=(s[s.length()-1-i]-48)*(ll)pow(10, i/2);
        } else {
            b+=(s[s.length()-1-i]-48)*(ll)pow(10, i/2);
        }
    }

    // printf("a: %d, b: %d\n", a, b);

    cout<<(a+1)*(b+1)-2<<endl;
    
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