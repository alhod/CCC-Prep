#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    vector<string>v(8);
    for(ll i=0; i<8; i++){
        cin>>v[i];
    }
    for(ll i=0; i<8; i++){
        bool foundB=false;;
        for(ll j=0; j<8; j++){
            if(v[i][j]=='B'||v[i][j]=='.'){
                foundB=true;
                break;
            }
        }
        if(foundB==false){
            cout<<"R"<<endl;
            return 0;
        }
    }
    for(ll i=0; i<8; i++){
        bool foundR=false;
        for(ll j=0; j<8; j++){
            if(v[j][i]=='R'||v[j][i]=='.'){
                foundR=true;
                break;
            }
        }
        if(foundR==false){
            cout<<"B"<<endl;
            return 0;
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