#include<bits/stdc++.h>
#define ll long long
using namespace std;


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
    // for(ll i=0; i<n; i++){
        // cout<<x[i]<<" "<<t[i]<<endl;
    // }
    ll l=0, r=1e8+1, mid, ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        // cout<<"mid: "<<mid<<endl;
        ll leftEnd=0, rightEnd=1e8+1;
        for(ll i=0; i<n; i++){
            if(t[i]>mid){
                leftEnd=1e8+1;
                rightEnd=0;
                break;
            } else {
                // cout<<"op 2"<<endl;
                leftEnd=max(leftEnd, x[i]-(mid-t[i]));
                rightEnd=min(rightEnd, x[i]+(mid-t[i]));
            }
        }
        // cout<<"leftEnd: "<<leftEnd<<endl;
        // cout<<"rightEnd: "<<rightEnd<<endl;

        if(leftEnd<=rightEnd){
            ans=mid;
            r=mid-1;
        } else {
            l=mid+1;
        }
    }

    // cout<<"ans: "<<ans<<endl;

    double leftEnd=0, rightEnd=1e8+1;
    for(ll i=0; i<n; i++){
        leftEnd=max(leftEnd, (double)(x[i]-(ans-t[i])));
        rightEnd=min(rightEnd, (double)(x[i]+(ans-t[i])));
    }

    cout<<leftEnd/2<<endl;
    
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