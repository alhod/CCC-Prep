#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    cin>>n;
    
    vector<ll>v(n);
    for(ll i=0; i<n; i++){
        cin>>v[i];
    }

    ll even_1=-1;
    ll even_2=-1;
    ll odd_1=-1;
    ll odd_2=-1;
    ll odd_3=-1;

    for(ll i=0; i<n; i++){
        if(v[i]%2==0){
            if(even_1==-1){
                even_1=i;
            } else if(even_2==-1){
                even_2=i;
            }
        } else {
            if(odd_1==-1){
                odd_1=i;
            } else if(odd_2==-1){
                odd_2=i;
            } else if(odd_3==-1){
                odd_3=i;
            }
        }
    }

    if(even_1!=-1&&even_2!=-1&&odd_1!=-1){
        printf("YES\n%d %d %d\n", even_1+1, even_2+1, odd_1+1);
    } else if(odd_1!=-1&&odd_2!=-1&&odd_3!=-1){
        printf("YES\n%d %d %d\n", odd_1+1, odd_2+1, odd_3+1);
    } else {
        printf("NO\n");
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