#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool mag(ll m, ll startx, ll starty, ll checkx, ll checky){
    if(m==0){
        return false;
    }
    // cout<<"m: "<<m<<endl;
    // cout<<"startx: "<<startx<<endl;
    // cout<<"starty: "<<starty<<endl;
    // cout<<"checkx: "<<checkx<<endl;
    // cout<<"checky: "<<checky<<endl;
    if(startx+pow(5, m-1)<=checkx&&checkx<=startx+(4*pow(5, m-1)-1)&&starty<=checky&&checky<=starty+(pow(5, m-1)-1)){
        // cout<<"crystal located in bottom rectangle"<<endl;
        return true;
    } else if(startx+2*pow(5,m-1)<=checkx&&checkx<=startx+(3*pow(5, m-1)-1)&&starty+pow(5, m-1)<=checky&&checky<=starty+(2*pow(5, m-1)-1)){
        // cout<<"crystal located in top square"<<endl;
        return true;
    }
    if(mag(m-1, startx+pow(5, m-1), starty+pow(5, m-1), checkx, checky)==true){
        return true;
    } else if(mag(m-1, startx+2*pow(5, m-1), starty+2*pow(5, m-1), checkx, checky)==true){
        return true;
    } else if(mag(m-1, startx+3*pow(5, m-1), starty+pow(5, m-1), checkx, checky)==true){
        return true;
    }

    return false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll m;
        cin>>m;
        ll x, y;
        cin>>x>>y;
        if(mag(m, 0, 0, x, y)){
            cout<<"crystal"<<endl;
        } else {
            cout<<"empty"<<endl;
        }
    }
}