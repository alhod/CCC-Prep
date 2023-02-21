#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll p1=0, p2=n-1;
    while(p1<p2){
        if(s[p1]=='1'&&s[p2]=='0'){
            p1++;
            p2--;
            continue;
        } else if(s[p1]=='0'&&s[p2]=='1'){
            p1++;
            p2--;
            continue;
        } else {
            break;
        }
    }

    cout<<p2-p1+1<<endl;
    
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