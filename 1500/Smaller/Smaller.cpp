#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll q;
    cin>>q;
    vector<ll>s(26);
    vector<ll>t(26);
    ll lens=1;
    ll lent=1;
    s[0]=1;
    t[0]=1;
    bool notas=false;
    bool notat=false;
    while(q--){
        ll d, k;
        cin>>d>>k;
        string x;
        cin>>x;
        if(d==1){
            lens+=x.length()*k;
            for(ll i=0; i<x.length(); i++){
                if(x[i]!='a'){
                    notas=true;
                }
            }
        } else {
            lent+=x.length()*k;
            for(ll i=0; i<x.length(); i++){
                if(x[i]!='a'){
                    notat=true;
                }
            }
        }

        if(notat==true){
            cout<<"YES"<<endl;
        } else if(notas==true&&notat==false){
            cout<<"NO"<<endl;
        } else {
            if(lens>=lent){
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
            }
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