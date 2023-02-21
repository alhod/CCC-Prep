#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }

    ll p1=0;
    ll p2=n-1;
    ll cost=0;
    while(true){
        if(p1==p2){
            cost+=a[p2];
            break;
        }

        if(b[p1]<=b[p2]){
            cost+=a[p1];
            a[p1+1]+=b[p1];
            p1++;
        } else {
            cost+=a[p2];
            a[p2-1]+=b[p2];
            p2--;
        }
    }
    cout<<cost<<endl;
    
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