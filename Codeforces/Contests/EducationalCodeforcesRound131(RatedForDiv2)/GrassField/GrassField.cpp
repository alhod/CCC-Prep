#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll numOnes=0;
        for(ll i=0;i<4;i++){
            ll val;cin>>val;
            if(val==1){
                numOnes++;
            }
        }
        if(numOnes==1||numOnes==2||numOnes==3){
            cout<<1<<endl;
        } else if(numOnes==0){
            cout<<0<<endl;
        } else{cout<<2<<endl;}
    }
}