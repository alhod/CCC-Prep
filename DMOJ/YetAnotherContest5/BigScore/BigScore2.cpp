#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solution(){
    ll n;
    cin>>n;
    vector<ll>v1(n);
    vector<ll>v2(n);
    vector<ll>v3(n);
    for(ll i=0; i<n; i++){
        cin>>v1[i];
    }
    for(ll i=0; i<n; i++){
        cin>>v2[i];
    }
    for(ll i=0; i<n; i++){
        cin>>v3[i];
    }
    ll josh=-1;
    ll nil=-1;
    ll mike=-1;
    
    ll sum1=0;
    ll sum2=0;
    ll sum3=0;

    for(ll i=0; i<n; i++){
        sum1+=v1[i];
        sum2+=v2[i];
        sum3+=v3[i];
    }

    if(sum1<sum2&&sum1<sum3){
        mike=1;
    } else if(sum2<sum1&&sum2<sum3){
        mike=2;
    } else if(sum3<sum1&&sum3<sum2){
        mike=3;
    }

    if(mike!=-1){
        if(mike==1){
            for(ll i=0; i<n; i++){
                if(v2[i]>v3[i]){
                    nil=2;
                    josh=3;
                } else if(v2[i]<v3[i]){
                    nil=3;
                    josh=2;
                }
            }
        }
        if(mike==2){
            for(ll i=0; i<n; i++){
                if(v1[i]>v3[i]){
                    nil=1;
                    josh=3;
                } else if(v1[i]<v3[i]){
                    nil=3;
                    josh=1;
                }
            }
        }
        if(mike==3){
            for(ll i=0; i<n; i++){
                if(v2[i]>v1[i]){
                    nil=2;
                    josh=1;
                } else if(v2[i]<v1[i]){
                    nil=1;
                    josh=2;
                }
            }
        }
    } else {
        ll mikeNot=-1;
        ll nilNot=-1;
        ll joshNot=-1;
        ll p1=0;
        ll p2=n-1;
        while(true){
            if(p1==n){
                // fucked case
            } else {
                if(v1[p1]>v2[p1]&&v1[p1]>v3[p1]){
                    josh=1;
                    break;
                } else if(v2[p1]>v1[p1]&&v2[p1]>v3[p1]){
                    josh=2;
                    break;
                } else if(v3[p1]>v1[p1]&&v3[p1]>v2[p1]){
                    josh=3;
                    break;
                } else if(v1[p1]==v2[p1]&&v1[p1]>v3[p1]){
                    joshNot=3;
                } else if(v1[p1]==v3[p1]&&v1[p1]>v2[p1]){
                    joshNot=2;
                } else if(v3[p1]==v2[p1]&&v3[p1]>v1[p1]){
                    joshNot=1;
                } 
            }
        }
    }

    vector<string>ans(3);
    ans[nil-1]="Nils";
    ans[josh-1]="Josh";
    ans[mike-1]="Mike";
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    


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