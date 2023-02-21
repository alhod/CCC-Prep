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


    vector<ll>best(n+1, 1e18);
    best[1]=0;
    for(ll i=0; i<n; i++){ // all odd first
        
        ll sum=0;
        for(ll size=0; i-size>=0&&i+size<n; size++){
            if(size==0){
                continue;
            }

            sum+=abs(v[i-size]-v[i+size]);
            best[1+2*size]=min(best[1+2*size], sum);
        }
    }
    
    for(ll i=0; i<n-1; i++){ // even

        ll sum=0;
        for(ll size=1; i-size+1>=0&&i+size<n; size++){

            sum+=abs(v[i-size+1]-v[i+size]);
            best[2*size]=min(best[2*size], sum);
        }
    }

    for(ll i=1; i<n+1; i++){
        cout<<best[i]<<" ";
    }
    cout<<endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();
}