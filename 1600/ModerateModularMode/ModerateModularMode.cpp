#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    // if x > y, then n=x+y
    // if x==y, then n=x
    // if x < y
    //      if y is a multiple of x then n==x
    //      else n is (x+y)/2

    ll x, y;
    cin>>x>>y;

    if(x>y){
        // cout<<"case 1:"<<endl;
        cout<<x+y<<endl;
    } else if(x==y){
        // cout<<"case 2:"<<endl;
        cout<<x<<endl;
    } else if(x<y){
        if(y%x==0){
            // cout<<"case 3: "<<endl;
            cout<<x<<endl;
        } else {
            ll avg=(x+y)/2;
            if(avg%x==y%avg){
                cout<<avg<<endl;
            } else {
                cout<<(y-avg%x)<<endl;
            }
        }
    }
    
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