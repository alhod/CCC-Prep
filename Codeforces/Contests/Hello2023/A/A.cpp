#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    bool allL=true;
    bool allR=true;
    for(ll i=0; i<n; i++){
        if(s[i]=='L'){
            allR=false;
        } else {
            allL=false;
        }
    }

    if(allL||allR){
        cout<<-1<<endl;
        return;
    }

    vector<ll>preL(n, 0);
    ll foundL=-1;

    for(ll i=n-1; i>=0; i--){
        if(i==n-1){
            if(s[i]=='L'){
                preL[i]=1;
                if(foundL==-1){
                    foundL=i;
                }
            } else {
                preL[i]=0;
            }
        } else {
            preL[i]+=preL[i+1];
            if(s[i]=='L'){
                preL[i]++;
                if(foundL==-1){
                    foundL=i;
                }
            }
        }
    }

    for(ll i=0; i<n; i++){
        if(s[i]=='R'){
            if(preL[i]>0){
                cout<<0<<endl;
                return;
            }
        }
    }

    cout<<foundL+1<<endl;

    return;

    
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