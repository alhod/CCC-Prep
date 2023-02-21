#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;

    ll not_match1=0;
    ll not_match2=0;
    ll not_match_both=0;

    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    for(ll i=0; i<n; i++){
        if(v[i]!=i+1&&v[i]!=n-i){
            not_match_both++;
        } else if(v[i]!=i+1){
            not_match1++;
        } else if(v[i]!=n-i){
            not_match2++;
        }
    }

    if(not_match1+not_match_both<=not_match2){
        cout<<"First"<<endl;
    } else if(not_match2+not_match_both<not_match1){
        cout<<"Second"<<endl;
    } else {
        cout<<"Tie"<<endl;
    }


    // if(match1==(n+1)/2&&match2==(n+1)/2){
    //     cout<<"Tie"<<endl;
    // } else if(match1==(n+1)/2){
    //     cout<<"First"<<endl;
    // } else if(match2==(n/2+1)){
    //     cout<<"Second"<<endl;
    // } else {
    //     cout<<"Tie"<<endl;
    // }

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