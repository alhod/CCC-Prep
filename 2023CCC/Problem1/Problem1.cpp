#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    vector<ll>row1(n);
    vector<ll>row2(n);
    for(ll i=0; i<n; i++){
        cin>>row1[i];
    }
    for(ll i=0; i<n; i++){
        cin>>row2[i];
    }

    ll ans=0;

    for(ll i=0; i<n; i++){
        if(row1[i]==0){
            continue;
        }

        ll to_add=3;
        if(i==0){
            if(row2[0]==1){
                to_add--;
            }
            if(n>1&&row1[1]==1){
                to_add--;
            }
        } else if(i%2==0){
            if(row2[i]==1){
                to_add--;
            }
            if(row1[i-1]==1){
                to_add--;
            }
            if(i<n-1&&row1[i+1]==1){
                to_add--;
            }
        } else {
            if(row1[i-1]==1){
                to_add--;
            }
            if(i<n-1&&row1[i+1]==1){
                to_add--;
            }
        }

        ans+=to_add;
    }
    

    for(ll i=0; i<n; i++){
        if(row2[i]==0){
            continue;
        }

        ll to_add=3;
        if(i==0){
            if(row1[0]==1){
                to_add--;
            }
            if(n>1&&row2[1]==1){
                to_add--;
            }
        } else if(i%2==0){
            if(row1[i]==1){
                to_add--;
            }
            if(row2[i-1]==1){
                to_add--;
            }
            if(i<n-1&&row2[i+1]==1){
                to_add--;
            }
        } else {
            if(row2[i-1]==1){
                to_add--;
            }
            if(i<n-1&&row2[i+1]==1){
                to_add--;
            }
        }

        ans+=to_add;
    }

    cout<<ans<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}