#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll f;
        cin>>f;
        vector<ll>x(f);
        vector<ll>y(f);
        for(ll i=0; i<f; i++){
            cin>>x[i];
        }
        for(ll i=0; i<f; i++){
            cin>>y[i];
        }
        vector<ll>diff(f);
        for(ll i=0; i<f; i++){
            diff[i]=y[i]-x[i];
        }
        sort(diff.begin(), diff.end());
        ll p1 = f-1;
        ll p2 = 0;
        ll count = 0;
        while(p1!=p2&&p1>p2){
            if(diff[p1]+diff[p2]>=0){
                p1--;
                p2++;
                count++;
            } else if(diff[p1]+diff[p2]<0){
                p2++;
            }
        }
        cout<<count<<endl;
    }
}