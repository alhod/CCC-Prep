#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solution(){
    ll n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
    }
    for(ll i=0; i<n; i++){
        cin>>b[i];
    }

    vector<ll>count(n);
    for(ll i=0; i<n; i++){
        count[a[i]]++;
        count[b[i]]++;
    }
    
    // Check every number from 1...n is present at least once
    for(ll i=0; i<n; i++){
        if(!count[i]){
            cout<<0<<endl;
            return;
        }
    }

    for(ll i=0; i<n; i++){
        if(count[a[i]]==1&&count[b[i]]==1){
            cout<<0<<endl;
            return;
        } else if(count[a[i]]==1&&count[b[i]]!=1){
            count[b[i]]--;
            if(count[b[i]]==1){
                count[b[i]]=-1;  // implicit singleton
            }
        }
    }


    ll ans=1;
    for(ll i=0; i<n; i++){
        // Check a[i] is singleton
        if(count[a[i]]==1&&count[b[i]]!=1){
            continue;
        }

        // Check b[i] is singleton
        else if(count[a[i]]!=1&&count[b[i]]==1){
            continue;
        }

        else if()
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