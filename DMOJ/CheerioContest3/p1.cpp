#include<bits/stdc++.h>
#define ll long long
using namespace std;



void place(ll n, ll m, ll r, ll c, vector<string>&v){
    if(v[r-1][c]=='.'){
        v[r-1][c]='C';
    }
    if(v[r+1][c]=='.'){
        v[r+1][c]='C';
    }
    if(v[r][c+1]=='.'){
        v[r][c+1]='C';
    }
    if(v[r][c-1]=='.'){
        v[r][c-1]='C';
    }
    
}



void solution(){
    ll n, m;
    cin>>n>>m;

    vector<string>v(n+2);
    string tmp="";
    for(ll i=0; i<m+2; i++){
        tmp.push_back('.');
    }

    v[0]=tmp;
    v[n+1]=tmp;

    for(ll i=1; i<n+1; i++){
        cin>>v[i];
        v[i]='.'+v[i]+'.';
    }


    // for(auto i:v){
    //     cout<<i<<endl;
    // }


    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<m+1; j++){
            if(v[i][j]=='W'){
                place(n+2, m+2, i, j, v);
            }
        }
    }

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<m+1; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}