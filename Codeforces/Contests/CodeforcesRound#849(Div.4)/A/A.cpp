#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    char c;
    cin>>c;
    
    for(auto i:"codeforces"){
        if(i==c){
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    
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