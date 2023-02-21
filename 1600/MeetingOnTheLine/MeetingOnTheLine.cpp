#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAX 1e9






void solution(){
    ll n;
    cin>>n;
    vector<ll>x(n);
    vector<ll>t(n);
    for(ll i=0; i<n; i++){
        cin>>x[i];
        x[i]*=2;
    }
    for(ll i=0; i<n; i++){
        cin>>t[i];
        t[i]*=2;
    }

    ll l=0, r=MAX+1, mid, ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        ll leftEnd=0, rightEnd=MAX+1;
        for(ll i=0; i<n; i++){
            if(t[i]>mid){
                leftEnd=MAX+1;
                rightEnd=0;
                break;
            } else {
                leftEnd=max(leftEnd, x[i]-(mid-t[i]));
                rightEnd=min(rightEnd, x[i]+(mid-t[i]));
            }
        }

        if(leftEnd<=rightEnd){
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }



    ll leftEnd=0, rightEnd=MAX+1;
    for(ll i=0; i<n; i++){
        leftEnd=max(leftEnd, x[i]-(ans-t[i]));
        rightEnd=min(rightEnd, x[i]+(ans-t[i]));
    }

    cout<<leftEnd/2;
    if(leftEnd%2!=0){
        cout<<".5";
    }
    cout<<endl;
    
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