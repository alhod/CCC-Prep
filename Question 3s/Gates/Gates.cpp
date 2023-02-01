#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ll g;
    cin>>g;
    ll p;
    cin>>p;
    vector<ll>v(g);
    bool imp = false;
    ll count = 0;
    while(p--){
        ll plane;
        cin>>plane;
        if(imp==true){
            continue;
        }
        if(v[plane-1]==0){
            v[plane-1]=1;
            count++;
            continue;
        } else {
            while(true){
                plane--;
                if(plane==0){
                    imp = true;
                    break;
                } else if(v[plane-1]==0){
                    v[plane-1]=1;
                    count++;
                    break;
                } else if (v[plane-1]==1){
                    continue;
                }
            }
        }

    }
    cout<<count<<endl;
}