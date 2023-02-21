#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll g;
    cin>>g;
    ll p;
    cin>>p;
    set<ll>s;
    bool imp = false;
    ll count = 0;
    for(ll i=1; i<g+1; i++){
        s.insert(i);
    }
    while(p--){
        ll plane;
        cin>>plane;
        if(imp==true){
            continue;
        }
        while(s.find(plane)==s.end()){
            plane--;
            if(plane==0){
                imp=true;
                break;
            }
        }
        if(imp==false){
            s.erase(plane);
            count++;
        }
    }
    cout<<count<<endl;
}