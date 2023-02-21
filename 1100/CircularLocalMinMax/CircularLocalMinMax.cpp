#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        sort(a.begin(),a.end());
        vector<ll>v(n);
        ll indLeft=0;ll indRight=n-1;
        for(ll i=0;i<n;i++){
            if(i%2==0){
                v[i]=a[indLeft];
                indLeft++;
            } else if(i%2!=0){
                v[i]=a[indRight];
                indRight--;
            }
        }

        if(n%2==0){ 
            if(v.back()<=v.front()){
                cout<<"NO"<<endl; 
                continue;
            }
        } else{
            cout<<"NO"<<endl;
            continue;
        }
        bool imp=false;
        for(ll i=1;i<n;i++){
            if(i%2!=0){//greater
                if(v[i]<=v[i-1]){
                    imp=true; 
                    break;
                }
            } else{
                if(v[i]>=v[i-1]){
                    imp=true; 
                    break;
                }
            }
        }
        if(imp==true){
            cout<<"NO"<<endl; 
            continue;
        }
        cout<<"YES"<<endl;
        for(ll i:v){
            cout<<i<<" ";
        }
        cout<<endl;

    }
}