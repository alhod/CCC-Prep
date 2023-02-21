#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string s2;
        cin>>s2;
        ll deg1=0;
        ll deg2=0;
        ll type1=0;
        ll type2=0;
        for(ll i=0; i<s.length(); i++){
            if(s[i]=='S'){
                type1=1;
                break;
            } else if (s[i]=='M'){
                type1=2;
            } else if (s[i]=='L'){
                type1=3;
            } else {
                deg1++;
            }
        }
        for(ll i=0; i<s2.length(); i++){
            if(s2[i]=='S'){
                type2=1;
                break;
            } else if (s2[i]=='M'){
                type2=2;
            } else if (s2[i]=='L'){
                type2=3;
            } else {
                deg2++;
            }
        }

        if(type1==2&&type2==2){
            cout<<"="<<endl;
        } else if(type1==1&&(type2==2||type2==3)){
            cout<<"<"<<endl;
        } else if(type1==3&&(type2==1||type2==2)){
            cout<<">"<<endl;
        } else if(type1==2&&type2==1){
            cout<<">"<<endl;
        } else if(type1==2&&type2==3){
            cout<<"<"<<endl;
        } else if(type2==2&&type1==1){
            cout<<">"<<endl;
        } else if(type2==2&&type1==3){
            cout<<"<"<<endl;
        } else if(type2==1&&type1==1){
            if(deg1>deg2){
                cout<<"<"<<endl;
            } else if (deg1<deg2){
                cout<<">"<<endl;
            } else {
                cout<<"="<<endl;
            }
        } else if(type1==3&&type2==3){
            if(deg1>deg2){
                cout<<">"<<endl;
            } else if(deg1<deg2){
                cout<<"<"<<endl;
            } else {
                cout<<"="<<endl;
            }
        }
    }
}